#include "controller.h"
#include "gamelogic.h"


bool Controller::isValidMove(int buttonValue)
{
    return *moveIterator == buttonValue;
}

Controller::Controller() {}

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
    //TODO: Make timers. 
}

void Controller::gameEnd()
{
    
}
