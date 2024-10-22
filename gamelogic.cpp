#include "gamelogic.h"
#include <cstdlib>
#include <vector>

using std::rand;

GameLogic::GameLogic()
{
    vector<int> moves;
}

void GameLogic::addMove()
{
    const int numButtons = 2;
    int newMove = rand() % numButtons;
    moves.push_back(newMove);
}

vector<int> &GameLogic::getMoves()
{
    return moves;
}
