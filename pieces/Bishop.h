#ifndef _BISHOP_H
#define _BISHOP_H

#include "Piece.h"

class Bishop: public Piece {
    public:
        Bishop(std::pair<int,int> coordinates, bool moved, Side side): Piece(coordinates, moved, side) {};
        Piecetype getType() override;
        std::vector<std::pair<int,int>> getMoves(Board *board) override;
};

#endif