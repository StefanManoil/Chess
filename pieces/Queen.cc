#include "Queen.h"

Piecetype Queen::getType() {
    return Piecetype::Queen;
}

std::vector<std::pair<int,int>> Queen::getMoves(Board board) {
    std::vector<std::pair<int,int>> straights = getStraightMoves(board);
    std::vector<std::pair<int,int>> diagonals = getDiagonalMoves(board);

    for(auto move: diagonals) {
        straights.emplace_back(move);
    }
    
    return straights;
}