#ifndef CPUPLAYER_H
#define CPUPLAYER_H
#include "player.h"

class CPUPlayer: public Player {
    int diff_level;
    public;
    CPUPlayer(side, diff_level);
    ~CPUPlayer();
    bool player_move(Board *board) override;
};

#endif
