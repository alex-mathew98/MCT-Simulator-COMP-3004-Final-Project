/*
 * File name: Function.h
 * Description: The header file for the 'Function' class
 *
*/
#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include <QTimer>
#include <MAIN_MP.h>
#include <MainWindow.h>
#include "ui_mainwindow.h"

/*
 * Declaration of the 'Function' class
*/
class Function : public QObject {

    Q_OBJECT

    public:
        explicit Function(QObject* parent = nullptr, Ui::MainWindow* ui = nullptr, short freq = 0, int duration = 0, short powerLevel = 1);
        ~Function();
        void Start();
        void Stop();
        void SetPowerLevel(short powerLevel);
        QTimer* GetTimer();
        short Getfreq();
        short GetPowerLevel();
        //Variable to store the original time
        const int originalDuration;
        bool isActive;

    private slots:
        void Update();

    private:
        Ui::MainWindow* ui;
        short freq, powerLevel;
        int duration;
        QTimer* sessionTime;
        void UpdateUI();
};

#endif
