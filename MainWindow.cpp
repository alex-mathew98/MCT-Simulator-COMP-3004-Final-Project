/*
 * File name: MainWindow.cpp
 * Description: The source code for the 'MainWindow' class implementation.
 *
*/
#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Contents.h"
#include <iostream>
#include "Function.h"
using namespace std;

/*
 * Constructor: Constructor for the 'MainWindow' class initializing all the attributes
 * Parameters:
 *    a.parent
 *
*/
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setWindowTitle("MCT-Bio-FeedBack");
    this->setFixedSize(400, 730);

    //Vector implementation for the main menu of the device.
    vector<Main_MP*>* mainMain_MPChoices = new vector<Main_MP*>;
    mainMain_MPChoices->push_back(FunctionsMain_MP);
    mainMain_MPChoices->push_back(freqMain_MP);
    mainMain_MPChoices->push_back(medMain_MP);
    mainMain_MPChoices->push_back(scMain_MP);
    mainMain_MPChoices->push_back(childrenMain_MP);
    mainMain_MPChoices->push_back(settingsMain_MP);
    mainMain_MPChoices->push_back(hisMain_MP);
    mainMain_MP->Choices = mainMain_MPChoices;

    //Vector implementation for the list of treatments under the programs/functions section.
    vector<Main_MP*>* FunctionChoices = new vector<Main_MP*>;
    FunctionChoices->push_back(new Contents(this, "Coughing", new Function(this, ui, 7720, 600 ,10), FunctionsMain_MP));
    FunctionChoices->push_back(new Contents(this, "Pain", new Function(this, ui, 77, 900, 15), FunctionsMain_MP));
    FunctionChoices->push_back(new Contents(this, "Allergic Reaction", new Function(this, ui, 38, 600,20), FunctionsMain_MP));
    FunctionChoices->push_back(new Contents(this, "Bloating", new Function(this, ui, 44, 690,35), FunctionsMain_MP));
    FunctionsMain_MP->Choices = FunctionChoices;

    //Vector implementation for the list of frequencies for the treatments under the frequencies section.
    vector<Main_MP*>* Selection_OF_freq = new vector<Main_MP*>;
    Selection_OF_freq->push_back(new Contents(this, "1.0 - 9.9 Hz", new Function(this, ui,9,10,1), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "10 Hz", new Function(this, ui,19,15, 10), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "20 Hz", new Function(this, ui,58,20 ,20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "60 Hz", new Function(this, ui,75,25 ,20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "77 Hz", new Function(this, ui,124,30, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "125 Hz", new Function(this, ui,139,35, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "140 Hz", new Function(this, ui,198,40, 20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "200 Hz", new Function(this, ui,200,45,20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "7710 Hz", new Function(this, ui,7715,50,20), freqMain_MP));
    Selection_OF_freq->push_back(new Contents(this, "7720 Hz", new Function(this, ui,7720,55, 20), freqMain_MP));
    freqMain_MP->Choices = Selection_OF_freq;

    //Vector implementation for the list of children's treatment options under the children section.
    vector<Main_MP*>* childrenChoices = new vector<Main_MP*>;
    childrenChoices->push_back(new Contents(this, "UP TO 1 YEAR", new Function(this, ui, 77, 900), childrenMain_MP));
    childrenChoices->push_back(new Contents(this, "1 - 3 YEARS", new Function(this, ui, 7710, 600), childrenMain_MP));
    childrenChoices->push_back(new Contents(this, "4 - 7 YEARS", new Function(this, ui, 7710, 600), childrenMain_MP));
    childrenChoices->push_back(new Contents(this, "7 - 12 YEARS", new Function(this, ui, 7710, 600), childrenMain_MP));
    childrenChoices->push_back(new Contents(this, "DISABLE", new Function(this, ui, 38, 600), childrenMain_MP));
    childrenMain_MP->Choices = childrenChoices;

    //Vector implementation for the list of settings available under the settings section.
    vector<Main_MP*>* settingsChoices = new vector<Main_MP*>;
    settingsChoices->push_back(new Contents(this, "Alarm Clock", new Function(this, ui,7710 ,1, 1), settingsMain_MP));
    settingsChoices->push_back(new Contents(this, "Language", new Function(this, ui,7710 ,1, 1), settingsMain_MP));
    settingsChoices->push_back(new Contents(this, "Screen Layout", new Function(this, ui,7710 ,1,1), settingsMain_MP));
    settingsChoices->push_back(new Contents(this, "Sound", new Function(this, ui,7710 ,1,1), settingsMain_MP));
    settingsChoices->push_back(new Contents(this, "Brightness", new Function(this, ui,7710 ,1,1), settingsMain_MP));
    settingsMain_MP->Choices = settingsChoices;


    //Vector implementation for the med section.
    vector<Main_MP*>* medChoices = new vector<Main_MP*>;
    medChoices->push_back(new Contents(this, "", new Function(this, ui,7710 ,1,1), medMain_MP));
    medMain_MP->Choices = medChoices;

   //Vector implementation for the selected screening choices
    vector<Main_MP*>* scChoices = new vector<Main_MP*>;
    scChoices->push_back(new Contents(this, "", new Function(this, ui,7710 ,1,1), scMain_MP));
    scMain_MP->Choices = scChoices;



    //Vector implementation for the recorded treatments
    vector<Main_MP*>* hisChoices = new vector<Main_MP*>;
    hisChoices->push_back(viewhis);
    hisChoices->push_back(clearhis);
    hisMain_MP->Choices = hisChoices;


    vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
    viewhis->Choices = vChoices;
    vector<Main_MP*>* cChoices = new vector<Main_MP*>;

    cChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,0,0), clearhis));
    clearhis->Choices = cChoices;

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

/*
 * Destructor for the 'MainWindow' class
 * Parameters: N/A
*/
MainWindow::~MainWindow() {
    delete ui;
}

//function for changing the screen pointer
/*
 * ChangeMain_MP():This function is for updating/changing the screen pointer.
 * Parameters:
 *    a.Main_MP
 *
*/
void MainWindow::ChangeMain_MP(Main_MP* Main_MP) {

    ui->Main_MP->clear();
    ui->Main_MPTitle->setText(Main_MP->GetHeading());
    this->currentMain_MP = Main_MP;

    if (Main_MP->Choices != nullptr) {
        for (size_t i = 0; i < Main_MP->Choices->size(); i++)
            ui->Main_MP->addItem(Main_MP->Choices->at(i)->GetHeading());
            ui->Main_MP->setCurrentRow(0);

    }
    else if(Main_MP->GetHeading() == "Med" || Main_MP->GetHeading() == "" ||Main_MP->GetHeading() == "Screening" ||Main_MP->GetHeading() == "Alarm Clock" ||Main_MP->GetHeading() == "Language" || Main_MP->GetHeading() == "Screen Layout"|| Main_MP->GetHeading() == "Brightness"|| Main_MP->GetHeading() == "Sound" )
    {
        ui->Main_MP->previousInFocusChain();
    }
    else
    {
        ui->Main_MP->addItem("Click on 'TICK' Button to Continue ");
    }


    // Validation for the treatment programs and frequencies to be added to the recording history.
    // a.Treatments/Programs
    if(Main_MP->GetHeading()=="Coughing") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,0,0), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Programmed, Coughing" , new Function(this, ui,7710 ,1,1), viewhis));

    }

    if(Main_MP->GetHeading()=="Allergic Reaction") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Programmed, Allergic Reaction" , new Function(this, ui,7710 ,1,1), viewhis));

    }

    if(Main_MP->GetHeading()=="Bloating") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Programmed, Bloating" , new Function(this, ui,7710 ,1,1), viewhis));
    }

    if(Main_MP->GetHeading()=="Pain") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Programmed, Pain" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    // b.Frequencies
    if(Main_MP->GetHeading()=="1.0 - 9.9 Hz") {

        this->
        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 1.0 - 9.9 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="10 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 10 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="20 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 20 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="60 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 60 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }

    if(Main_MP->GetHeading()=="77 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 77 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="125 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 125 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="140 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 140 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="200 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 200 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="7710 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 7710 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="7720 Hz") {

        vChoices->push_back(new Contents(this, "" , new Function(this, ui,7710 ,1,1), viewhis));
        vChoices->push_back(new Contents(this, "Treatment:Frequency, 7720 Hz" , new Function(this, ui,7710 ,1,1), viewhis));

    }
    if(Main_MP->GetHeading()=="Clear")
    {
        vChoices->clear();

    }

}


