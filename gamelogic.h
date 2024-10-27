#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
using std::vector;

/// @brief - This class represents the game logic backing the model for the game. 
/// @author - Samuel Dutson & Alexander Kuettel 
/// Assign 06
class GameLogic
{
    vector<int> moves; // A vector storing all of the computer's moves. 

public:
    /// @brief - Constructor for a new GameLogic object.
    GameLogic();

    /// @brief - Adds a random move to moves(The computer's moves.)
    void addMove();

    /// @brief - Get the computer's moves. 
    /// @return - The vector storing the computer's moves. 
    vector<int>& getMoves();
};

#endif // GAMELOGIC_H
