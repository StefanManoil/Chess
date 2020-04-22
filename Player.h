#ifndef _PLAYER_H
#define _PLAYER_H

#include "Side.h"
#include "Board.h"
#include "pieces/Piecetype.h"
#include "conversion.h"

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
