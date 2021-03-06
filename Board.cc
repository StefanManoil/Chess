#include "Board.h"

bool checkMove(std::pair<int,int> dest, std::vector<std::pair<int,int>> moves) {
    for (auto move : moves) {
        if (dest.first == move.first && dest.second == move.second) {
            return true;
        }
    }
    return false;
}

BoardStatus Board::getStatus() {
    std::pair<int,int> whiteKingPos, blackKingPos;
    for (auto item : actualPosOfWhitePieces) {
        if (item.second->getType() == Piecetype::King) {
            std::cout << "Found white king" << std::endl;
            whiteKingPos = item.first;
        }
    }
    for (auto item : actualPosOfBlackPieces) {
        if (item.second->getType() == Piecetype::King) {
            std::cout << "Found black king" << std::endl;
            blackKingPos = item.first;
        }
    }

    for (auto item : actualPosOfBlackPieces) {
        if (checkMove(whiteKingPos, item.second->getMoves(this))) {
            std::cout << "Black piece can move on white king" << std::endl;
            this->currentBoardStatus = BoardStatus::WhiteCheck;
            //return BoardStatus::WhiteCheck;
        }
    }
    for (auto item : actualPosOfWhitePieces) {
        if (checkMove(blackKingPos, item.second->getMoves(this))) {
            std::cout << "White piece can move on black king" << std::endl;
            this->currentBoardStatus = BoardStatus::BlackCheck;
            //return BoardStatus::BlackCheck;
        }
    }

    if (this->currentBoardStatus == BoardStatus::WhiteCheck || this->currentBoardStatus == BoardStatus::BlackCheck) { //also check for checkmate
    
    }

    //Also need to check for checkmate

    return this->currentBoardStatus;
}

bool Board::canSideCaptureDestPos(std::pair<int, int> destPos, Side currentSide) {
    if (currentSide == Side::White) {
        for (auto item : actualPosOfWhitePieces) {
            if (item.second->getType() == Piecetype::Pawn && item.first.first == destPos.first) { //might be second not sure
                return false; //Pawn cannot capture by a straight move
            }
            else if (checkMove(destPos, item.second->getMoves(this))) {
                return true;
            }
        }
    }
    return false;
}

bool Board::getComputerMove(Side side, int diff_level) {
    std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> computerMoves;

    if (side == Side::White) {
        for (auto item : actualPosOfWhitePieces) {
            std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> moves = item.second->getComputerMove(this, diff_level);
            computerMoves.insert(computerMoves.end(), moves.begin(), moves.end());
        }
    }
    else if (side == Side::Black) {
        for (auto item : actualPosOfBlackPieces) {
            std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> moves = item.second->getComputerMove(this, diff_level);
            computerMoves.insert(computerMoves.end(), moves.begin(), moves.end());
        }
    }

    if (computerMoves.size() == 0) {
        return this->getComputerMove(side, diff_level-1);
    }
    std::pair<std::pair<int,int>, std::pair<int,int>> finalMove = computerMoves[rand() % computerMoves.size()];
    return this->canPieceMoveToDestPos(finalMove.first, finalMove.second, side);
}

BoardStatus Board::getCurrentStatusField() {
    return this->currentBoardStatus;
}

bool Board::inSetup() {
    return this->inSetupMode;
}

Piecetype Board::getTypeOfPiece(std::pair<int, int> location) {
  if (this->actualPosOfWhitePieces.count(location) > 0) {
      return this->actualPosOfWhitePieces.at(location)->getType();
  }
  if (this->actualPosOfBlackPieces.count(location) > 0) {
      return this->actualPosOfBlackPieces.at(location)->getType();
  }
  return Piecetype::NoPiece;
}

Side Board::getSideOfPiece(std::pair<int, int> location) {
  if (this->actualPosOfWhitePieces.count(location) > 0) {
      return Side::White;
  }
  if (this->actualPosOfBlackPieces.count(location) > 0) {
      return Side::Black;
  }
  return Side::None;
}

bool Board::pieceAtPosMoved(std::pair<int,int> location) {
  if (this->actualPosOfWhitePieces.count(location) > 0) {
      return this->actualPosOfWhitePieces.at(location)->hasMoved();
  }
  if (this->actualPosOfBlackPieces.count(location) > 0) {
      return this->actualPosOfBlackPieces.at(location)->hasMoved();
  }
  return false;
}


void Board::setup() {
  if (this->inSetupMode) {
    std::cout << "You are already in Setup mode." << std::endl;
  }
  else if (this->gameInProgress) {
      std::cout << "A game is in progress, cannot enter Setup mode." << std::endl;
  }
  // ^^ this may not be necessary, to discuss
  else {
    this->inSetupMode = true;
  }
}

void Board::setPieceInSetup(std::pair<int, int> pos, Side side, Piecetype piecetype) {
    if (this->inSetupMode) {
        if (piecetype == Piecetype::Rook) {
            this->removePieceInSetup(pos);
            if (side == Side::White) {
                this->actualPosOfWhitePieces.emplace(pos, new Rook(pos, false, side));
            }
            else if (side == Side::Black) {
                this->actualPosOfBlackPieces.emplace(pos, new Rook(pos, false, side));
            }
        }
        else if (piecetype == Piecetype::Knight) {
            this->removePieceInSetup(pos);
            if (side == Side::White) {
                this->actualPosOfWhitePieces.emplace(pos, new Knight(pos, false, side));
            }
            else if (side == Side::Black) {
                this->actualPosOfBlackPieces.emplace(pos, new Knight(pos, false, side));
            }
        }
        else if (piecetype == Piecetype::Bishop) {
            this->removePieceInSetup(pos);
            if (side == Side::White) {
                this->actualPosOfWhitePieces.emplace(pos, new Bishop(pos, false, side));
            }
            else if (side == Side::Black) {
                this->actualPosOfBlackPieces.emplace(pos, new Bishop(pos, false, side));
            }
        }
        else if (piecetype == Piecetype::King) {
            this->removePieceInSetup(pos);
            if (side == Side::White) {
                this->actualPosOfWhitePieces.emplace(pos, new King(pos, false, side));
            }
            else if (side == Side::Black) {
                this->actualPosOfBlackPieces.emplace(pos, new King(pos, false, side));
            }
        }
        else if (piecetype == Piecetype::Queen) {
            this->removePieceInSetup(pos);
            if (side == Side::White) {
                this->actualPosOfWhitePieces.emplace(pos, new Queen(pos, false, side));
            }
            else if (side == Side::Black) {
                this->actualPosOfBlackPieces.emplace(pos, new Queen(pos, false, side));
            }
        }
        else if (piecetype == Piecetype::Pawn) {
            this->removePieceInSetup(pos);
            if (side == Side::White) {
                this->actualPosOfWhitePieces.emplace(pos, new Pawn(pos, false, side));
            }
            else if (side == Side::Black) {
                this->actualPosOfBlackPieces.emplace(pos, new Pawn(pos, false, side));
            }
        }
    }
    else {
        std::cout << "You are not in Setup mode." << std::endl;
    }
}

