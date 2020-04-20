#ifndef CONVERSION_H
#define CONVERSION_H

#include "Piecetype.h"
#include "side.h"
#include <string>
using namespace std;

class Conversion{
public:
    pair<int, int> toCoordinate(string location);
    PieceType toType(string piece);
    Side toSide(string piece);
};



#endif