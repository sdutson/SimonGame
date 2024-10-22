#include "controller.h"
#include "gamelogic.h"


bool Controller::isValidMove(int buttonValue)
{
    return *moveIterator == buttonValue;
}

GameLogic::GameLogic(QObject *parent) : QObject(parent)
{
    GameLogic model;
    std::vector<int>::iterator moveIterator = model.getMoves().begin();
}

void Controller::gameStart()
{
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
    //TODO: Make timers. 
}

void Controller::gameEnd()
{
    
}
