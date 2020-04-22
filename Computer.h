#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "Side.h"
#include "Board.h"
#include "Player.h"

class Computer: public Player {
    int diff_level;
    public:
        Computer(Side side, int diff_level);
        ~Computer();
        bool player_move(Board *board) override;
};

#endif
