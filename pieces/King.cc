#include "King.h"

Piecetype King::getType() {
    return Piecetype::King;
}

std::vector<std::pair<int,int>> King::getMoves() {
    std::vector<std::pair<int,int>> moves;
    std::pair<int,int> move;

    int x = this->coordinates.first;
    int y = this->coordinates.second;

    //Possible moves are:
    //1 in each adjacent, 1 in each diagonal, castle

    //Direction doesn't matter for king, no need to check side of piece
    
    //down
    move = std::make_pair(x, y+1);
    //do checking
    moves.emplace_back(move);

    //down right
    move = std::make_pair(x+1, y+1);
    //do checking
    moves.emplace_back(move);

    //down left
    move = std::make_pair(x-1, y+1);
    //do checking
    moves.emplace_back(move);

    //right
    move = std::make_pair(x+1, y);
    //do checking
    moves.emplace_back(move);

    //left
    move = std::make_pair(x-1, y);
    //do checking
    moves.emplace_back(move);

    //up
    move = std::make_pair(x, y-1);
    //do checking
    moves.emplace_back(move);

    //up right
    move = std::make_pair(x+1, y+1);
    //do checking
    moves.emplace_back(move);

    //up left
    move = std::make_pair(x-1, y+1);
    //do checking
    moves.emplace_back(move);

    //add castling to the moves
    /*
     *
     * 
     * 
     */

    return moves;
}