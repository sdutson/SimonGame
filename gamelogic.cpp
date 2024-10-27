#include "gamelogic.h"
#include <cstdlib>
#include <vector>

using std::rand;
/// @author - Samuel Dutson & Alexander Kuettel
/// Assign 06

GameLogic::GameLogic()
{
    std::srand(static_cast<unsigned int>(time(NULL)));
}

void GameLogic::addMove()
{
    int newMove = std::rand() % 2;
    moves.push_back(newMove);
}

vector<int> &GameLogic::getMoves()
{
    return moves;
}
