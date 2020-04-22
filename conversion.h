
#ifndef _CONVERSION_H
#define _CONVERSION_H

#include "Piecetype.h"
#include "side.h"
#include <string>

using namespace std;

class Conversion{
public:
    static pair<int, int> toCoordinate(string location);
    static Piecetype toType(string piece);
    static Side toSide(string piece);
};

#endif