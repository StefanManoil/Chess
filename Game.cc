#include "Game.h"

void Game::start() {
    std::string input;
    while (std::cin >> input) {
        if (input == "move") {
            if (currentSide == Side::White) {
                if (white->player_move(board)) {
                    currentSide = Side::Black;
                }
                else {
                    std::cout << "Invalid move, try again" << std::endl;
                    continue;
                }
            }
            else if (currentSide == Side::Black) {
                if (black->player_move(board)) {
                    currentSide = Side::White;
                }
                else {
                    std::cout << "Invalid move, try again" << std::endl;
                    continue;
                }
            }

            board->print();
            //Boardstatus status = board->getStatus()
            //Check current status against each Boardstatus
            //Display appropriate message for each score
            //Increment scores if necessary
        }
    }
}