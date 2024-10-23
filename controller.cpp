#include "controller.h"
#include "gamelogic.h"
#include <QTimer>

bool Controller::isValidMove(int buttonValue)
{
    return *moveIterator == buttonValue;
}

int Controller::getWaitTime(int currentWaitTime)
{
    return currentWaitTime += 200 + (OMPUTER_TURN_LENGTH / moves.size());
}

GameLogic::GameLogic(QObject *parent) : QObject(parent) {}

void Controller::gameStart()
{
    GameLogic model;
    std::vector<int>::iterator moveIterator = model.getMoves().begin();
    roundEnd();
}

void Controller::playerClickedButton(int buttonValue)
{
    if(!isValidMove(buttonValue))
    {
       gameEnd();
    }

    // Update progress bar. 

    if(moveIterator == model.getMoves().end()) 
    {
        roundEnd();
    }
    moveIterator++;
}

void Controller::roundEnd()
{
    model.addMove();
    int waitTime = 500;
    for(int move: moves)
    {
        waitTime = getWaitTime(moveTime);
        QTimer::singleShot(); // Put llambda here.
    }
    moveIterator = model.getMoves().begin(); // Reset the iterator.
}

void Controller::gameEnd()
{
    
}
