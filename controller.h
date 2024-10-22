#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gamelogic.h"

class Controller
{
    GameLogic model;

    std::vector<int>::iterator moveIterator;

    bool isValidMove(int buttonValue);

    const int COMPUTER_TURN_LENGTH = 2000; // TODO: adjust this as needed.

public:
    Controller(QObject *parent);

    Controller(); //TODO: Do we need the default constructor?

    void gameStart(); // Initalizes logic

    void playerClickedButton(int buttonValue);

    void roundEnd(); 

    void gameEnd();

};

// Addmove to gameLogic when prompted by view. 
// Slot for when player clickes button. 
//  - Update the progress bar. 
//  - If incorrect endGame. 
//  - If bar = 100% roundEnd. 

// When it's computer's turn. computerTurn(). 
//  - Iterate over computer moves. 

// Qtimer: set method to displayMove. DisplayMove emits a signal to the view. 
// !iter.hasNext() -> QTimer.stop. 
// computerTurnEnd(). 


#endif // CONTROLLER_H
