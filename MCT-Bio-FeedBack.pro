TEMPLATE = app

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

SOURCES += \
    Contents.cpp \
    Driver.cpp \
    Function.cpp \
    MAIN_MP.cpp \
    MainWindow.cpp

HEADERS += \
    Contents.h \
    Function.h \
    MAIN_MP.h \
    MainWindow.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
