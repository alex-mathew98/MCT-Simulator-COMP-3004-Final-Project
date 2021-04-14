#include "Contents.h"

Contents::Contents(QObject* parent, QString title, Function* prog, Main_MP* prevMain_MP, vector<Main_MP*>* options) :
    Main_MP(parent, title, options, prevMain_MP), function(prog) {}

Contents::~Contents() { delete function; }
//Updating the screen according to the buttons

void Contents::Back_Button() {
    if (!this->function->isActive) return;
    this->function->Stop();
}
void Contents::Ok_Button() { this->function->Start(); }
void Contents::Left_Button() {
    if (!this->function->isActive) return;
    this->function->SetPowerLevel(this->function->GetPowerLevel() - 1);
}
void Contents::Right_Button() {
    if (!this->function->isActive) return;
    this->function->SetPowerLevel(this->function->GetPowerLevel() + 1);
}
