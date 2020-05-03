#include "Pawn.h"
#include "../Board.h"

Piecetype Pawn::getType() {
    return Piecetype::Pawn;
}

std::vector<std::pair<int,int>> Pawn::getMoves(Board *board) {
    std::vector<std::pair<int,int>> moves;
    std::pair<int,int> move;

    int x = this->coordinates.first;
    int y = this->coordinates.second;

    //What are all possible moves?
    //1 space forward, 2 space forward (!hasMoved), diagonal (if capture), en passant
    //white pawns move upwards, black pawns move downwards

    if (this->side == Side::Black) {
        //Black moving 1 space forward
        move = std::make_pair(x + 1, y);
        if (this->isCoordinateOnBoard(move)) {
            if (board->getSideOfPiece(move) == Side::None) {
                moves.emplace_back(move);
                if (!this->hasMoved()) {
                    move = std::make_pair(x + 2, y);
                    if (this->isCoordinateOnBoard(move)) {
                        if (board->getSideOfPiece(move) == Side::None) {
                            moves.emplace_back(move);
                        }
                    }
                }
            }
        }
        //Black moving forward and right
        move = std::make_pair(x + 1, y + 1);
        if (this->isCoordinateOnBoard(move)) {
            if (board->getSideOfPiece(move) == Side::White) {
                moves.emplace_back(move);
            }
        }
        
        //Black moving forward and left
        move = std::make_pair(x + 1, y - 1);
        if (this->isCoordinateOnBoard(move)) {
            if (board->getSideOfPiece(move) == Side::White) {
                moves.emplace_back(move);
            }
        }
    }
    else if (this->side == Side::White) {
        //White moving 1 space forward
        move = std::make_pair(x - 1, y);
        if (this->isCoordinateOnBoard(move)) {
            if (board->getSideOfPiece(move) == Side::None) {
                moves.emplace_back(move);
                if (!this->hasMoved()) {
                    move = std::make_pair(x - 2, y);
                    if (this->isCoordinateOnBoard(move)) {
                        if (board->getSideOfPiece(move) == Side::None) {
                            moves.emplace_back(move);
                        }
                    }
                }
            }
        }

        //White moving forward and right
        move = std::make_pair(x - 1, y + 1);
        std::cout << "MoveFirst: " << move.first << "MoveSecond: " << move.second << std::endl;
        if (this->isCoordinateOnBoard(move)) {
            if (board->getSideOfPiece(move) == Side::Black) {
                moves.emplace_back(move);
            }
        }

        //White moving forward and left
        move = std::make_pair(x - 1, y - 1);
        if (this->isCoordinateOnBoard(move)) {
            if (board->getSideOfPiece(move) == Side::Black) {
                moves.emplace_back(move);
            }
        }
    }
    return moves;
}
