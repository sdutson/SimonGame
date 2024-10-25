#include "mainwindow.h"

#include <QApplication>
#include "controller.h"
/// @brief - Sets up and starts the GUI application. 
/// @author - Samuel Dutson & Alexander Kuettel 
/// Assign 06
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller controller;
    MainWindow w(controller);
    w.show();
    return a.exec();
}