void Board::removePieceInSetup(std::pair<int , int> location) {
    if (this->inSetupMode) {
        if (this->actualPosOfWhitePieces.count(location) > 0) {
            delete this->actualPosOfWhitePieces.at(location);
            this->actualPosOfWhitePieces.at(location) = nullptr;
            // delete the newly deleted piece from our actualPosPieces map
            this->actualPosOfWhitePieces.erase(location);
        }
        else if (this->actualPosOfBlackPieces.count(location) > 0) {
            delete this->actualPosOfBlackPieces.at(location);
            this->actualPosOfBlackPieces.at(location) = nullptr;
            // delete the newly deleted piece from our actualPosPieces map
            this->actualPosOfBlackPieces.erase(location);
        }
    }
    else {
        std::cout << "You are not in Setup mode." << std::endl;
    }
}

void Board::print() {
  for (int i = 0; i < 8; i++) {
      std::cout << 8 - i << " ";
      for (int j = 0; j < 8; j++) {
          std::pair<int, int> currentPair = std::make_pair(i, j);
          if (actualPosOfWhitePieces.count(currentPair) > 0) {
              std::cout << actualPosOfWhitePieces.at(currentPair)->toString(); 
          }
          else if (actualPosOfBlackPieces.count(currentPair) > 0) {
              std::cout << actualPosOfBlackPieces.at(currentPair)->toString(); 
          }
          else {
               std::cout << ((((i + j) % 2) == 0) ? " " : "-");
          }
      }
      std::cout << std::endl;
  }
  std::cout << std::endl << "  abcdefgh" << std::endl << std::endl;
}

void Board::exitSetup(){
  if (this->inSetupMode) {
      bool foundBlackKing = false;
      bool foundWhiteKing = false;
      for (const auto& posPiecePair: this->actualPosOfWhitePieces) {
          if (posPiecePair.second->getType() == Piecetype::King) {
                if (foundWhiteKing) {
                    std::cout << "Found more than one white king, you cannot exit Setup mode." << std::endl;
                    return;
                }
                else {
                      foundWhiteKing = true;
                }
          }
      }
      for (const auto& posPiecePair: this->actualPosOfBlackPieces) {
          if (posPiecePair.second->getType() == Piecetype::King) {
                if (foundBlackKing) {
                    std::cout << "Found more than one black king, you cannot exit Setup mode." << std::endl;
                    return;
                }
                else {
                      foundBlackKing = true;
                }
          }
      }
      if (!foundBlackKing) {
          std::cout << "Did not find a black king, you cannot exit Setup mode." << std::endl;
          return;
      }
      if (!foundWhiteKing) {
          std::cout << "Did not find a white king, you cannot exit Setup mode." << std::endl;
          return;
      }
      for (const auto& posPiecePair: this->actualPosOfWhitePieces) {
          if (posPiecePair.first.first == 0) {
              if (posPiecePair.second->getType() == Piecetype::Pawn) {
                  std::cout << "Pawn is in first row, you cannot exit Setup mode." << std::endl;
                  return;
              }
          }
          else if (posPiecePair.first.first == 7) {
              if (posPiecePair.second->getType() == Piecetype::Pawn) {
                  std::cout << "Pawn is in last row, you cannot exit Setup mode." << std::endl;
                  return;
              }
          }
      }
      for (const auto& posPiecePair: this->actualPosOfBlackPieces) {
          if (posPiecePair.first.first == 0) {
              if (posPiecePair.second->getType() == Piecetype::Pawn) {
                  std::cout << "Pawn is in first row, you cannot exit Setup mode." << std::endl;
                  return;
              }
          }
          else if (posPiecePair.first.first == 7) {
              if (posPiecePair.second->getType() == Piecetype::Pawn) {
                  std::cout << "Pawn is in last row, you cannot exit Setup mode." << std::endl;
                  return;
              }
          }
      }
      BoardStatus currentStatus = this->getStatusBasic();
      if (currentStatus == BoardStatus::BlackCheck) {
          std::cout << "Black king is in check, you cannot exit Setup mode." << std::endl;
          return;
      }
      else if (currentStatus == BoardStatus::WhiteCheck) {
          std::cout << "White king is in check, you cannot exit Setup mode." << std::endl;
          return;
      }
      this->inSetupMode = false;
  }
  else {
      std::cout << "You are not in Setup mode." << std::endl; 
  }
}

BoardStatus Board::getStatusBasic() {
    for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
        if (posPiecePairBlacks.second->getType() == Piecetype::King) {
            for (auto posPiecePairWhites : actualPosOfWhitePieces) {
                std::vector<std::pair<int,int>> moves = posPiecePairWhites.second->getMoves(this);
                for (int i = 0; i < moves.size(); i++) {
                    if (moves.at(i).first == posPiecePairBlacks.first.first
                        && moves.at(i).second == posPiecePairBlacks.first.second) {
                        return BoardStatus::BlackCheck;
                    }
                }
            }
        }
    }
    for (const auto& posPiecePairWhites : actualPosOfWhitePieces) {
        if (posPiecePairWhites.second->getType() == Piecetype::King) {
            for (auto posPiecePairBlacks : actualPosOfBlackPieces) {
                std::vector<std::pair<int,int>> moves = posPiecePairBlacks.second->getMoves(this);
                for (int i = 0; i < moves.size(); i++) {
                    if (moves.at(i).first == posPiecePairWhites.first.first
                        && moves.at(i).second == posPiecePairWhites.first.second) {
                        return BoardStatus::WhiteCheck;
                    }
                }
            }
        }
    }
    return BoardStatus::Normal;
}

