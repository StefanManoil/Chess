#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include <vector>
#include "Piece.h"
#include "Piecetype.h"

class Knight: public Piece {
    public:
        Knight(std::pair<int,int> coordinates, Side side): Piece{coordinates, side} {};
        Piecetype getType();
        std::vector<std::pair<int,int>> getMoves(Board board);
};

#endif