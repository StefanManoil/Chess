#include "conversion.h"
using namespace std;

pair<int, int> Conversion::toCoordinate(string location) {
    if (location.length() != 2) {
        throw "invalid location";
    }
    else {
        char r = location.at(1);
        char c = location.at(0);
        int row, col;

        if (c == 'a') col = 0;
        else if (c == 'b') col = 1;
        else if (c == 'c') col = 2;
        else if (c == 'd') col = 3;
        else if (c == 'e') col = 4;
        else if (c == 'f') col = 5;
        else if (c == 'g') col = 6;
        else if (c == 'h') col = 7;
        else throw "invalid location";

        if (r == '1') row = 7;
        else if (r == '2') row = 6;
        else if (r == '3') row = 5;
        else if (r == '4') row = 4;
        else if (r == '5') row = 3;
        else if (r == '6') row = 2;
        else if (r == '7') row = 1;
        else if (r == '8') row = 0;
        else throw "invalid location";

        return make_pair(row, col);
    }
}


Piecetype Conversion::toType(string piece) {
    if (piece == "K" || piece == "k") return Piecetype::King;
    else if (piece == "Q" || piece == "q") return Piecetype::Queen;
    else if (piece == "R" || piece == "r") return Piecetype::Rook;
    else if (piece == "N" || piece == "n") return Piecetype::Knight;
    else if (piece == "B" || piece == "b") return Piecetype::Bishop;
    else if (piece == "P" || piece == "p") return Piecetype::Pawn;
    else throw "invalid type";
}


Side Conversion::toSide(string piece) {
    if (piece == "K" || piece == "Q" || piece == "R" || piece == "N" || piece == "B" || piece == "P") {
        return Side::White;
    }
    else return Side::Black;
}