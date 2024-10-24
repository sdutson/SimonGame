#include "gamelogic.h"
#include <cstdlib>
#include <vector>


using std::rand;

GameLogic::GameLogic()
{
    std::srand(static_cast<unsigned int>(time(NULL)));
}

void GameLogic::addMove()
{
    const int numButtons = 2;

    int newMove = std::rand() % numButtons;
    moves.push_back(newMove);
}

vector<int> &GameLogic::getMoves()
{
    return moves;
}
