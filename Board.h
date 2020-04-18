#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <iostream>
#include "Boardstatus.h"
#include "pieces/Piece.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"

class Board {
    private:
        std::vector<std::vector<Piece*>> pieces;
        bool inSetupMode = false;
    public:
        Board();
        // void methods
        void setPieceInSetup(std::pair<int, int> pos, Side side, Piecetype piecetype);
        void removePieceInSetup(std::pair<int , int> location);
        void setup();
        void exitSetup();
        void print();
        void resetBoard();
        // retrieve information of piece at particular location
        Piecetype getTypeOfPiece(std::pair<int, int> location);
        Side getSideOfPiece(std::pair<int, int> location);
        // player move logic
        bool canMovePiece(std::pair<int, int> currentPos);
        bool pieceAtPosMoved(std::pair<int, int> currentPos);
        bool capturable(std::pair<int, int> pos, Side side);
        // board status checks
        BoardStatus getStatus();
        BoardStatus getStatusUponMove(std::pair<int, int> currentPos, std::pair<int, int> destPos);
};

#endif