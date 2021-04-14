#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Contents.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("MCT-Bio-FeedBack");
    // Main window Size
    this->setFixedSize(400, 730);

    Main_MP* mainMain_MP = new Main_MP(this, "MAIN MENU");
    Main_MP* FunctionsMain_MP = new Main_MP(this, "Program", nullptr, mainMain_MP);

    Main_MP* childrenMain_MP = new Main_MP(this, "Children", nullptr, mainMain_MP);
    Main_MP* settingsMain_MP = new Main_MP(this, "Setting", nullptr, mainMain_MP);
    Main_MP* freqMain_MP = new Main_MP(this, "Frequency", nullptr, mainMain_MP);
    vector<Main_MP*>* mainMain_MPChoices = new vector<Main_MP*>;

    mainMain_MPChoices->push_back(childrenMain_MP);
    mainMain_MPChoices->push_back(freqMain_MP);
    mainMain_MPChoices->push_back(FunctionsMain_MP);
    mainMain_MPChoices->push_back(settingsMain_MP);


    mainMain_MP->Choices = mainMain_MPChoices;
    vector<Main_MP*>* FunctionChoices = new vector<Main_MP*>;
    FunctionChoices->push_back(new Contents(this, "Coughing", new Function(this, ui, 7720, 600), FunctionsMain_MP));
    FunctionChoices->push_back(new Contents(this, "Pain", new Function(this, ui, 77, 900), FunctionsMain_MP));
    FunctionChoices->push_back(new Contents(this, "Allergic Reactioin", new Function(this, ui, 38, 600), FunctionsMain_MP));
    FunctionChoices->push_back(new Contents(this, "Bloating", new Function(this, ui, 44, 690), FunctionsMain_MP));
    FunctionsMain_MP->Choices = FunctionChoices;

    vector<Main_MP*>* Selection_OF_freq = new vector<Main_MP*>;
    Selection_OF_freq->push_back(new Contents(this, "1.0-9.9 Hz", new Function(this, ui, 1), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "10 Hz", new Function(this, ui, 10), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "20 Hz", new Function(this, ui, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "60 Hz", new Function(this, ui, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "77 Hz", new Function(this, ui, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "125 Hz", new Function(this, ui, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "140 Hz", new Function(this, ui, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "200 Hz", new Function(this, ui, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "7710", new Function(this, ui, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "7720", new Function(this, ui, 20), freqMain_MP));
    freqMain_MP->Choices = Selection_OF_freq;

    vector<Main_MP*>* childrenChoices = new vector<Main_MP*>;

    childrenChoices->push_back(new Contents(this, "DISABLE", new Function(this, ui, 38, 600), childrenMain_MP));
    childrenChoices->push_back(new Contents(this, "UP TO 1 YEAR", new Function(this, ui, 77, 900), childrenMain_MP));
    childrenChoices->push_back(new Contents(this, "1 - 3 YEARS", new Function(this, ui, 7710, 600), childrenMain_MP));
    childrenChoices->push_back(new Contents(this, "4 - 7 YEARS", new Function(this, ui, 7710, 600), childrenMain_MP));
    childrenChoices->push_back(new Contents(this, "7 -12 YEARS", new Function(this, ui, 7710, 600), childrenMain_MP));
    childrenMain_MP->Choices = childrenChoices;

    vector<Main_MP*>* settingsChoices = new vector<Main_MP*>;

    settingsChoices->push_back(new Contents(this, "Alarm Clock", new Function(this, ui, 7710, 600), settingsMain_MP));
    settingsChoices->push_back(new Contents(this, "Language", new Function(this, ui, 7710, 600), settingsMain_MP));
    settingsChoices->push_back(new Contents(this, "Screen Layout", new Function(this, ui, 7710, 600), settingsMain_MP));
    settingsChoices->push_back(new Contents(this, "Sound", new Function(this, ui, 38, 600), settingsMain_MP));
    settingsChoices->push_back(new Contents(this, "Brightness", new Function(this, ui, 77, 900), settingsMain_MP));
    settingsMain_MP->Choices = settingsChoices;

    this->ChangeMain_MP(mainMain_MP);

    //Action Handlers
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(Back_Button()));
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(Ok_Button()));
    connect(ui->leftButton, SIGNAL(clicked()), this, SLOT(Left_Button()));
    connect(ui->rightButton, SIGNAL(clicked()), this, SLOT(Right_Button()));
    connect(ui->upButton, SIGNAL(clicked()), this, SLOT(Up_Button()));
    connect(ui->downButton, SIGNAL(clicked()), this, SLOT(Down_Button()));
    connect(ui->powerButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ChangeMain_MP(Main_MP* Main_MP) {
    ui->Main_MP->clear();
    ui->Main_MPTitle->setText(Main_MP->GetHeading());
    this->currentMain_MP = Main_MP;
    if (Main_MP->Choices != nullptr) {
        for (size_t i = 0; i < Main_MP->Choices->size(); i++)
            ui->Main_MP->addItem(Main_MP->Choices->at(i)->GetHeading());
        ui->Main_MP->setCurrentRow(0);
    } else {
        ui->Main_MP->addItem("Click on 'OK' Button to Continue ");
    }
}

// Button Action Handlers
void MainWindow::Back_Button() {
    if (this->currentMain_MP->GetPreviousMain_MP() == nullptr) return;

    if (dynamic_cast<Contents *>(this->currentMain_MP)) dynamic_cast<Contents *>(this->currentMain_MP)->Back_Button();
    this->ChangeMain_MP(this->currentMain_MP->GetPreviousMain_MP());
}

void MainWindow::Ok_Button() {
    if (dynamic_cast<Contents *>(this->currentMain_MP) != nullptr) dynamic_cast<Contents *>(this->currentMain_MP)->Ok_Button();
    else ChangeMain_MP(this->currentMain_MP->Choices->at((size_t)ui->Main_MP->currentRow()));
}

void MainWindow::Left_Button() { if (dynamic_cast<Contents *>(this->currentMain_MP)) dynamic_cast<Contents *>(this->currentMain_MP)->Left_Button(); }
void MainWindow::Right_Button() { if (dynamic_cast<Contents *>(this->currentMain_MP)) dynamic_cast<Contents *>(this->currentMain_MP)->Right_Button(); }

void MainWindow::Up_Button() {
    if (ui->Main_MP->currentRow()-1 < 0) return;
    ui->Main_MP->setCurrentRow(ui->Main_MP->currentRow()-1);
}

void MainWindow::Down_Button() {
    if (currentMain_MP->Choices == nullptr || (ui->Main_MP->currentRow() + 1) >= (int)currentMain_MP->Choices->size()) return;
    ui->Main_MP->setCurrentRow(ui->Main_MP->currentRow()+1);
}
