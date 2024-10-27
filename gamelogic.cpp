#include "gamelogic.h"
#include "Color.h"
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
    int moveID = std::rand() % 2;
    Color newMove = static_cast<Color>(moveID);
    moves.push_back(newMove);
}

vector<Color> &GameLogic::getMoves()
{
    return moves;
}
