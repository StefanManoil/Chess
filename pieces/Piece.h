#ifndef _PIECE_H_
#define _PIECE_H_

#include "../Side.h"
#include "Piecetype.h"
#include <string>
#include <vector>


class Piece {
    protected:
        std::pair<int,int> coordinates;
        bool hasMoved;
        virtual std::vector<std::pair<int,int>> getStraightMoves();
        virtual std::vector<std::pair<int,int>> getDiagonalMoves();
        bool validCoordinate(std::pair<int,int>);
    public:
        Side side;
        Piece(std::pair<int,int> coordinates, Side side) : coordinates{coordinates}, hasMoved{false}, side{side} {};
        virtual ~Piece() {};
        virtual std::vector<std::pair<int,int>> getMoves() = 0;
        virtual Piecetype getType() = 0;
        std::string toString();
};

#endif