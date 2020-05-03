#ifndef _PAWN_H_
#define _PAWN_H_

#include "Piece.h"

class Pawn: public Piece {
    public:
        Pawn(std::pair<int,int> coordinates, bool moved, Side side): Piece(coordinates, moved, side) {};
        Piecetype getType() override;
        std::vector<std::pair<int,int>> getMoves(Board *board) override;
};

#endif