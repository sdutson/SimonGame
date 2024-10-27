#include "mainwindow.h"
#include <QApplication>
#include "model.h"
/// @brief - Sets up and starts the GUI application. 
/// @author - Samuel Dutson & Alexander Kuettel 
/// Assign 06
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model);
    w.show();
    return a.exec();
}
