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
    model.addMove(); // TODO: add in model? 
    // TODO:Either call playerTurnEnd or direct call to light up button. 
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
    //TODO: Make timers. 
}

void Controller::gameEnd()
{
    
}
