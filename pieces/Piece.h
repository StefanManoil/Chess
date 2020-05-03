#ifndef _PIECE_H_
#define _PIECE_H_

#include <string>
#include <vector>
#include "Piecetype.h"
#include "../Side.h"

class Board;

class Piece {
    protected:
        std::pair<int,int> coordinates;
        bool moved;
        virtual std::vector<std::pair<int,int>> getStraightMoves(Board *board);
        virtual std::vector<std::pair<int,int>> getDiagonalMoves(Board *board);
        virtual bool isCoordinateOnBoard(std::pair<int,int> coordinate);
    public:
        Side side;
        Piece(std::pair<int,int> coordinates, bool moved, Side side) : coordinates{coordinates}, moved{moved}, side{side} {};
        virtual ~Piece() {};
        virtual std::vector<std::pair<int,int>> getMoves(Board *board) = 0;
        virtual Piecetype getType() = 0;
        std::string toString();
        std::pair<int,int> getCoordinates();
        bool hasMoved();
        void setMoved(bool val);
        bool checkMove(Board *board, std::pair<int,int> move);
        std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> getComputerMove(Board *board, int diff_level);
};

#endif