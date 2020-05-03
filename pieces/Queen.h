#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "Piece.h"

class Queen: public Piece {
    public:
        Queen(std::pair<int,int> coordinates, bool moved, Side side): Piece(coordinates, moved, side) {};
        Piecetype getType() override;
        std::vector<std::pair<int,int>> getMoves(Board *board) override;
};

#endif