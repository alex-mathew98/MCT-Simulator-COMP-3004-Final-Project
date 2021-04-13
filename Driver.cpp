#include <QApplication>
#include <QLabel>

#include <MainWindow.h>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    MainWindow ShowMain;
    ShowMain.show();

    return app.exec();
}
