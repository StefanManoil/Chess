#include "Piece.h"

std::string Piece::toString() {
    Piecetype p = this->getType();
    if (this->side == Side::White) {
        if (p == Piecetype::Pawn) {
            return "P";
        }
        else if (p == Piecetype::Bishop) {
            return "B";
        }
        else if (p == Piecetype::Knight) {
            return "N";
        }
        else if (p == Piecetype::Rook) {
            return "R";
        }
        else if (p == Piecetype::King) {
            return "K";
        }
        else if (p == Piecetype::Queen) {
            return "Q";
        }
    }
    else if (this->side == Side::Black) {
        if (p == Piecetype::Pawn) {
            return "p";
        }
        else if (p == Piecetype::Bishop) {
            return "b";
        }
        else if (p == Piecetype::Knight) {
            return "n";
        }
        else if (p == Piecetype::Rook) {
            return "r";
        }
        else if (p == Piecetype::King) {
            return "k";
        }
        else if (p == Piecetype::Queen) {
            return "q";
        }
    }
    return "";
}
