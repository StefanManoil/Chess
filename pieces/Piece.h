#ifndef _PIECE_H_
#define _PIECE_H_

#include <string>
#include <vector>
#include "Piecetype.h"
#include "../Side.h"
#include "../Board.h"

class Piece {
    protected:
        std::pair<int,int> coordinates;
        bool moved;
        virtual std::vector<std::pair<int,int>> getStraightMoves(Board *board);
        virtual std::vector<std::pair<int,int>> getDiagonalMoves(Board *board);
    public:
        Side side;
        Piece(std::pair<int,int> coordinates, Side side) : coordinates{coordinates}, moved{false}, side{side} {};
        virtual ~Piece() {};
        virtual std::vector<std::pair<int,int>> getMoves(Board *board) = 0;
        virtual Piecetype getType() = 0;
        std::string toString();
        std::pair<int,int> getCoordinates();
        bool hasMoved();
        bool checkMove(Board *board, std::pair<int,int> move);
};

#endif