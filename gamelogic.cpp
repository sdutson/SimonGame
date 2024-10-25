#include "gamelogic.h"
#include <cstdlib>
#include <vector>
/// @author - Samuel Dutson & Alexander Kuettel 
/// Assign 06
using std::rand;

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