void Board::resetBoard() {
    for (auto& posPiecePair : this->actualPosOfBlackPieces) {
        delete posPiecePair.second;
        posPiecePair.second = nullptr;
    }
    this->actualPosOfBlackPieces.clear();
    for (auto& posPiecePair : this->actualPosOfWhitePieces) {
        delete posPiecePair.second;
        posPiecePair.second = nullptr;
    }
    this->actualPosOfWhitePieces.clear();
    // make black first row
    this->actualPosOfBlackPieces.emplace(std::make_pair(0, 0), new Rook(std::make_pair(0, 0), false, Side::Black));
    this->actualPosOfBlackPieces.emplace(std::make_pair(0, 1), new Knight(std::make_pair(0, 1), false, Side::Black));
    this->actualPosOfBlackPieces.emplace(std::make_pair(0, 2), new Bishop(std::make_pair(0, 2), false, Side::Black));
    this->actualPosOfBlackPieces.emplace(std::make_pair(0, 3), new Queen(std::make_pair(0, 3), false, Side::Black));
    this->actualPosOfBlackPieces.emplace(std::make_pair(0, 4), new King(std::make_pair(0, 4), false, Side::Black));
    this->actualPosOfBlackPieces.emplace(std::make_pair(0, 5), new Bishop(std::make_pair(0, 5), false, Side::Black));
    this->actualPosOfBlackPieces.emplace(std::make_pair(0, 6), new Knight(std::make_pair(0, 6), false, Side::Black));
    this->actualPosOfBlackPieces.emplace(std::make_pair(0, 7), new Rook(std::make_pair(0, 7), false, Side::Black));
    // make black pawn row
    for (int i = 0; i < 8; i++) {
        this->actualPosOfBlackPieces.emplace(std::make_pair(1, i), new Pawn(std::make_pair(1, i), false, Side::Black));
    }
    // make white pawn row
    for (int i = 0; i < 8; i++) {
        this->actualPosOfWhitePieces.emplace(std::make_pair(6, i), new Pawn(std::make_pair(6, i), false, Side::White));
    }
    // make white last row
    this->actualPosOfWhitePieces.emplace(std::make_pair(7, 0), new Rook(std::make_pair(7, 0), false, Side::White));
    this->actualPosOfWhitePieces.emplace(std::make_pair(7, 1), new Knight(std::make_pair(7, 1), false, Side::White));
    this->actualPosOfWhitePieces.emplace(std::make_pair(7, 2), new Bishop(std::make_pair(7, 2), false, Side::White));
    this->actualPosOfWhitePieces.emplace(std::make_pair(7, 3), new Queen(std::make_pair(7, 3), false, Side::White));
    this->actualPosOfWhitePieces.emplace(std::make_pair(7, 4), new King(std::make_pair(7, 4), false, Side::White));
    this->actualPosOfWhitePieces.emplace(std::make_pair(7, 5), new Bishop(std::make_pair(7, 5), false, Side::White));
    this->actualPosOfWhitePieces.emplace(std::make_pair(7, 6), new Knight(std::make_pair(7, 6), false, Side::White));
    this->actualPosOfWhitePieces.emplace(std::make_pair(7, 7), new Rook(std::make_pair(7, 7), false, Side::White));
}

BoardStatus Board::getStatusField() {
    return this->currentBoardStatus;
}

BoardStatus Board::getStatusOfCurrentSide(Side currentSide) {
    if (currentSide == Side::White) {
        for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
            if (posPiecePairWhites.second->getType() == Piecetype::King) {
                for (const auto& posPiecePairBlacks : actualPosOfBlackPieces) {
                    for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                        if (posPiecePairBlacks.second->getMoves(this).at(i) == posPiecePairWhites.first) {
                            return BoardStatus::WhiteCheck;
                        }
                    }
                }
            }
        }
    }
    else if (currentSide == Side::Black) {
        for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
            if (posPiecePairBlacks.second->getType() == Piecetype::King) {
                for (const auto& posPiecePairWhites : actualPosOfWhitePieces) {
                    for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                        if (posPiecePairWhites.second->getMoves(this).at(i) == posPiecePairBlacks.first) {
                            return BoardStatus::BlackCheck;
                        }
                    }
                }
            }
        }
    }
    return BoardStatus::Normal;
}

