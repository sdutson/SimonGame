#include "mainwindow.h"
#include <QApplication>
#include "model.h"
/// @brief - Sets up and starts the GUI application. 
/// @author - Samuel Dutson & Alexander Kuettel 
/// Assign 06
/// Github authors: sdutson and alexanderkuettel
/// Github link: https://github.com/University-of-Utah-CS3505/a6-simon-f24-alexanderkuettel
/// Creative Element: For our creative element we added a button that allowed the player to reset the round(Once per game).
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model);
    w.show();
    return a.exec();
}
