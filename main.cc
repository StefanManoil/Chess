#include "pieces/Piece.h"
#include "pieces/Pawn.h"
#include "pieces/Bishop.h"
#include "pieces/Knight.h"
#include "pieces/Rook.h"
#include "pieces/King.h"
#include "pieces/Queen.h"

#include <iostream>

int main() {
    Piece* b = new Bishop(std::make_pair(0,0), Side::Black);
    Piece* p = new Pawn(std::make_pair(0,1), Side::Black);
    Piece* wb = new Bishop(std::make_pair(8,8), Side::White);
    Piece* wp = new Pawn(std::make_pair(8,7), Side::White);

    std::cout << b->toString() << std::endl;
    std::cout << p->toString() << std::endl;
    std::cout << wb->toString() << std::endl;
    std::cout << wp->toString() << std::endl;
}