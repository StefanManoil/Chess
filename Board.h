#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include "Boardstatus.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"

class Piece;

class Board {
    private:
        //std::vector<std::vector<Piece*>> pieces;
        //std::vector<Piece*> actualPieces;
        //
        //std::map<std::pair<int, int>, Piece*> actualPosOfPieces;
        std::map<std::pair<int, int>, Piece*> actualPosOfWhitePieces;
        std::map<std::pair<int, int>, Piece*> actualPosOfBlackPieces;
        bool inSetupMode = false;
        bool gameInProgress = false;
        bool whiteSideNoMoves = false;
        bool blackSideNoMoves = false;
        // maybes
        std::string invalidMoveMessageIfNeeded;
        BoardStatus currentBoardStatus = BoardStatus::Normal;
    public:
        Board() {
            resetBoard();
        };
        bool inSetup();
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
        //bool canMovePiece(std::pair<int, int> currentPos);
        bool pieceAtPosMoved(std::pair<int, int> currentPos);
        bool canSideCaptureDestPos(std::pair<int, int> destPos, Side currentSide);
        //
        bool canPieceMoveToDestPos(std::pair<int, int> currentPos, std::pair<int, int> destPos, Side currentSide);
        bool canKingInCheckMoveToSafePos(Side currentSide);
        bool canFriendlyPiecesBlockEnemyPieces(Side currentSide);
        bool canFriendlyPiecesDestroyEnemyAttackingKing(Side currentSide);
        bool doesSideHaveMovesLeft(Side currentSide);
        bool willMoveRenderSideInCheck(Side currentSide, std::pair<int, int> currentPos, std::pair<int, int> destPos);
        // board status checks
        BoardStatus getStatus();
        BoardStatus getStatusAfterMove(std::pair<int, int> currentPos, std::pair<int, int> destPos);
        //
        BoardStatus getStatusOfCurrentSide(Side currentSide);
        BoardStatus getCurrentStatusField();
        BoardStatus getStatusBasic();
        BoardStatus getStatusField();
        // ^ not sure if getStatus should have side yet or not
        bool getComputerMove(Side side, int diff_level);
};

#endif