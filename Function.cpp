/*
 * File name: Function.cpp
 * Description: The source code for the 'Function' class implementation.
 *
*/
#include "Function.h"
#include "Contents.h"
#include "MainWindow.h"
#include "MAIN_MP.h"

/*
 * Constructor: Constructor for the 'Function' class initializing all the attributes
 * Parameters:
 *    a.parent
 *    b.MainWindow* ui
 *    c.freq
 *    d.duration
 *    e.powerLevel
*/
Function::Function(QObject* parent, Ui::MainWindow* ui, short freq, int duration, short powerLevel) : QObject(parent), originalDuration(duration) {

    this->ui = ui;
    this->freq = freq;
    this->powerLevel = powerLevel;
    this->duration = duration;
    this->sessionTime = nullptr;
    isActive = false;

}

/*
 * Destructor for the 'Function' class: Deletes the current session time.
 * Parameters: N/A
*/
Function::~Function() {
    //deletes the current session time
    delete this->sessionTime;
}

/*
 * Start():The start function implemented is used to start the treatment program upon being called.
 * Parameters: None
*/
void Function::Start() {

    isActive = true;
    this->sessionTime = new QTimer(this);
    connect(this->sessionTime, SIGNAL(timeout()), this, SLOT(Update()));
    this->sessionTime->start(1000);
    this->duration = this->originalDuration;

}

/*
 * Stop():The start function implemented is used to stop the treatment program upon being called.
 * Parameters: None
*/
void Function::Stop() {

    ui->Main_MP->clear();
    isActive = false;
    this->sessionTime->stop();
    disconnect(this->sessionTime, SIGNAL(timeout()), this, SLOT(Update()));
    delete this->sessionTime;

}

/*
 * UpdateUI():This function updates the UI screen for the current process/treatment that's in progress and displays the details accordingly.
 * Parameters: None
*/
void Function::UpdateUI() {
    ui->Main_MP->clear();

    // If the timer for the session gets over,it stops the treatment.
    if (this->duration == 0) Stop();
    // If the timer for the session is running currently, then it displays the details for the treatment: Program, Frequency and the remaining time
    else if (duration > 0) {
        ui->Main_MP->addItem("Hz: " + QString::number(this->freq));
        ui->Main_MP->addItem("Time Remaining: " + QString::number(this->duration) + "s");
    }
    else ui->Main_MP->addItem("Time Elapsed: " + QString::number(0 - this->duration) + "s");

    if (this->duration!=0)
    ui->Main_MP->addItem("Power Level: " + QString::number(this->powerLevel));
}

/*
 * Update():The update function gets implemented once the program/treatment starts and updates the battery level of the device and also controls the time duration(decreasing).
 * Parameters: None
*/
void Function::Update() {

    this->duration -= 1;
    if (this->powerLevel != 0) ui->batteryBar->setValue(ui->batteryBar->value() - (1-(1/this->powerLevel)));
    this->UpdateUI();
    if (ui->batteryBar->value() == 0) ui->powerButton->click();

}

/*
 * SetPowerLevel():This function is utilized to set the power level for the treatment as well as updating the UI.
 * Parameters:
 *    a.powerLevel
 *
*/
void Function::SetPowerLevel(short powerLevel) {

    if (powerLevel < 0 || powerLevel > 100) return;
    this->powerLevel = powerLevel;
    this->UpdateUI();

}

/*
 * GetTimer(): This getter is used to retrieve the timer for the session
 * Parameters: None
*/
QTimer* Function::GetTimer() {
    return this->sessionTime;
}

/*
 * Getfreq(): This getter is used to retrieve the frequency for the session
 * Parameters: None
*/
short Function::Getfreq() {
    return this->freq;
}

/*
 * GetPowerLevel(): This getter is used to retrieve the power level for the session
 * Parameters: None
*/
short Function::GetPowerLevel() {
    return this->powerLevel;
}
