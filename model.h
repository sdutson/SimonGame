#ifndef MODEL_H
#define MODEL_H

#include "gamelogic.h"
#include <QObject>
/// @author - Samuel Dutson & Alexander Kuettel 
/// Assign 06
// TODO: Comment this. And change it's name to model?
class Model : public QObject
{
    Q_OBJECT

private:
    GameLogic gameLogic;

    std::vector<int>::iterator moveIterator;

    /// @brief - This method checks if the given move is valid. 
    /// @param buttonValue - The move taken by the user. 
    /// @return - If the provided matches the move taken by the computer. 
    bool isValidMove(int buttonValue);

    /// @brief - This method calculates a wait time for a timer based off of the current position of moveIterator.
    /// @param currentWaitTime - The current wait time. 
    /// @return - The provided time incremented by at least 500ms. 
    int getWaitTime(int currentWaitTime);

    /// @brief - Calculates the new correct value for the progress bar. 
    /// @return - The correct value between 0-100(inclusive) for the progress bar. 
    int incrementProgressBar();

    /// @brief - Called when the user has finished their turn. Adds a new move to the sequence and prompts the view to display them all
    /// at responsible intervals of time(Displays the computer's turn). 
    void roundEnd();

    /// @brief - Helper method for when the user presses a color button. This method checks the move's correctness and acts accordingly.  
    /// @param buttonValue - The ID of the button that was pressed. 
    void playerClickedButton(int buttonValue);

    /// @brief - Prompts the view to display the computer's moves.
    void displayMoves();

    const int COMPUTER_TURN_LENGTH = 1000; // Constant used to ensure computer moves speed up at game progresses. 

public:
     /// @brief - Constructor for a new Model. 
     /// @param parent - Not used.
     explicit Model(QObject *parent = nullptr);

public slots:
    /// @brief - Slot for when the user starts a new game. Initializes all needed values and starts game. 
    void gameStart();

    /// @brief - Slot for when the user presses the redButton. Makes use of the playerClickedButton helper method. 
    void redButtonPressed();

    /// @brief - Slot for when the user presses the blueButton. Makes use of the playerClickedButton helper method. 
    void blueButtonPressed();

    /// @brief - Restarts the current turn.
    void restartTurnButtonPressed();

signals:
    /// @brief - This signal informs the view that it needs to update the progress bar. 
    /// @param newProgressValue - The new value for the progress bar.
    void updateProgressBar(int newProgressValue);

    /// @brief - This signal informs the view that the user made an incorrect move and that therefore the game needs to end. 
    void gameEnd();

    /// @brief - This signal informs the view that it needs to 'flash' the specified button. 
    /// @param buttonId - The ID of the button to flash. 
    void flashButton(int buttonId);

    /// @brief - This signal informs the view that it needs to update the enables status of the color buttons. 
    /// @param enabled - What the buttons enables status should be set to. 
    void buttonEnabled(bool enabled);

    /// @brief - Informs the view the user has used the restart turn button and that it should noe be disabled.
    /// @param used - What the enabled status of the button should be set to(in this case, always false.)
    void restartTurnUsed(bool used = false);
};

#endif // MODEL_H
