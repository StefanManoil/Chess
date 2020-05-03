#ifndef _KING_H_
#define _KING_H_

#include "Piece.h"

class King: public Piece {
    public:
        King(std::pair<int,int> coordinates, bool moved, Side side): Piece(coordinates, moved, side) {};
        Piecetype getType() override;
        std::vector<std::pair<int,int>> getMoves(Board *board) override;
};

#endif