bool Board::canKingInCheckMoveToSafePos(Side currentSide) {
    if (currentSide == Side::White) {
        for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
            if (posPiecePairWhites.second->getType() == Piecetype::King) {
                int countOfMoves = posPiecePairWhites.second->getMoves(this).size();
                for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                    for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
                        for (int j = 0; j < posPiecePairBlacks.second->getMoves(this).size(); j++) {
                            if (posPiecePairBlacks.second->getMoves(this).at(j) == 
                                posPiecePairWhites.second->getMoves(this).at(i)) {
                                    countOfMoves--;
                                    if (countOfMoves <= 0) return false;
                                }
                        }
                    }
                }
            }
        }
    }
    else if (currentSide == Side::Black) {
        for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
            if (posPiecePairBlacks.second->getType() == Piecetype::King) {
                int countOfMoves = posPiecePairBlacks.second->getMoves(this).size();
                for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                    for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
                        for (int j = 0; j < posPiecePairWhites.second->getMoves(this).size(); j++) {
                            if (posPiecePairWhites.second->getMoves(this).at(j) == 
                                posPiecePairBlacks.second->getMoves(this).at(i)) {
                                    countOfMoves--;
                                    if (countOfMoves <= 0) return false;
                                }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Board::canFriendlyPiecesBlockEnemyPieces(Side currentSide) {
    // If we have a double check or more, we know there is no chance to stop
    // all the attacks by blocking, so we rely on our previous work of checking
    // if the king can move itself out of the check.
    if (currentSide == Side::White) {
        std::vector<std::pair<int, int>> attackingPieceMovesNotIncludingFriendlyKing;
        for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
            if (posPiecePairWhites.second->getType() == Piecetype::King) {
                std::vector<Piece*> attackingPieces;
                for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
                    for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                        if (posPiecePairBlacks.second->getMoves(this).at(i) == posPiecePairWhites.first) {
                            attackingPieces.emplace_back(posPiecePairBlacks.second);
                        }
                    }
                }
                if (attackingPieces.size() > 1) {
                    for (int i = 0; i < attackingPieces.size(); i++) {
                        attackingPieces.at(i) = nullptr;
                    }
                    attackingPieces.clear();
                    return false;
                }
                for (int i = 0; i < attackingPieces.at(0)->getMoves(this).size(); i++) {
                    if (attackingPieces.at(0)->getMoves(this).at(i) != posPiecePairWhites.first) {
                        attackingPieceMovesNotIncludingFriendlyKing.emplace_back(attackingPieces.at(0)->getMoves(this).at(i));
                    }
                }
            }
        }
        for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
            for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                for (int j = 0; j < attackingPieceMovesNotIncludingFriendlyKing.size(); j++) {
                    if (posPiecePairWhites.second->getMoves(this).at(i) == 
                        attackingPieceMovesNotIncludingFriendlyKing.at(j)) {
                            return true;
                    }
                }
            }
        }
    }
    else if (currentSide == Side::Black) {
        std::vector<std::pair<int, int>> attackingPieceMovesNotIncludingFriendlyKing;
        for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
            if (posPiecePairBlacks.second->getType() == Piecetype::King) {
                std::vector<Piece*> attackingPieces;
                for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
                    for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                        if (posPiecePairWhites.second->getMoves(this).at(i) == posPiecePairBlacks.first) {
                            attackingPieces.emplace_back(posPiecePairWhites.second);
                        }
                    }
                }
                if (attackingPieces.size() > 1) {
                    for (int i = 0; i < attackingPieces.size(); i++) {
                        attackingPieces.at(i) = nullptr;
                    }
                    attackingPieces.clear();
                    return false;
                }
                for (int i = 0; i < attackingPieces.at(0)->getMoves(this).size(); i++) {
                    if (attackingPieces.at(0)->getMoves(this).at(i) != posPiecePairBlacks.first) {
                        attackingPieceMovesNotIncludingFriendlyKing.emplace_back(attackingPieces.at(0)->getMoves(this).at(i));
                    }
                }
            }
        }
        for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
            for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                for (int j = 0; j < attackingPieceMovesNotIncludingFriendlyKing.size(); j++) {
                    if (posPiecePairBlacks.second->getMoves(this).at(i) == 
                        attackingPieceMovesNotIncludingFriendlyKing.at(j)) {
                            return true;
                    }
                }
            }
        }
    }
    return false; 
}

bool Board::canFriendlyPiecesDestroyEnemyAttackingKing(Side currentSide) {
    // If we have a double check or more, we know there is no chance to stop
    // all the attacks as we can only kill one attacking piece on white's one turn, so we rely on our previous work of checking
    // if the king can move itself out of the check.
    if (currentSide == Side::White) {
        std::pair<int, int> attackingPieceLocation;
        for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
            if (posPiecePairWhites.second->getType() == Piecetype::King) {
                std::vector<Piece*> attackingPieces;
                for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
                    for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                        if (posPiecePairBlacks.second->getMoves(this).at(i) == posPiecePairWhites.first) {
                            attackingPieces.emplace_back(posPiecePairBlacks.second);
                        }
                    }
                }
                if (attackingPieces.size() > 1) {
                    for (int i = 0; i < attackingPieces.size(); i++) {
                        attackingPieces.at(i) = nullptr;
                    }
                    attackingPieces.clear();
                    return false;
                }
            }
        }
        for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
            for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                if (posPiecePairWhites.second->getMoves(this).at(i) == attackingPieceLocation) {
                    return true;
                }
            }
        }
    }
    else if (currentSide == Side::Black) {
        std::pair<int, int> attackingPieceLocation;
        for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
            if (posPiecePairBlacks.second->getType() == Piecetype::King) {
                std::vector<Piece*> attackingPieces;
                for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
                    for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                        if (posPiecePairWhites.second->getMoves(this).at(i) == posPiecePairBlacks.first) {
                            attackingPieces.emplace_back(posPiecePairWhites.second);
                        }
                    }
                }
                if (attackingPieces.size() > 1) {
                    for (int i = 0; i < attackingPieces.size(); i++) {
                        attackingPieces.at(i) = nullptr;
                    }
                    attackingPieces.clear();
                    return false;
                }
            }
        }
        for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
            for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                if (posPiecePairBlacks.second->getMoves(this).at(i) == attackingPieceLocation) {
                    return true;
                }
            }
        }
    }
    return false;
}

// BoardStatus Board::getStatusAfterMove(std::pair<int,int> currPos, std::pair<int,int> destPos) {
//     Side side = this->getSideOfPiece(currPos);
//     Piecetype p = this->getTypeOfPiece(currPos);
//     if (side == Side::White) {
//         switch (p) {
//             case Piecetype::Pawn : this->actualPosOfWhitePieces.emplace(destPos, new Pawn(destPos, Side::White)); break;
//             case Piecetype::Bishop : this->actualPosOfWhitePieces.emplace(destPos, new Bishop)
//             case Piecetype::King :
//             case Piecetype::Knight :
//             case Piecetype::Queen :
//             case Piecetype::Rook : 
//         }
//     }
//     else if (side == Side::Black) {

//     }
// }

