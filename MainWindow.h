/*
 * File name: MainWindow.h
 * Description: The header file for the 'MainWindow' class
 *
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include "MAIN_MP.h"

namespace Ui {
    class MainWindow;
}

/*
 * Declaration of the 'MainWindow' class
*/

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);
        ~MainWindow();
        void ChangeMain_MP(Main_MP* Main_MP);

    private slots:
        void Right_Button();
        void Up_Button();
        void Down_Button();
        void Back_Button();
        void Ok_Button();
        void Left_Button();


    private:
        // Vector for storing the list of recorded treatments
        vector<Main_MP*>* vChoices = new vector<Main_MP*>;
        //All the contents of the main menu.
        Main_MP* mainMain_MP = new Main_MP(this, "MAIN MENU");
        Main_MP* FunctionsMain_MP = new Main_MP(this, "PROGRAMS", nullptr, mainMain_MP);
        Main_MP* freqMain_MP = new Main_MP(this, "FREQUENCY", nullptr, mainMain_MP);
        Main_MP* medMain_MP = new Main_MP(this, "MED", nullptr, mainMain_MP);
        Main_MP* scMain_MP = new Main_MP(this, "SCREENING", nullptr, mainMain_MP);
        Main_MP* childrenMain_MP = new Main_MP(this, "CHILDREN", nullptr, mainMain_MP);
        Main_MP* settingsMain_MP = new Main_MP(this, "SETTING", nullptr, mainMain_MP);
        Main_MP* hisMain_MP = new Main_MP(this, "HISTORY", nullptr, mainMain_MP);
        Main_MP* viewhis = new Main_MP(this, "View", nullptr, hisMain_MP);
        Main_MP* clearhis = new Main_MP(this, "Clear", nullptr, hisMain_MP);

        Ui::MainWindow* ui;
        // Pointer pointing to the current menu
        Main_MP* currentMain_MP;
        int c = 0;
};

#endif
