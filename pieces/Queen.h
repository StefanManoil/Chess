#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "Piece.h"
#include <vector>


class Queen: public Piece {
    public:
        Queen(std::pair<int,int> coordinates, Side side): Piece{coordinates, side} {};
        Piecetype getType();
        std::vector<std::pair<int,int>> getMoves(Board board);
};

#endif