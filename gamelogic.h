#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include <iostream>

using std::vector;

class GameLogic
{
    vector<int> moves;

public:
    GameLogic();

    void addMove();

    vector<int>& getMoves();

};

#endif // GAMELOGIC_H
