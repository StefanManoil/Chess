#include "conversion.h"
using namespace std;

pair<int, int> Conversion::toCoordinate(string location) {
    if (location.length() != 2) {
        throw "invalid location"
    }
    else {
        string r = location[1];
        string c = location[0];
        int row, col;

        if (c == "a") col = 0;
        else if (c == "b") col = 1;
        else if (c == "c") col = 2;
        else if (c == "d") col = 3;
        else if (c == "e") col = 4;
        else if (c == "f") col = 5;
        else if (c == "g") col = 6;
        else if (c == "h") col = 7;
        else throw "invalid location";

        if (row == "1") row = 7;
        else if (row == "2") row = 6;
        else if (row == "3") row = 5;
        else if (row == "4") row = 4;
        else if (row == "5") row = 3;
        else if (row == "6") row = 2;
        else if (row == "7") row = 1;
        else if (row == "8") row = 0;
        else throw "invalid location"

        return make_pair(row, col);
    }
}


PieceType Conversion::toType(string piece) {
    if (piece == "K" || piece == "k") return PieceType::King;
    else if (piece == "Q" || piece == "q") return PieceType::Queen;
    else if (piece == "R" || piece == "r") return PieceType::Rook;
    else if (piece == "N" || piece == "n") return PieceType::Knight;
    else if (piece == "B" || piece == "b") return PieceType::Bishop;
    else if (piece == "P" || piece == "p") return PieceType::Pawn;
    else throw "invalid type";
}


Side Conversion::toSide(string piece) {
    if (piece == "K" || piece == "Q" || piece == "R" || piece == "N" || piece == "B" || piece == "P") {
        return Side::White;
    }
    else return Side::Black;
}