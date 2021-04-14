#ifndef MAIN_MP_H
#define MAIN_MP_H

#include <QObject>
#include "ui_mainwindow.h"
#include <vector>

using namespace std;

class Main_MP : public QObject {
    Q_OBJECT
public:
    explicit Main_MP(QObject* parent = nullptr, QString Heading = "{Heading}", vector<Main_MP*>* Choices = nullptr, Main_MP* Main_MP = nullptr);
    ~Main_MP();
    QString GetHeading();
    vector<Main_MP*>* Choices;
    Main_MP* GetPreviousMain_MP();
private:
    QString Heading;
    Main_MP* Main_M;

};

#endif
