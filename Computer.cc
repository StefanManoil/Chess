#include "Computer.h"
using namespace std;

Computer::Computer(Side side, int diff_level): Player(side), diff_level{diff_level} {}


Computer::~Computer() {}


bool Computer::player_move(Board *board) {
    return board->CPUmove(side, diff_level);
}