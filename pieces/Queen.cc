#include "Queen.h"

Piecetype Queen::getType() {
    return Piecetype::Queen;
}

std::vector<std::pair<int,int>> Queen::getMoves() {
    std::vector<std::pair<int,int>> straights = getStraightMoves();
    std::vector<std::pair<int,int>> diagonals = getDiagonalMoves();

    for(auto move: diagonals) {
        straights.emplace_back(move);
    }
    
    return straights;
}