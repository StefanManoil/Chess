#ifndef _PAWN_H_
#define _PAWN_H_

#include <string>
#include <vector>
#include "Piece.h"

class Pawn: public Piece {
    public:
        Pawn(std::pair<int,int> coordinates, Side side): Piece{coordinates, side} {};
        Piecetype getType();
        std::vector<std::pair<int,int>> getMoves(Board board);
};

#endif