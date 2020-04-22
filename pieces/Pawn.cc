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
        move = std::make_pair(x, y + 1);
        if (checkMove(board, move)) {
            std::cout << "ADDING MOVE: " << move.first << "," << move.second << std::endl;
            moves.emplace_back(move);
        }
        if (!this->hasMoved()) {
            //Black moving 2 space forward
            move = std::make_pair(x, y + 2);
            if (checkMove(board, move)) {
                std::cout << "ADDING MOVE: " << move.first << "," << move.second << std::endl;
                moves.emplace_back(move);
            }
        }
        //Black moving forward and right
        move = std::make_pair(x+1, y+1);
        if (checkMove(board, move)) {
            if (board->getSideOfPiece(move) != Side::None) {
                std::cout << "ADDING MOVE: " << move.first << "," << move.second << std::endl;
                moves.emplace_back(move);
            }
        }
        
        //Black moving forward and left
        move = std::make_pair(x-1, y+1);
        if (checkMove(board, move)) {
            if (board->getSideOfPiece(move) != Side::None) {
                std::cout << "ADDING MOVE: " << move.first << "," << move.second << std::endl;
                moves.emplace_back(move);
            }
        }
    }
    else if (this->side == Side::White) {
        //White moving 1 space forward
        move = std::make_pair(x, y-1);
        if (checkMove(board, move)) {
            std::cout << "ADDING MOVE: " << move.first << "," << move.second << std::endl;
            moves.emplace_back(move);
        }

        //White moving 2 space forward
        if (!this->hasMoved()) {
            move = std::make_pair(x, y-2);
            if (checkMove(board, move)) {
                std::cout << "ADDING MOVE: " << move.first << "," << move.second << std::endl;
                moves.emplace_back(move);
            }
        }

        //White moving forward and right
        move = std::make_pair(x+1, y-1);
        if (checkMove(board, move)) {
            if (board->getSideOfPiece(move) != Side::None) {
                std::cout << "ADDING MOVE: " << move.first << "," << move.second << std::endl;
                moves.emplace_back(move);
            }
        }

        //White moving forward and left
        move = std::make_pair(x-1, y-1);
        if (checkMove(board, move)) {
            if (board->getSideOfPiece(move) != Side::None) {
                std::cout << "ADDING MOVE: " << move.first << "," << move.second << std::endl;
                moves.emplace_back(move);
            }
        }
    }
    
    return moves;
}