/*
 * File name: Contents.cpp
 * Description: The source code for the 'Contents' class implementation.
 *
*/
#include "Contents.h"

/*
 * Constructor: Constructor for the 'Contents' class initializing all the attributes
 * Parameters:
 *    a.parent
 *    b.title
 *    c.Function/prog
 *    d.prevMain_MP
 *    e.options
*/
Contents::Contents(QObject* parent, QString title, Function* prog, Main_MP* prevMain_MP, vector<Main_MP*>* options) :
    Main_MP(parent, title, options, prevMain_MP), function(prog) {}

/*
 * Destructor for the 'Contents' class
 * Parameters: N/A
*/
Contents::~Contents() { delete function; }

/*
 * Back_Button():This is the function implementation for the back/return button.With this called,the ongoing treatment stops.
 * Parameters: None
*/
void Contents::Back_Button() {
    if (!this->function->isActive) return;
    this->function->Stop();
}

/*
 * Ok_Button():This is the function implementation for the ok button.With this called,the treatment is selected and treatment gets initialized.
 * Parameters: None
*/
void Contents::Ok_Button() { this->function->Start(); }

/*
 * Left_Button():This is the function implementation for the left button.This function is responsible for decreasing the power level during the treatment.
 * Parameters: None
*/
void Contents::Left_Button() {
    if (!this->function->isActive) return;
    this->function->SetPowerLevel(this->function->GetPowerLevel() - 1);
}

/*
 * Right_Button():This is the function implementation for the right button.This function is responsible for increasing the power level during the treatment.
 * Parameters: None
*/
void Contents::Right_Button() {
    if (!this->function->isActive) return;
    this->function->SetPowerLevel(this->function->GetPowerLevel() + 1);
}
