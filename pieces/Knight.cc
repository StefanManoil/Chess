#include "Knight.h"
#include "../Board.h"

Piecetype Knight::getType() {
    return Piecetype::Knight;
}

std::vector<std::pair<int,int>> Knight::getMoves(Board *board) {
    std::vector<std::pair<int,int>> moves;
    std::pair<int,int> move;

    int x = this->coordinates.first;
    int y = this->coordinates.second;

    //moves for a knight are:
    //2 up 1 right, 2 up 1 left, 2 right 1 up, 2 right 1 down, 2 left 1 up, 2 left 1 down, 2 down 1 right, 2 down 1 left

    //2 up 1 right
    move = std::make_pair(x - 2, y + 1);
    if (checkMove(board, move)) {
        moves.emplace_back(move);
    }

    //2 up 1 left
    move = std::make_pair(x - 2, y - 1);
    if (checkMove(board, move)) {
        moves.emplace_back(move);
    }

    //2 right 1 up
    move = std::make_pair(x - 1, y + 2);
    if (checkMove(board, move)) {
        moves.emplace_back(move);
    }

    //2 right 1 down
    move = std::make_pair(x + 1, y + 2);
    if (checkMove(board, move)) {
        moves.emplace_back(move);
    }

    //2 left 1 up
    move = std::make_pair(x - 1, y - 2);
    if (checkMove(board, move)) {
        moves.emplace_back(move);
    }

    //2 left 1 down
    move = std::make_pair(x + 1, y - 2);
    if (checkMove(board, move)) {
        moves.emplace_back(move);
    }

    //2 down 1 right
    move = std::make_pair(x + 2, y + 1);
    if (checkMove(board, move)) {
        moves.emplace_back(move);
    }

    //2 down 1 left
    move = std::make_pair(x + 2, y - 1);
    if (checkMove(board, move)) {
        moves.emplace_back(move);
    }

    return moves;
}
