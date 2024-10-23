#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gamelogic.h"

class Controller
{
    GameLogic model;

    std::vector<int>::iterator moveIterator;

    bool isValidMove(int buttonValue);

    int getWaitTime(int currentWaitTime);

    int incrementProgressBar();

    const int COMPUTER_TURN_LENGTH = 2000; // TODO: adjust this as needed.

public:
    Controller(QObject *parent);

    Controller(); //TODO: Do we need the default constructor?

    void gameStart(); // Initalizes logic

    void playerClickedButton(int buttonValue);

    void roundEnd(); 

    void gameEnd();

signals:
    updateProgressBar(int);
};

#endif // CONTROLLER_H
