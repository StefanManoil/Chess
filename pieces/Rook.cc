#include "Rook.h"

Piecetype Rook::getType() {
    return Piecetype::Rook;
}

std::vector<std::pair<int,int>> Rook::getMoves() {
    /* 
     *
     * 
     * add castling move
     * 
     * 
     */
    
    return getStraightMoves();
}