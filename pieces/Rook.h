#ifndef _ROOK_H_
#define _ROOK_H_

#include "Piece.h"

class Rook: public Piece {
    public:
        Rook(std::pair<int,int> coordinates, bool moved, Side side): Piece(coordinates, moved, side) {};
        Piecetype getType() override;
        std::vector<std::pair<int,int>> getMoves(Board *board) override;
};

#endif