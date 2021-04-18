/*
 * File name: MAIN_MP.cpp
 * Description: The source code for the 'Main_MP' class implementation.
 *
*/
#include "MAIN_MP.h"

/*
 * Constructor: Constructor for the 'Main_MP' class initializing all the attributes.
 * Parameters:
 *    a.parent
 *    b.Heading
 *    c.Choices
 *    d.Main_M
*/
Main_MP::Main_MP(QObject* parent, QString Heading, vector<Main_MP*>* Choices, Main_MP* Main_M) : QObject(parent) {

    this->Heading = Heading;
    this->Choices = Choices;
    this->Main_M = Main_M;

}

/*
 * Destructor for the 'Main_MP' class
 * Parameters: N/A
*/
Main_MP::~Main_MP() {

    for(auto o : *this->Choices)
        delete o;
    delete this->Choices;
    delete Main_M;

}

/*
 * GetHeading(): This getter is used to retrieve the header/title for each section.
 * Parameters: None
*/
QString Main_MP::GetHeading() {
    return this->Heading;
}

/*
 * GetPreviousMain_MP(): This getter is used to retrieve the previous menu.
 * Parameters: None
*/
Main_MP* Main_MP::GetPreviousMain_MP() {
    return this->Main_M;
}
