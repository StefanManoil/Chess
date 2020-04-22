#include "Scoreboard.h"
using namespace std;

Scoreboard::Scoreboard() {
    white_score = 0;
    black_score = 0;
}


void Scoreboard::printScore() {
    cout << "Final Score:" << endl;
    cout << "White: " << white_score << endl;
    cout << "Black: " << black_score << endl;
}


void Scoreboard::winScore(Side winner) {
    if (winner == Side::Black) {
        black_score += 1;
    }
    else if (winner == Side::White) {
        white_score += 1;
    }
    else if (winner == Side::None) {
        black_score += 0.5;
        white_score += 0.5;
    }
}