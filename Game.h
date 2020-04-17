#ifndef _GAME_H_
#define _GAME_H_

#include "Board.h"
#include "Player.h"
#include "Scoreboard.h"
//include "Boardstatus.h"
#include "Side.h"
#include <iostream>

class Game {
    Board* board;
    Scoreboard* score;
    Player* white;
    Player* black;
    Side currentSide;
    public:
        Game(Board* board, Scoreboard* score, Player* white, Player* black, Side currentSide): board{board}, score{score}, white{white}, black{black}, currentSide{currentSide} {};
        ~Game() {
            board->resetBoard();
            delete white;
            delete black;
        }
        void start();
};

#endif