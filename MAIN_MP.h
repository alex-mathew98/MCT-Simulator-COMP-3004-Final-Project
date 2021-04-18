/*
 * File name: MAIN_MP.h
 * Description: The header file for the 'Main_MP' class
 *
*/
#ifndef MAIN_MP_H
#define MAIN_MP_H

#include <QObject>
#include "ui_mainwindow.h"
#include <vector>

using namespace std;

/*
 * Declaration of the 'Main_MP' class
*/
class Main_MP : public QObject {

    Q_OBJECT

    public:
        explicit Main_MP(QObject* parent = nullptr, QString Heading = "{Heading}", vector<Main_MP*>* Choices = nullptr, Main_MP* Main_MP = nullptr);
        ~Main_MP();
        QString GetHeading();
        Main_MP* GetPreviousMain_MP();
        // Vector for choices
        vector<Main_MP*>* Choices;

    private:

        QString Heading;
        // Pointer to the main menu
        Main_MP* Main_M;

};

#endif
