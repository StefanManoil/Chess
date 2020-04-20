#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"
#include "conversion.h"
#include <string>
#include <iostream>
using namespace std;

class Player{
public:
    Side side;
    Player(Side side);
    virtual ~Player();

    // if the move is legal, move the piece on the board
    // otherwise, return 0 and Game class will ask for another move
    virtual bool player_move(Board *board) = 0;
};


#endif
