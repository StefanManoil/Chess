#include "humanplayer.h"
using namespace std;

HumanPlayer::HumanPlayer(Side side): Player(side) {}


HumanPlayer::~HumanPlayer() {}


bool HumanPlayer::player_move(Board *board) override{
    // read in staring and ending coordinates
    string line;
    getline(cin, line);

    istringstream ss{line};
    string move_from, move_to;

    if  (ss >> move_from && ss >> move_to) {
        // convert string to pair<int, int>
        try{
            pair<int, int> coordinate1 = Conversion::toCoordinate(move_from);
            pair<int, int> coordinate2 = Conversion::toCoordinate(move_to);
            catch (const string *msg){
                return false;
            }
        }

        string pawn_promote;
        if  (ss >> pawn_promote) {
            // convert string to piece type
            try{
                Piecetype type = Conversion::toType(pawn_promote);
                catch (const string *msg) {
                    return false;
                }
            }

            return board->PawnPromotion(coordinate2, type, side);
        }
        return board->movePiece(coordinate1, coordinate2, side);
    }
    else return false;
}
