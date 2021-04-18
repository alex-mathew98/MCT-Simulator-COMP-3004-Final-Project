/*
 * File name: Driver.cpp
 * Description: Initializing the driver for the main window.
 *
*/
#include <QApplication>
#include <QLabel>

#include <MainWindow.h>

int main(int argc, char** argv) {

    //Driver for the Main Window
    QApplication app(argc, argv);
    //Display the main window
    MainWindow ShowMain;
    ShowMain.show();

    return app.exec();
}
