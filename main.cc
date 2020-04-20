#include "Scoreboard.h"
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Piecetype.h"
#include "conversion.h"
#include <string>
#include <iostream>

int main() {
    std::cout << "Main" << std::endl;
    Scoreboard* score = new Scoreboard();
    Board* board = new Board();
    Game* game;
    Side first = Side::White;

    std::string input;
    while (std::cin >> input) {
        if (input == "setup") {
            board->setup();
            board->print();
        }
        else if (input == "done") {
            board->exitSetup();
        }
        else if (input == "+") {
            std::string piece;
            std::cin >> piece;
            std::string location;
            std::cin >> location;

            //Piecetype p = get piecetype from piece string
            //Side s = get side from piece string
            //std::pair<int,int> coordinate = get coordinate from location string

            //more stuff to do here after the above comments work

        }
        else if (input == "-") {
            std::string location;
            std::cin >> location;

            //std::pair<int,int> coordinate = get coordinate from location string
            //board->setupRemove(coordinate);
            //board->print();
        }
        else if (input == "=") {
            std::string colour;
            std::cin >> colour;

            if (board->inSetup()) {
                if (colour == "black") {
                    first = Side::Black;
                }
                else if (colour == "white") {
                    first = Side::White;
                }
            }
            else {
                std::cout << "Not currently in setup" << std::endl;
            }
        }
        else if (input == "game") {
            std::string p1;
            std::string p2;
            std::cin >> p1 >> p2;

            if (board->inSetup()) {
                std::cout << "Can't start game in setup mode. Please exit setup mode first" << std::endl;
                continue;
            }

            Player* whitePlayer;
            Player* blackPlayer;

            if (p1 == "human") {
                whitePlayer = new Human(Side::White);
            }
            else if (p1 == "computer1") {
                whitePlayer = new Computer(Side::White, 1);
            }
            else if (p1 == "computer2") {
                whitePlayer = new Computer(Side::White, 2);
            }
            else if (p1 == "computer3") {
                whitePlayer = new Computer(Side::White, 3);
            }
            else {
                std::cout << "Invalid player: " << p1 << std::endl;
                continue;
            }

            if (p2 == "human") {
                blackPlayer = new Human(Side::Black);
            }
            else if (p2 == "computer1") {
                blackPlayer = new Computer(Side::Black, 1);
            }
            else if (p2 == "computer2") {
                blackPlayer = new Computer(Side::Black, 2);
            }
            else if (p2 == "computer3") {
                blackPlayer = new Computer(Side::Black, 3);
            }
            else {
                std::cout << "Invalid player: " << p2 << std::endl;
                continue;
            }

            game = new Game(board, score, whitePlayer, blackPlayer, first);
            board->print();
            game->start();
            board->resetBoard();
        }
        else {
            std::cout << "Invalid command" << std::endl;
            continue;
        }
    }
    score->printScore();
    if (game != nullptr) {
        delete game;
    }
    delete board;
    delete score;
}