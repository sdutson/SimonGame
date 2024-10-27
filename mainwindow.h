#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"
#include "Color.h"

QT_BEGIN_NAMESPACE
namespace Ui {
/// @brief -  The view for the Simon Game.
/// @author - Samuel Dutson & Alexander Kuettel
/// Assign 06
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// @brief - Constructor for a new MainWindow.
    /// @param model - The model for the game. 
    /// @param parent - Not used.  
    MainWindow(Model& model, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    /// @brief - Slot for when the user clicks the start button. 
    void startButtonClicked();

    /// @brief - Slot for when the model prompts the view to flash a button. 
    /// @param buttonId - The id of the button to flash. 
    void buttonFlash(Color buttonId);

    /// @brief - Slot for when the model prompts the view to end the game. 
    void gameOver();

private:
    Ui::MainWindow *ui;

    /// @brief - Sets/resets the red button color(At either game start or after red button flashes). 
    void setRedButtonColor();

    /// @brief - Sets/resets the blue button color(At either game start or after blue button flashes.)
    void setBlueButtonColor();

    /// @brief - Flashes the red button.
    void redButtonFlash();

    /// @brief - Flashes the blue button. 
    void blueButtonFlash();

    /// @brief - Enables/Disables both the color buttons. 
    /// @param enabled - State to set the buttons to. 
    void buttonEnabled(bool enabled);
};
#endif // MAINWINDOW_H
