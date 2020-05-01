#include "Human.h"
using namespace std;

Human::Human(Side side): Player(side) {}


Human::~Human() {}


bool Human::player_move(Board *board) {
    // read in staring and ending coordinates
    string line;
    getline(cin, line);

    istringstream ss{line};
    string move_from, move_to;
    pair<int,int> coordinate1, coordinate2;

    if  (ss >> move_from && ss >> move_to) {
        // convert string to pair<int, int>
        try{
            coordinate1 = Conversion::toCoordinate(move_from);
            coordinate2 = Conversion::toCoordinate(move_to);
        }
        catch (string msg){
            std::cout << "hit exception: " << msg << std::endl; 
            return false;
        }

        // string pawn_promote;
        // if  (ss >> pawn_promote) {
        //     // convert string to piece type
        //     try{
        //         Piecetype type = Conversion::toType(pawn_promote);
        //     }
        //     catch (const string *msg) {
        //         return false;
        //     }

        //     //return board->PawnPromotion(coordinate2, type, side);
        //     return false;
        // }
        return board->canPieceMoveToDestPos(coordinate1, coordinate2, side);
    }
    else return false;
}
