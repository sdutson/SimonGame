#include "controller.h"
#include "gamelogic.h"

bool Controller::isValidMove(int buttonValue)
{
    return *moveIterator == buttonValue;
}

Controller::Controller()
{
}

void Controller::gameStart()
{
    GameLogic model;
    std::vector<int>::iterator moveIterator;
    model.addMove(); // TODO: add in model? 
    // Either call playerTurnEnd or direct call to light up button. 
}

void Controller::playerClickedButton(int buttonValue)
{
    if(!isValidMove(buttonValue))
    {
        // do stuff
    }s
}

void Controller::roundEnd()
{

}
