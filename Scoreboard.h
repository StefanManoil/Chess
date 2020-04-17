#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "side.h"
#include <iostream>
using namespace std;

class ScoreBoard{
    float white_score;
    float black_score;
public:
    ScoreBoard();
    void printScore();
    void winScore(Side winner);
    void stalemate();
};

#endif