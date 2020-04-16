#include "cpuplayer.h"
using namespace std;

CPUPlayer::CPUPlayer(side, diff_level): Player(side), diff_level{diff_level} {}


CPUPlayer::~CPUPlayer() {}


bool CPUPlayer::player_move(Board *board) {
    return board->CPUmove(side, diff_level);
}