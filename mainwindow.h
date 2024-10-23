#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Controller& controller, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void startButtonClicked();

    void redButtonClicked();

    void blueButtonClicked();

    void redButtonFlash();

    void blueButtonFlash();

private:
    Ui::MainWindow *ui;

    void setRedButtonColor();

    void setBlueButtonColor();
};
#endif // MAINWINDOW_H

// Slots needed
//  - For when player presses start button.
//  - For when player presses redButton.(Light it up)
//  - For when player presses blueButton (Light it up).
//  - For when controller tells up to light up a button. (This can also work in tandem with the previous two slots.)
//  - For when controller tells us to end the game.