/*
 * Back_Button():This is the function implementation for the back button in regards to the menus on the UI.With this implemented,the menu gets changed to the previous one.
 * Parameters: None
*/
void MainWindow::Back_Button() {

    if (this->currentMain_MP->GetPreviousMain_MP() == nullptr) return;

    if (dynamic_cast<Contents *>(this->currentMain_MP)) dynamic_cast<Contents *>(this->currentMain_MP)->Back_Button();
    this->ChangeMain_MP(this->currentMain_MP->GetPreviousMain_MP());

}

/*
 * Ok_Button():This is the function implementation for the ok button in regards to the menu selection on the UI.With this called,it allows the user to select the current option.
 * Parameters: None
*/
void MainWindow::Ok_Button() {
    if (dynamic_cast<Contents *>(this->currentMain_MP) != nullptr) dynamic_cast<Contents *>(this->currentMain_MP)->Ok_Button();
    else ChangeMain_MP(this->currentMain_MP->Choices->at((size_t)ui->Main_MP->currentRow()));
}

/*
 * Left_Button():This is the function implementation for the left button on the UI.
 * Parameters: None
*/
void MainWindow::Left_Button() {
    if (dynamic_cast<Contents *>(this->currentMain_MP)) dynamic_cast<Contents *>(this->currentMain_MP)->Left_Button();
}

/*
 * Right_Button():This is the function implementation for the right button on the UI.
 * Parameters: None
*/
void MainWindow::Right_Button() {
    if (dynamic_cast<Contents *>(this->currentMain_MP)) dynamic_cast<Contents *>(this->currentMain_MP)->Right_Button();
}

/*
 * Up_Button():This is the function implementation for the up button on the UI.It allows the user to scroll upwards on the menu of the interface.
 * Parameters: None
*/
void MainWindow::Up_Button() {
    if (ui->Main_MP->currentRow()-1 < 0) return;
    ui->Main_MP->setCurrentRow(ui->Main_MP->currentRow()-1);
}

/*
 * Down_Button():This is the function implementation for the down button on the UI.It allows the user to scroll downwards on the menu of the interface.
 * Parameters: None
*/
void MainWindow::Down_Button() {
    if (currentMain_MP->Choices == nullptr || (ui->Main_MP->currentRow() + 1) >= (int)currentMain_MP->Choices->size()) return;
    ui->Main_MP->setCurrentRow(ui->Main_MP->currentRow()+1);
}
