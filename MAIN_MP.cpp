#include "MAIN_MP.h"

Main_MP::Main_MP(QObject* parent, QString Heading, vector<Main_MP*>* Choices, Main_MP* Main_M) : QObject(parent) {
    this->Heading = Heading;
    this->Choices = Choices;
    this->Main_M = Main_M;
}

Main_MP::~Main_MP() {
    for(auto o : *this->Choices)
        delete o;
    delete this->Choices;
    delete Main_M;
}

QString Main_MP::GetHeading() { return this->Heading; }
Main_MP* Main_MP::GetPreviousMain_MP() { return this->Main_M; }
