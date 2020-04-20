#include "Bishop.h"

Piecetype Bishop::getType() {
    return Piecetype::Bishop;
}

std::vector<std::pair<int,int>> Bishop::getMoves(Board board) {
    return getDiagonalMoves(board);
}