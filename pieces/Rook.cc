#include "Rook.h"
#include "../Board.h"

Piecetype Rook::getType() {
    return Piecetype::Rook;
}

std::vector<std::pair<int,int>> Rook::getMoves(Board *board) {    
    return getStraightMoves(board);
}