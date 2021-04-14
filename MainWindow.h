#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include "MAIN_MP.h"

namespace Ui {
    class MainWindow;
}

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
    Ui::MainWindow* ui;
    Main_MP* currentMain_MP;
};

#endif
