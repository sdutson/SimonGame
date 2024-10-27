#include "controller.h"
#include "gamelogic.h"
#include <QTimer>
/// @author - Samuel Dutson & Alexander Kuettel 
/// Assign 06

bool Controller::isValidMove(int buttonValue)
{
    return *moveIterator == buttonValue;
}

int Controller::getWaitTime(int currentWaitTime)
{
    return currentWaitTime += 500 + (COMPUTER_TURN_LENGTH / model.getMoves().size());
}

int Controller::incrementProgressBar()
{
    int index = static_cast<int>(std::distance(model.getMoves().begin(), moveIterator));
    int size = static_cast<int>(model.getMoves().size());
    return (index * 100) / size;
}

Controller::Controller(QObject *parent) : QObject(parent) {}

void Controller::gameStart()
{
    GameLogic model;
    std::vector<int>::iterator moveIterator = model.getMoves().begin();
    roundEnd();
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
        // If player lost, inform the view and reset needed elements. 
        model.getMoves().clear();
        emit updateProgressBar(0);
        emit gameEnd();
        return;
    }
    moveIterator++;
    // Update the progress bar.
    emit updateProgressBar(incrementProgressBar());

    // Check if the player's turn is over. 
    if(moveIterator == model.getMoves().end())
    {
        emit buttonEnabled(false);
        roundEnd();
    }
}

void Controller::roundEnd()
{
    model.addMove();
    displayMoves();
    moveIterator = model.getMoves().begin(); // Reset the iterator.
}

void Controller::displayMoves()
{
    int waitTime = 500;
    for(int move: model.getMoves())
    {
        // Set timers to flash for each move.
        waitTime = getWaitTime(waitTime);
        QTimer::singleShot(waitTime, Qt::PreciseTimer, this, [this, move]() {emit flashButton(move);});
    }
    // Enable buttons for player after all flashes are done.
    QTimer::singleShot(waitTime + 500, Qt::PreciseTimer, this, [this]() {emit buttonEnabled(true);});
}

void Controller::restartTurnButtonPressed()
{
    emit buttonEnabled(false); // Disable the color buttons.
    emit restartTurnUsed();
    displayMoves();
    moveIterator = model.getMoves().begin(); // Reset the iterator.
}

