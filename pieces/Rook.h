#ifndef _ROOK_H_
#define _ROOK_H_

#include "Piece.h"
#include <vector>

class Rook: public Piece {
    Rook(std::pair<int,int> coordinates, Side side): Piece{coordinates, side} {};
    Piecetype getType();
    std::vector<std::pair<int,int>> getMoves(Board board);
};

#endif