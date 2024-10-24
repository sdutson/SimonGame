#include "controller.h"
#include "gamelogic.h"
#include <QTimer>

bool Controller::isValidMove(int buttonValue)
{
    return *moveIterator == buttonValue;
}

// int Controller::getWaitTime(int currentWaitTime)
// {
//     return currentWaitTime += 200 + (COMPUTER_TURN_LENGTH / moves.size());
// }

int Controller::incrementProgressBar()
{
    int index = static_cast<int>(std::distance(model.getMoves().begin(), moveIterator));
    // return (index / moveIterator.size()) * 100;
}

Controller::Controller(QObject *parent) : QObject(parent) {}

void Controller::gameStart()
{
    GameLogic model;
    std::vector<int>::iterator moveIterator = model.getMoves().begin();
    // roundEnd();
}

void Controller::redButtonPressed()
{
    playerClickedButton(0);
}

void Controller::blueButtonPressed()
{
    playerClickedButton(1);
}

void Controller::playerClickedButton(int buttonValue)
{
    if(!isValidMove(buttonValue))
    {
       emit gameEnd(); // End the game.
    }
    // Update the progress bar.
    emit updateProgressBar(100);
    // emit updateProgressBar(incrementProgressBar()); // TODO: Connect to view.

    // if(moveIterator == model.getMoves().end())
    // {
    //     roundEnd();
    // }
    // moveIterator++;
}

// void Controller::roundEnd()
// {
//     emit updateProgressBar(0); // Clear the progress bar.
//     model.addMove();
//     int waitTime = 500;
//     for(int move: moves)
//     {
//         waitTime = getWaitTime(moveTime);
//         QTimer::singleShot(); // TODO: Inform view of what button to light up. Use llambda.
//     }
//     moveIterator = model.getMoves().begin(); // Reset the iterator.
//}

