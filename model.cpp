#include "gamelogic.h"
#include "model.h"
#include <QTimer>
/// @author - Samuel Dutson & Alexander Kuettel 
/// Assign 06

bool Model::isValidMove(int buttonValue)
{
    return *moveIterator == buttonValue;
}

int Model::getWaitTime(int currentWaitTime)
{
    return currentWaitTime += 500 + (COMPUTER_TURN_LENGTH / gameLogic.getMoves().size());
}

int Model::incrementProgressBar()
{
    int index = static_cast<int>(std::distance(gameLogic.getMoves().begin(), moveIterator));
    int size = static_cast<int>(gameLogic.getMoves().size());
    return (index * 100) / size;
}

Model::Model(QObject *parent) : QObject(parent) {}

void Model::gameStart()
{
    GameLogic gameLogic;
    std::vector<int>::iterator moveIterator = gameLogic.getMoves().begin();
    roundEnd();
}

void Model::redButtonPressed()
{
    playerClickedButton(0);
}

void Model::blueButtonPressed()
{
    playerClickedButton(1);
}

void Model::playerClickedButton(int buttonValue)
{
    if(!isValidMove(buttonValue))
    {
        // If player lost, inform the view and reset needed elements. 
        gameLogic.
getMoves().clear();
        emit updateProgressBar(0);
        emit gameEnd();
        return;
    }
    moveIterator++;
    // Update the progress bar.
    emit updateProgressBar(incrementProgressBar());

    // Check if the player's turn is over. 
    if(moveIterator == gameLogic.getMoves().end())
    {
        emit buttonEnabled(false);
        roundEnd();
    }
}

void Model::roundEnd()
{
    gameLogic.addMove();
    displayMoves();
    moveIterator = gameLogic.getMoves().begin(); // Reset the iterator.
}

void Model::displayMoves()
{
    int waitTime = 500;
    for(int move: gameLogic.getMoves())
    {
        // Set timers to flash for each move.
        waitTime = getWaitTime(waitTime);
        QTimer::singleShot(waitTime, Qt::PreciseTimer, this, [this, move]() {emit flashButton(move);});
    }
    // Enable buttons for player after all flashes are done.
    QTimer::singleShot(waitTime + 500, Qt::PreciseTimer, this, [this]() {emit buttonEnabled(true);});
}

void Model::restartTurnButtonPressed()
{
    emit buttonEnabled(false); // Disable the color buttons.
    emit restartTurnUsed();
    displayMoves();
    moveIterator = gameLogic.getMoves().begin(); // Reset the iterator.
}

