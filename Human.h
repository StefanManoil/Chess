#ifndef _HUMAN_H
#define _HUMAN_H

#include "Side.h"
#include "Board.h"
#include "Player.h"
#include "conversion.h"
#include <sstream>
#include <string>

class Human: public Player {
public:
    Human(Side side);
    ~Human();
    bool player_move(Board *board) override;
};

#endif
