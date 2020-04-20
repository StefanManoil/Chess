#include "scoreboard.h"
using namespace std;

ScoreBoard::ScoreBoard() {
    white_score = 0;
    black_score = 0;
}


void ScoreBoard::printScore() {
    cout << "Final Score:" << endl;
    cout << "White: " << white_score << endl;
    cout << "Black: " << black_score << endl;
}


void ScoreBoard::winScore(Side winner) {
    if (winner == Side::Black) {
        black_score += 1;
    }
    else white_score += 1;
}


void ScoreBoard::stalemate() {
    black_score += 0.5;
    white_score += 0.5;
}