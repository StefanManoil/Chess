#ifndef _BISHOP_H
#define _BISHOP_H

#include <vector>
#include "Piece.h"

class Bishop: public Piece {
    public:
        Bishop(std::pair<int,int> coordinates, Side side): Piece{coordinates, side} {};
        Piecetype getType();
        std::vector<std::pair<int,int>> getMoves();
};

#endif