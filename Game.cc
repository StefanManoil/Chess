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

            BoardStatus boardStatus = board->getStatusBasic();
            switch (boardStatus) {
                case BoardStatus::WhiteCheck : std::cout << "White is in check." << std::endl; break;
                case BoardStatus::BlackCheck : std::cout << "Black is in check." << std::endl; break;
                case BoardStatus::WhiteCheckmate : std::cout << "Checkmate! Black wins!" << std::endl; score->winScore(Side::Black); return;
                case BoardStatus::BlackCheckmate : std::cout << "Checkmate! White wins!" << std::endl; score->winScore(Side::White); return;
                case BoardStatus::Stalemate : std::cout << "Stalemate!" << std::endl; score->winScore(Side::None); return;
                default: break;
            }

        }
        else if (input == "resign") {
            if (currentSide == Side::White) {
                std::cout << "Black wins!" << std::endl;
                score->winScore(Side::Black);
            }
            else if (currentSide == Side::Black) {
                std::cout << "White wins!" << std::endl;
                score->winScore(Side::White);
            }
            return;
        }
    }
}