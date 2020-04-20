#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "player.h"
#include <sstream>
using namespace std;

class HumanPlayer: public Player {
public:
    HumanPlayer(Side side);
    ~HumanPlayer();
    bool player_move(Board *board) override;
};

#endif
