#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "Piece.h"

class Knight: public Piece {
    public:
        Knight(std::pair<int,int> coordinates, Side side): Piece(coordinates, side) {};
        Piecetype getType() override;
        std::vector<std::pair<int,int>> getMoves(Board *board) override;
};

#endif