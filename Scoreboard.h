#ifndef _SCORE_BOARD_H
#define _SCORE_BOARD_H

#include "Side.h"
#include <iostream>
using namespace std;

class Scoreboard{
    float white_score;
    float black_score;
public:
    Scoreboard();
    void printScore();
    void winScore(Side winner);
};

#endif