bool Board::willMoveRenderSideInCheck(Side currentSide, std::pair<int, int> currentPos, std::pair<int, int> destPos) {
    if (currentSide == Side::White) {
        bool hasPieceMoved = this->actualPosOfWhitePieces.at(currentPos)->hasMoved();
        if (this->actualPosOfWhitePieces.at(currentPos)->getType() == Piecetype::King) {
            this->actualPosOfWhitePieces.emplace(destPos, new King(destPos, true, Side::White));
            delete this->actualPosOfWhitePieces.at(currentPos);
            this->actualPosOfWhitePieces.at(currentPos) = nullptr;
            this->actualPosOfWhitePieces.erase(currentPos);
            for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
                for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                    if (posPiecePairBlacks.second->getMoves(this).at(i) == destPos) {
                        std::cout << "WhiteKingMoveRenderSideInCheck" << std::endl;
                        return true; // One of the enemy pieces has a move that can check the proposed positon of friendly king
                    }
                }
            }
            delete this->actualPosOfWhitePieces.at(destPos);
            this->actualPosOfWhitePieces.at(destPos) = nullptr;
            this->actualPosOfWhitePieces.erase(destPos);
            this->actualPosOfWhitePieces.emplace(currentPos, new King(currentPos, hasPieceMoved, Side::White));
            // ^^ should moved flag be what it is 
        }
        else {
            Piecetype typeOfPieceAtCurrentPos = this->actualPosOfWhitePieces.at(currentPos)->getType();
            if (typeOfPieceAtCurrentPos == Piecetype::Rook) {
                this->actualPosOfWhitePieces.emplace(destPos, new Rook(destPos, true, Side::White));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Knight) {
                this->actualPosOfWhitePieces.emplace(destPos, new Knight(destPos, true, Side::White));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Bishop) {
                this->actualPosOfWhitePieces.emplace(destPos, new Bishop(destPos, true, Side::White));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Queen) {
                this->actualPosOfWhitePieces.emplace(destPos, new Queen(destPos, true, Side::White));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Pawn) {
                this->actualPosOfWhitePieces.emplace(destPos, new Pawn(destPos, true, Side::White));
            }
            delete this->actualPosOfWhitePieces.at(currentPos);
            this->actualPosOfWhitePieces.at(currentPos) = nullptr;
            this->actualPosOfWhitePieces.erase(currentPos);
            // find the friendly king
            std::pair<int, int> friendlyKingPos;
            for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
                if (posPiecePairWhites.second->getType() == Piecetype::King) {
                    friendlyKingPos = posPiecePairWhites.first;
                }
            }
            for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
                for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                    if (posPiecePairBlacks.second->getMoves(this).at(i) == friendlyKingPos) {
                        std::cout << "WhiteNotKingMoveRenderSideInCheck" << std::endl;
                        return true; // One of the enemy pieces has a move that can check the positon of friendly king
                    }
                }
            }
            delete this->actualPosOfWhitePieces.at(destPos);
            this->actualPosOfWhitePieces.at(destPos) = nullptr;
            this->actualPosOfWhitePieces.erase(destPos);
            if (typeOfPieceAtCurrentPos == Piecetype::Rook) {
              this->actualPosOfWhitePieces.emplace(currentPos, new Rook(currentPos, hasPieceMoved, Side::White));
              // ^^ should moved flag be what it is
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Knight) {
              this->actualPosOfWhitePieces.emplace(currentPos, new Knight(currentPos, hasPieceMoved, Side::White));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Bishop) {
              this->actualPosOfWhitePieces.emplace(currentPos, new Bishop(currentPos, hasPieceMoved, Side::White));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Queen) {
              this->actualPosOfWhitePieces.emplace(currentPos, new Queen(currentPos, hasPieceMoved, Side::White));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Pawn) {
              this->actualPosOfWhitePieces.emplace(currentPos, new Pawn(currentPos, hasPieceMoved, Side::White));
            }
        }
    }
    else if (currentSide == Side::Black) {
        bool hasPieceMoved = this->actualPosOfBlackPieces.at(currentPos)->hasMoved();
        if (this->actualPosOfBlackPieces.at(currentPos)->getType() == Piecetype::King) {
            this->actualPosOfBlackPieces.emplace(destPos, new King(destPos, true, Side::Black));
            delete this->actualPosOfBlackPieces.at(currentPos);
            this->actualPosOfBlackPieces.at(currentPos) = nullptr;
            this->actualPosOfBlackPieces.erase(currentPos);
            for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
                for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                    if (posPiecePairWhites.second->getMoves(this).at(i) == destPos) {
                        std::cout << "BlackKingMoveRenderSideInCheck" << std::endl;
                        return true; // One of the enemy pieces has a move that can check the proposed positon of friendly king
                    }
                }
            }
            delete this->actualPosOfBlackPieces.at(destPos);
            this->actualPosOfBlackPieces.at(destPos) = nullptr;
            this->actualPosOfBlackPieces.erase(destPos);
            this->actualPosOfBlackPieces.emplace(currentPos, new King(currentPos, hasPieceMoved, Side::Black));
            // ^^ should moved flag be what it is
        }
        else {
            Piecetype typeOfPieceAtCurrentPos = this->actualPosOfBlackPieces.at(currentPos)->getType();
            if (typeOfPieceAtCurrentPos == Piecetype::Rook) {
                this->actualPosOfBlackPieces.emplace(destPos, new Rook(destPos, true, Side::Black));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Knight) {
                this->actualPosOfBlackPieces.emplace(destPos, new Knight(destPos, true, Side::Black));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Bishop) {
                this->actualPosOfBlackPieces.emplace(destPos, new Bishop(destPos, true, Side::Black));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Queen) {
                this->actualPosOfBlackPieces.emplace(destPos, new Queen(destPos, true, Side::Black));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Pawn) {
                this->actualPosOfBlackPieces.emplace(destPos, new Pawn(destPos, true, Side::Black));
            }
            delete this->actualPosOfBlackPieces.at(currentPos);
            this->actualPosOfBlackPieces.at(currentPos) = nullptr;
            this->actualPosOfBlackPieces.erase(currentPos);
            // find the friendly king
            std::pair<int, int> friendlyKingPos;
            for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
                if (posPiecePairBlacks.second->getType() == Piecetype::King) {
                    friendlyKingPos = posPiecePairBlacks.first;
                }
            }
            for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
                for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                    if (posPiecePairWhites.second->getMoves(this).at(i) == friendlyKingPos) {
                        std::cout << "WhiteNotKingMoveRenderSideInCheck" << std::endl;
                        return true; // One of the enemy pieces has a move that can check the positon of friendly king
                    }
                }
            }
            //
            delete this->actualPosOfBlackPieces.at(destPos);
            this->actualPosOfBlackPieces.at(destPos) = nullptr;
            this->actualPosOfBlackPieces.erase(destPos);
            if (typeOfPieceAtCurrentPos == Piecetype::Rook) {
                this->actualPosOfBlackPieces.emplace(currentPos, new Rook(currentPos, hasPieceMoved, Side::Black));
                // ^^ should moved flag be what it is
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Knight) {
                this->actualPosOfBlackPieces.emplace(currentPos, new Knight(currentPos, hasPieceMoved, Side::Black));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Bishop) {
                this->actualPosOfBlackPieces.emplace(currentPos, new Bishop(currentPos, hasPieceMoved, Side::Black));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Queen) {
                this->actualPosOfBlackPieces.emplace(currentPos, new Queen(currentPos, hasPieceMoved, Side::Black));
            }
            else if (typeOfPieceAtCurrentPos == Piecetype::Pawn) {
                this->actualPosOfBlackPieces.emplace(currentPos, new Pawn(currentPos, hasPieceMoved, Side::Black));
            }
        }
    }
    return false;
}

