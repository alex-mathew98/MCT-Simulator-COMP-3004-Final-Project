#include "Function.h"

Function::Function(QObject* parent, Ui::MainWindow* ui, short freq, int duration, short powerLevel) : QObject(parent), originalDuration(duration) {
    this->ui = ui;
    this->freq = freq;
    this->powerLevel = powerLevel;
    this->duration = duration;
    this->sessionTime = nullptr;
    isActive = false;
}

Function::~Function() {
    delete this->sessionTime;
}

// Start the Function
void Function::Start() {
    isActive = true;
    this->sessionTime = new QTimer(this);
    connect(this->sessionTime, SIGNAL(timeout()), this, SLOT(Update()));
    this->sessionTime->start(1000);
    this->duration = this->originalDuration;
}

void Function::Stop() {
    isActive = false;
    this->sessionTime->stop();
    disconnect(this->sessionTime, SIGNAL(timeout()), this, SLOT(Update()));
    delete this->sessionTime;
    this->powerLevel = 1;
}
void Function::UpdateUI() {
    ui->Main_MP->clear();
    if (this->duration == 0) Stop();
    else if (duration > 0) {
        ui->Main_MP->addItem("Hz: " + QString::number(this->freq));
        ui->Main_MP->addItem("Time Remaining: " + QString::number(this->duration) + "s");
    } else ui->Main_MP->addItem("Time Elapsed: " + QString::number(0 - this->duration) + "s");
    ui->Main_MP->addItem("Power Level: " + QString::number(this->powerLevel));
}

// Update method, gets called every second after the Function starts
void Function::Update() {
    this->duration -= 1;
    if (this->powerLevel != 0) ui->batteryBar->setValue(ui->batteryBar->value() - (1-(1/this->powerLevel)));
    this->UpdateUI();
    if (ui->batteryBar->value() == 0) ui->powerButton->click();
}

void Function::SetPowerLevel(short powerLevel) {
    if (powerLevel < 0 || powerLevel > 100) return;
    this->powerLevel = powerLevel;
    this->UpdateUI();
}

QTimer* Function::GetTimer() { return this->sessionTime; }
short Function::Getfreq() { return this->freq; }
short Function::GetPowerLevel() { return this->powerLevel; }
