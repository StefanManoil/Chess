#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "Piece.h"

class Knight: public Piece {
    public:
        Knight(std::pair<int,int> coordinates, bool moved, Side side): Piece(coordinates, moved, side) {};
        Piecetype getType() override;
        std::vector<std::pair<int,int>> getMoves(Board *board) override;
};

#endif