bool Board::doesSideHaveMovesLeft(Side currentSide) {
  std::cout << "Does Side has moves left" << std::endl;
    if (currentSide == Side::White) {
        for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
            for (int i = 0; i < posPiecePairWhites.second->getMoves(this).size(); i++) {
                if (this->willMoveRenderSideInCheck
                   (Side::White, posPiecePairWhites.first, posPiecePairWhites.second->getMoves(this).at(i)) == false) {
                       return true;
                }
            }
        }
    }
    else if (currentSide == Side::Black) {
        for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
            for (int i = 0; i < posPiecePairBlacks.second->getMoves(this).size(); i++) {
                if (this->willMoveRenderSideInCheck
                   (Side::Black, posPiecePairBlacks.first, posPiecePairBlacks.second->getMoves(this).at(i)) == false) {
                       return true;
                }
            }
        }
    }
    std::cout << "false doesSideHaveMovesLeft" << std::endl;
    return false;
}

bool Board::isValidMove(std::pair<int,int> from, std::pair<int,int> to, Side side) {
    std::vector<std::pair<int,int>> moves;
    if (side == Side::White) {
        if (this->actualPosOfWhitePieces.count(from) > 0) {
            Piece* p = this->actualPosOfWhitePieces.at(from);
            moves = p->getMoves(this);
            for (auto move : moves) {
                if (move.first == to.first && move.second == to.second) {
                    return true;
                }
            }
            return false;
        }
    }
    else if (side == Side::Black) {
        try {
            Piece* p = this->actualPosOfBlackPieces.at(from);
            moves = p->getMoves(this);
            for (auto move : moves) {
                if (move.first == to.first && move.second == to.second) {
                    return true;
                }
            }
            return false;
        }
        catch (const std::string* e) {
            return false;
        }
    }
    return false;
}

bool Board::isValidCurrentPos(std::pair<int, int> currentPos, Side currentSide) {
    if (currentSide == Side::White) {
      std::cout << "currentPos: " << currentPos.first << "," << currentPos.second << std::endl;
        for (auto posPiecePairWhites : this->actualPosOfWhitePieces) {
            std::cout << "posPiecePairWhites:: " << posPiecePairWhites.first.first << "," << posPiecePairWhites.first.second << std::endl; 
            if (posPiecePairWhites.first.first == currentPos.first && posPiecePairWhites.first.second == currentPos.second) {
                return true;
            }
        }
    }
    else if (currentSide == Side::Black) {
        for (auto posPiecePairBlacks : this->actualPosOfBlackPieces) {
            if (posPiecePairBlacks.first.first == currentPos.first && posPiecePairBlacks.first.second == currentPos.second) {
                return true;
            }
        }
    }
    return false;
}

bool Board::isValidDestPos(std::pair<int, int> currentPos, std::pair<int, int> destPos, Side currentSide) {
    if (currentSide == Side::White) {
        for (int i = 0; i < this->actualPosOfWhitePieces.at(currentPos)->getMoves(this).size(); i++) {
            if (this->actualPosOfWhitePieces.at(currentPos)->getMoves(this).at(i) == destPos) {
                return true;
            }
        }
    }
    else if (currentSide == Side::Black) {
        for (int i = 0; i < this->actualPosOfBlackPieces.at(currentPos)->getMoves(this).size(); i++) {
            if (this->actualPosOfBlackPieces.at(currentPos)->getMoves(this).at(i) == destPos) {
                return true;
            }
        }
        
    }
    return false;
}

bool Board::isCapturingMove(std::pair<int, int> currentPos, std::pair<int, int> destPos, Side currentSide) {
    if (currentSide == Side::White) {
        for (const auto& posPiecePairBlacks : this->actualPosOfBlackPieces) {
            if (posPiecePairBlacks.first == destPos) {
                return this->isValidDestPos(currentPos, destPos, currentSide);
            }
        }
    }
    else if (currentSide == Side::Black) {
        for (const auto& posPiecePairWhites : this->actualPosOfWhitePieces) {
            if (posPiecePairWhites.first == destPos) {
                return this->isValidDestPos(currentPos, destPos, currentSide);
            }
        }
    }
    return false;
}

void Board::captureMove(std::pair<int, int> currentPos, std::pair<int, int> destPos, Side currentSide) {
    if (currentSide == Side::White) {
        Piecetype typeOfPieceAtCurrentPos = this->actualPosOfWhitePieces.at(currentPos)->getType();
        // Simulate capturing of enemy piece by destroying the friendly piece at the currentPos,
        // then destroying the enemy piece at destPos, then creating the same friendly piece
        // at destPos.
        // Delete friendly piece at currentPos (moving)
        delete this->actualPosOfWhitePieces.at(currentPos);
        this->actualPosOfWhitePieces.at(currentPos) = nullptr;
        this->actualPosOfWhitePieces.erase(currentPos);
        // Delete enemy piece at destPos (destroyed)
        delete this->actualPosOfBlackPieces.at(destPos);
        this->actualPosOfBlackPieces.at(destPos) = nullptr;
        this->actualPosOfBlackPieces.erase(destPos);
        // Create the same friendly piece at destPos (movement finished)
        if (typeOfPieceAtCurrentPos == Piecetype::Rook) {
            this->actualPosOfWhitePieces.emplace(destPos, new Rook(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Knight) {
            this->actualPosOfWhitePieces.emplace(destPos, new Knight(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Bishop) {
            this->actualPosOfWhitePieces.emplace(destPos, new Bishop(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::King) {
            this->actualPosOfWhitePieces.emplace(destPos, new King(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Queen) {
            this->actualPosOfWhitePieces.emplace(destPos, new Queen(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Pawn) {
            this->actualPosOfWhitePieces.emplace(destPos, new Pawn(destPos, true, Side::White));
        }
    }
    else if (currentSide == Side::Black) {
        Piecetype typeOfPieceAtCurrentPos = this->actualPosOfBlackPieces.at(currentPos)->getType();
        // Simulate capturing of enemy piece by destroying the friendly piece at the currentPos,
        // then destroying the enemy piece at destPos, then creating the same friendly piece
        // at destPos.
        // Delete friendly piece at currentPos (moving)
        delete this->actualPosOfBlackPieces.at(currentPos);
        this->actualPosOfBlackPieces.at(currentPos) = nullptr;
        this->actualPosOfBlackPieces.erase(currentPos);
        // Delete enemy piece at destPos (destroyed)
        delete this->actualPosOfWhitePieces.at(destPos);
        this->actualPosOfWhitePieces.at(destPos) = nullptr;
        this->actualPosOfWhitePieces.erase(destPos);
        // Create the same friendly piece at destPos (movement finished)
        if (typeOfPieceAtCurrentPos == Piecetype::Rook) {
            this->actualPosOfBlackPieces.emplace(destPos, new Rook(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Knight) {
            this->actualPosOfBlackPieces.emplace(destPos, new Knight(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Bishop) {
            this->actualPosOfBlackPieces.emplace(destPos, new Bishop(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::King) {
            this->actualPosOfBlackPieces.emplace(destPos, new King(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Queen) {
            this->actualPosOfBlackPieces.emplace(destPos, new Queen(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Pawn) {
            this->actualPosOfBlackPieces.emplace(destPos, new Pawn(destPos, true, Side::Black));
        }
    }
}

void Board::emptyMove(std::pair<int, int> currentPos, std::pair<int, int> destPos, Side currentSide) {
    if (currentSide == Side::White) {
        Piecetype typeOfPieceAtCurrentPos = this->actualPosOfWhitePieces.at(currentPos)->getType();
        // Simulate movement of friendly piece onto empty pos by destroying the friendly piece at the currentPos,
        // then creating the same friendly piece at destPos.

        // Delete friendly piece at currentPos (moving)
        delete this->actualPosOfWhitePieces.at(currentPos);
        this->actualPosOfWhitePieces.at(currentPos) = nullptr;
        this->actualPosOfWhitePieces.erase(currentPos);
        // Create the same friendly piece at destPos (movement finished)
        if (typeOfPieceAtCurrentPos == Piecetype::Rook) {
            this->actualPosOfWhitePieces.emplace(destPos, new Rook(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Knight) {
            this->actualPosOfWhitePieces.emplace(destPos, new Knight(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Bishop) {
            this->actualPosOfWhitePieces.emplace(destPos, new Bishop(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::King) {
            this->actualPosOfWhitePieces.emplace(destPos, new King(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Queen) {
            this->actualPosOfWhitePieces.emplace(destPos, new Queen(destPos, true, Side::White));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Pawn) {
            this->actualPosOfWhitePieces.emplace(destPos, new Pawn(destPos, true, Side::White));
        }
    }
    else if (currentSide == Side::Black) {
        Piecetype typeOfPieceAtCurrentPos = this->actualPosOfBlackPieces.at(currentPos)->getType();
        // Simulate movement of friendly piece onto empty pos by destroying the friendly piece at the currentPos,
        // then creating the same friendly piece at destPos.

        // Delete friendly piece at currentPos (moving)
        delete this->actualPosOfBlackPieces.at(currentPos);
        this->actualPosOfBlackPieces.at(currentPos) = nullptr;
        this->actualPosOfBlackPieces.erase(currentPos);
        // Create the same friendly piece at destPos (movement finished)
        if (typeOfPieceAtCurrentPos == Piecetype::Rook) {
            this->actualPosOfBlackPieces.emplace(destPos, new Rook(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Knight) {
            this->actualPosOfBlackPieces.emplace(destPos, new Knight(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Bishop) {
            this->actualPosOfBlackPieces.emplace(destPos, new Bishop(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::King) {
            this->actualPosOfBlackPieces.emplace(destPos, new King(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Queen) {
            this->actualPosOfBlackPieces.emplace(destPos, new Queen(destPos, true, Side::Black));
        }
        else if (typeOfPieceAtCurrentPos == Piecetype::Pawn) {
            this->actualPosOfBlackPieces.emplace(destPos, new Pawn(destPos, true, Side::Black));
        }
    }
}

bool Board::canPieceMoveToDestPos(std::pair<int, int> currentPos, std::pair<int, int> destPos, Side currentSide) {
  std::cout << "Reached canPieceMoveToDestPos" << std::endl;
  if (currentSide == Side::White) {
    std::cout << "Current Side is White" << std::endl;
  }
  else if (currentSide == Side::Black){
    std::cout << "Current Side is Black" << std::endl;
  }
    // maybe keep a vector of the moves the piece at the currentPos can make
    // restrict it further based on checks
    // see if this vector contains destPos and only then will the move be valid and return true
    // the side currently playing is the white side
    if (this->getStatusOfCurrentSide(currentSide) == BoardStatus::WhiteCheck
        || this->getStatusOfCurrentSide(currentSide) == BoardStatus::BlackCheck) {
        bool canKingMoveToSafePos;
        bool canPiecesBlockEnemyPieces;
        bool canPiecesDestroyEnemyPiecesAttackingKing;
        // The playing white side is under attack and white player cannot just do whatever it wants
        // White player must be restricted to certain moves to make its king get out of check, either:
        // 1) White king can move to a safe location that won't render it in check anymore, what this means more specifically
        //    is that the white king's possible moves have at least 1 position where if the king was there it would
        //    not be in check anymore (attackable by none of the black pieces).
        // 
        // 2) One of white's pieces can move in to block the oncoming attack, what this means more specifically
        //    is that at least one of white's pieces potential moves is a position where it would block the attack
        //    of all possible black's pieces that currently have the white king in check. Note it must block all attacks,
        //    say that there are two or more black pieces that currently have white king in check, if white has a piece that only
        //    blocks some of the attacks but there is still even only one black piece that can attack the white king, then this
        //    is not a valid option.
        //
        // 3) One of white's pieces can attack and kill the black piece that is placing the white king in check.
        //    Note this only works if there is only one black piece that is putting the white king in check, otherwise
        //    the white king will inevitably be in a checkmate. More specifically, go through the black pieces and see if there is only one
        //    black piece that puts the white king in check, if there is more than one, this strategy won't work.
        //    If there is indeed only one black piece, then we remember this piece's location and then go through all our white
        //    pieces and see if any of their moves is equivalent/can attack the black piece.

        // 1)
        std::cout << "Black or White Check" << std::endl;
        canKingMoveToSafePos = this->canKingInCheckMoveToSafePos(currentSide);
        std::cout << "Made past canKingInCheckMoveToSafePos" << std::endl;
        canPiecesBlockEnemyPieces = this->canFriendlyPiecesBlockEnemyPieces(currentSide);
        std::cout << "Made past canFriendlyPiecesBlockEnemyPieces" << std::endl;
        canPiecesDestroyEnemyPiecesAttackingKing = this->canFriendlyPiecesDestroyEnemyAttackingKing(currentSide);
        std::cout << "Made past canFriendlyPiecesDestroyEnemyAttackingKing" << std::endl;
        if (!canKingMoveToSafePos && !canPiecesBlockEnemyPieces && !canPiecesDestroyEnemyPiecesAttackingKing) {
            if (currentSide == Side::White) {
                this->currentBoardStatus = BoardStatus::WhiteCheckmate;
                return false;
            }
            else if (currentSide == Side::Black) {
                this->currentBoardStatus = BoardStatus::BlackCheckmate;
                return false;
            }
        }
        // If all of these situations fail, then white is in Checkmate and black has won the game
    }
    // If white is not in check it can kinda move wherever it wants, but maybe it can't?
    // Where to handle Stalemate is the question, I think here we will check if there is a potential 
    // Stalemate. By defn, a Stalemate occurs when both sides are not in check and none of the 
    // remaining pieces of either side has any legal moves available.
    // So here we will check that all of white's pieces have legal moves available which means
    // we will go through all of white's pieces and make sure there are available moves that does not render the white
    // king in check. If there is no available moves, this means that the white player has no available
    // moves left and we can set some sort of bool such as whiteSideNoMoves to true.
    // Thus we can return false as the white player's move cannot be made and when it is the opposition's
    // turn they can check the same thing as well as if whiteSideNoMoves is true and if so,
    // we have reached a Stalemate.
    std::cout << "one" << std::endl;
    if (currentSide == Side::White) {
      std::cout << "White side has moves left" << std::endl;
        this->whiteSideNoMoves = !(this->doesSideHaveMovesLeft(currentSide));
        if (this->blackSideNoMoves && this->whiteSideNoMoves) {
            this->currentBoardStatus = BoardStatus::Stalemate;
            std::cout << "StalemateWhitesTurn" << std::endl;
            return false;
        }
    }
    else if (currentSide == Side::Black) {
      std::cout << "Black side has moves left" << std::endl;
        this->blackSideNoMoves = !(this->doesSideHaveMovesLeft(currentSide));
        if (this->whiteSideNoMoves && this->blackSideNoMoves) {
            this->currentBoardStatus = BoardStatus::Stalemate;
            std::cout << "StalemateBlacksTurn" << std::endl;
            return false;
        }
    }
    std::cout << "two" << std::endl;
    // Check if the currentPos of the move is valid

    // if(this->isValidMove(currentPos, destPos, currentSide)) {
    //     return true;
    // }
    if (!this->isValidCurrentPos(currentPos, currentSide)) {
      std::cout << "Not Valid currentPos" << std::endl;
      return false;
    }
    // Check if the destPos of the move is valid
    if (!this->isValidDestPos(currentPos, destPos, currentSide)) {
      std::cout << "Not Valid destPos" << std::endl;
      return false;
    }
    std::cout << "three" << std::endl;
    // Based on the move white wants to make, we must check if the move will render the king in check.
    // If it does this is illegal and not allowed and we must return false.
    if (this->willMoveRenderSideInCheck(currentSide, currentPos, destPos)) {
        this->currentBoardStatus = BoardStatus::WhiteCheck;
        std::cout << "Move renders side in check" << std::endl;
        return false;
    }
    // If the move is valid and we indeed do not render the white king in check, then we can go ahead
    // and check if we are simply moving to an empty piece or capturing a black piece.
    if (this->isCapturingMove(currentPos, destPos, currentSide)) {
        // If we are capturing an enemy piece, delete the piece being attacked remove from appropriate map
        // and place the attacking friendly piece in the position the enemy piece was in.
        // We can also check for en passant at this point if a pawn is making the move.
        std::cout << "Capture Move" << std::endl;
        this->captureMove(currentPos, destPos, currentSide);
    }
    else {
        // If we are moving to an empty piece then we check for pawn promotion and castling, and if this 
        // does not happen we simply move the current piece to its destPos
        std::cout << "Empty Move" << std::endl;
        this->emptyMove(currentPos, destPos, currentSide);
}
    std::cout << "Wtf" << std::endl;
    return true;
}