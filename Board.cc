#include "Board.h"

bool Board::inSetup() {
    return this->inSetupMode;
}

Piecetype Board::getTypeOfPiece(std::pair<int, int> location) {
  /*Piece *p = this->pieces.at(location.first).at(location.second);
  if (p) {
    return p->getType();
  } else {
    return Piecetype::NoPiece;
  }*/
  /*for (int i = 0; i < this->actualPieces.size(); i++) {
      if (location.first == this->actualPieces.at(i)->getCoordinates().first &&
          location.second == this->actualPieces.at(i)->getCoordinates().second) {
              return this->actualPieces.at(i)->getType();
          }
  }
  return Piecetype::NoPiece;*/
  if (this->actualPosOfPieces.count(location) > 0) {
      return this->actualPosOfPieces.at(location)->getType();
  }
  return Piecetype::NoPiece;
}

Side Board::getSideOfPiece(std::pair<int, int> location) {
  /*Piece *p = this->pieces.at(location.first).at(location.second);
  if (p) {
    return p->side;
  } 
  else {
    return Side::None;
  }*/
  /*for (int i = 0; i < this->actualPieces.size(); i++) {
      if (location.first == this->actualPieces.at(i)->getCoordinates().first &&
          location.second == this->actualPieces.at(i)->getCoordinates().second) {
              return this->actualPieces.at(i)->side;
          }
  }
  return Side::None;*/
  if (this->actualPosOfPieces.count(location) > 0) {
      return this->actualPosOfPieces.at(location)->side();
  }
  return Side::None;
}

bool Board::pieceAtPosMoved(std::pair<int,int> location) {
  /*Piece *p = this->pieces.at(location.first).at(location.second);
  if (p) {
    return p->pieceMoved();
  } 
  else {
    return false; or return true not sure
  }*/
  /*for (int i = 0; i < this->actualPieces.size(); i++) {
      if (location.first == this->actualPieces.at(i)->getCoordinates().first &&
          location.second == this->actualPieces.at(i)->getCoordinates().second) {
              return this->actualPieces.at(i)->pieceMoved();
          }
  }
  return false;  // or return true not sure */
  if (this->actualPosOfPieces.count(location) > 0) {
      return this->actualPosOfPieces.at(location)->hasMoved();
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
  /*if (this->inSetupMode) {
    if (piecetype == Piecetype::Rook) {
      removePieceInSetup(pos);
      this->pieces.at(pos.first).at(pos.second) = new Rook(pos, side);
    }
    else if (piecetype == Piecetype::Knight) {
      removePieceInSetup(pos);
      this->pieces.at(pos.first).at(pos.second) = new Knight(pos, side);
    }
    else if (piecetype == Piecetype::Bishop) {
      removePieceInSetup(pos);
      this->pieces.at(pos.first).at(pos.second) = new Bishop(pos, side);
    }
    else if (piecetype == Piecetype::King) {
      removePieceInSetup(pos);
      this->pieces.at(pos.first).at(pos.second) = new King(pos, side);
    } 
    else if (piecetype == Piecetype::Queen) {
      removePieceInSetup(pos);
      this->pieces.at(pos.first).at(pos.second) = new Queen(pos, side);
    } 
    else if (piecetype == Piecetype::Pawn) {
      removePieceInSetup(pos);
      this->pieces.at(pos.first).at(pos.second) = new Pawn(pos, side);
    }
  } 
  else {
    std::cout << "You are not in Setup mode." << std::endl;
  }*/
    /*if (this->inSetupMode) {
        if (piecetype == Piecetype::Rook) {
            this->removePieceInSetup(pos);
            this->actualPieces.push_back(new Rook(pos, side));
        }
        else if (piecetype == Piecetype::Knight) {
            this->removePieceInSetup(pos);
            this->actualPieces.push_back(new Knight(pos, side));
        }
        else if (piecetype == Piecetype::Bishop) {
            this->removePieceInSetup(pos);
            this->actualPieces.push_back(new Bishop(pos, side));
        }
        else if (piecetype == Piecetype::King) {
            this->removePieceInSetup(pos);
            this->actualPieces.push_back(new King(pos, side));
        }
        else if (piecetype == Piecetype::Queen) {
            this->removePieceInSetup(pos);
            this->actualPieces.push_back(new Queen(pos, side));
        }
        else if (piecetype == Piecetype::Pawn) {
            this->removePieceInSetup(pos);
            this->actualPieces.push_back(new Pawn(pos, side));
        }
    }
    else {
        std::cout << "You are not in Setup mode." << std::endl;
    }*/
    if (this->inSetupMode) {
        if (piecetype == Piecetype::Rook) {
            this->removePieceInSetup(pos);
            this->actualPosOfPieces.emplace(pos, new Rook(pos, side));
        }
        else if (piecetype == Piecetype::Knight) {
            this->removePieceInSetup(pos);
            this->actualPosOfPieces.emplace(pos, new Knight(pos, side));
        }
        else if (piecetype == Piecetype::Bishop) {
            this->removePieceInSetup(pos);
            this->actualPosOfPieces.emplace(pos, new Bishop(pos, side));
        }
        else if (piecetype == Piecetype::King) {
            this->removePieceInSetup(pos);
            this->actualPosOfPieces.emplace(pos, new King(pos, side));
        }
        else if (piecetype == Piecetype::Queen) {
            this->removePieceInSetup(pos);
            this->actualPosOfPieces.emplace(pos, new Queen(pos, side));
        }
        else if (piecetype == Piecetype::Pawn) {
            this->removePieceInSetup(pos);
            this->actualPosOfPieces.emplace(pos, new Pawn(pos, side));
        }
    }
    else {
        std::cout << "You are not in Setup mode." << std::endl;
    }
}

void Board::removePieceInSetup(std::pair<int , int> location) {
    /*if (this->inSetupMode) {
        if (this->pieces.at(location.first).at(location.second) != nullptr) {
            delete this->pieces.at(location.first).at(location.second);
            this->pieces.at(location.first).at(location.second) = nullptr;
        }
    }
    else {
        std::cout << "You are not in Setup mode." << std::endl;
    }*/
    /*if (this->inSetupMode) {
        for (int i = 0; i < this->actualPieces.size(); i++) {
            if (location.first == this->actualPieces.at(i)->getCoordinates().first &&
                location.second == this->actualPieces.at(i)->getCoordinates().second) {
                    delete this->actualPieces.at(i);
                    this->actualPieces.at(i) = nullptr;
                    // delete the newly deleted piece from our actualPieces vector
                    this->actualPieces.erase(this->actualPieces.begin() + i);
            }
        }
    }
    else {
        std::cout << "You are not in Setup mode." << std::endl;
    }*/
    if (this->inSetupMode) {
        if (this->actualPosOfPieces.count(location) > 0) {
            delete this->actualPosOfPieces.at(location);
            this->actualPosOfPieces.at(location) = nullptr;
            // delete the newly deleted piece from our actualPosPieces map
            this->actualPosOfPieces.erase(location);
        }
    }
    else {
        std::cout << "You are not in Setup mode." << std::endl;
    }
}

void Board::exitSetup() {
    // instead of iterating through the whole board we can just iterate through the pieces
    // and check for more than 1 king, side in check , etc

}

void Board::print() {
  /*for(int i = 0; i < 8; i++){
    std::cout << 8 - i << " ";
    for(int j = 0; j < 8; j++){
      Piece *p = pieces[i][j];
      if (p != nullptr) {
	std::cout << p->toString();
      } else {
	std::cout << ((((i + j) % 2) == 0) ? " " : "-");
      }
    }  
    std::cout << std::endl;
  }
  std::cout << std::endl << "  abcdefgh" << std::endl << std::endl;*/
  /*std::map<std::pair<int, int>, Piece> actualPiecesCoordinates;
  for (int i = 0; i < this->actualPieces.size(); i++) {
      actualPiecesCoordinates.emplace
      (this->actualPieces.at(i)->getCoordinates(), this->actualPieces.at(i)); //getCoordinates of piece
  }

  for (int i = 0; i < 8; i++) {
      std::cout << 8 - i << " ";
      for (int j = 0; j < 8; j++) {
          std::pair<int, int> currentPair = std::make_pair(i, j);
          if (actualPiecesCoordinates.count(currentPair) > 0) {
              std::cout << actualPiecesCoordinates.at(currentPair)->toString(); // this needs tweaking not right
          }
          else {
              std::cout << ((((i + j) % 2) == 0) ? " " : "-");
          }
      }
      std::cout << std::endl;
  }
  std::cout << std::endl << "  abcdefgh" << std::endl << std::endl; */
  for (int i = 0; i < 8; i++) {
      std::cout << 8 - i << " ";
      for (int j = 0; j < 8; j++) {
          std::pair<int, int> currentPair = std::make_pair(i, j);
          if (actualPosOfPieces.count(currentPair) > 0) {
              std::cout << actualPosOfPieces.at(currentPair)->toString(); // this needs tweaking not right
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
  /*if (isSetupMode) {
    bool whiteKingFound = false;
    bool blackKingFound = false;
    
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
	Piece *p = pieces[i][j];
	if (p && p->getPieceType() == PieceType::King) {
	  //cout << "KING";
	  if (p->side == Side::White) {
	    if (whiteKingFound) {
	      cout << "More than one white king, cannot exit setup mode" << endl;
	      return;
	    } else {
	      whiteKingFound = true;
	    }
	  } else if (p->side == Side::Black) {
	    if (blackKingFound) {
	      cout << "More than one black king, cannot exit setup mode" << endl;
	      return;
	    } else {
	      blackKingFound = true;
	    }
	  }
	}
      }
    }
    
    if (!whiteKingFound) {
      cout << "No white king, cannot exit setup mode" << endl;
      return;
    }
    
    if (!blackKingFound) {
      cout << "No black king, cannot exit setup mode" << endl;
      return;
    }
    
    for (int i = 0; i < 8; i++) {
      Piece *p1 = pieces[0][i];
      if (p1 && p1->getPieceType() == PieceType::Pawn) {
	cout << "Pawn in first row, cannot exit setup mode" << endl;
	return;
      }

      Piece *p2 = pieces[7][i];
      if (p2 && p2->getPieceType() == PieceType::Pawn) {
	cout << "Pawn in last row, cannot exit setup mode" << endl;
	return;
      }
    }
    
    BoardStatus status = checkBoardStatus(true);
    if (status == BoardStatus::BlackInCheck) {
      cout << "Black king in check, cannot exit setup mode" << endl;
      return; 
    } else if (status == BoardStatus::WhiteInCheck) {
      cout << "White king in check, cannot exit setup mode" << endl;
      return;
    }

    isSetupMode = false;
  } else {
    cout << "Not in setup mode" << endl;
  }*/
  /*if (this->inSetupMode) {
      bool foundBlackKing = false;
      bool foundWhiteKing = false;
      for (int i = 0; i < this->actualPieces.size(); i++) {
          if (this->actualPieces.at(i)->getType() == Piecetype::King) {
              if (this->actualPieces.at(i)->side == Side::Black) {
                  if (foundBlackKing) {
                      std::cout << "Found more than one black king, you cannot exit Setuo mode." << std::endl;
                      return;
                  }
                  else {
                      foundBlackKing = true;
                  }
              }
              else if (this->actualPieces.at(i)->side == Side::White) {
                  if (foundWhiteKing) {
                      std::cout << "Found more than one white king, you cannot exit Setuo mode." << std::endl;
                      return;
                  }
                  else {
                      foundWhiteKing = true;
                  }
              }
          }
      }
      if (!foundBlackKing) {
          std::cout << "Did not find a black king, you cannot exit Setup mode." << std::endl;
          return;
      }
      if (!foundWhiteKing) {
          std::cout << "Did not find a black king, you cannot exit Setup mode." << std::endl;
          return;
      }
      for (int i = 0; i < this->actualPieces.size(); i++) {
          if (this->actualPieces.at(i)->getCoordinates().first == 0) {
              if (this->actualPieces.at(i)->getType() == Piecetype::Pawn) {
                  std::cout << "Pawn is in first row, you cannot exit Setup mode." << std::endl;
                  return;
              }
          }
          else if (this->actualPieces.at(i)->getCoordinates().first == 7) {
              if (this->actualPieces.at(i)->getType() == Piecetype::Pawn) {
                  std::cout << "Pawn is in last row, you cannot exit Setup mode." << std::endl;
                  return;
              }
          }
      }
      BoardStatus currentStatus = checkStatusBasic();
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
  }*/
  if (this->inSetupMode) {
      bool foundBlackKing = false;
      bool foundWhiteKing = false;
      for (const auto& posPiecePair: this->actualPosOfPieces) {
          if (posPiecePair.second->getType() == Piecetype::King) {
              if (posPiecePair.second->side == Side::Black) {
                  if (foundBlackKing) {
                      std::cout << "Found more than one black king, you cannot exit Setuo mode." << std::endl;
                      return;
                  }
                  else {
                      foundBlackKing = true;
                  }
              }
              else if (posPiecePair.second->side == Side::White) {
                  if (foundWhiteKing) {
                      std::cout << "Found more than one white king, you cannot exit Setuo mode." << std::endl;
                      return;
                  }
                  else {
                      foundWhiteKing = true;
                  }
              }
          }
      }
      if (!foundBlackKing) {
          std::cout << "Did not find a black king, you cannot exit Setup mode." << std::endl;
          return;
      }
      if (!foundWhiteKing) {
          std::cout << "Did not find a black king, you cannot exit Setup mode." << std::endl;
          return;
      }
      for (const auto& posPiecePair: this->actualPosOfPieces) {
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
      BoardStatus currentStatus = getStatusBasic();
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
    std::map<std::pair<int, int>, Piece*> mapOfBlackPieces;
    std::map<std::pair<int, int>, Piece*> mapOfWhitePieces;
    for (const auto& posPiecePair : this->actualPosOfPieces) {
        if (posPiecePair.second->side == Side::Black) {
            mapOfBlackPieces.emplace(posPiecePair.first, posPiecePair.second);
        }
        else if (posPiecePair.second->side == Side::White) {
            mapOfWhitePieces.emplace(posPiecePair.first, posPiecePair.second);
        }
    }
    for (const auto& posPiecePairBlacks : mapOfBlackPieces) {
        if (posPiecePairBlacks.second->getType() == Piecetype::King) {
            for (const auto& posPiecePairWhites : mapOfWhitePieces) {
                for (int i = 0; i < posPiecePairWhites.second->getMoves(*this).size(); i++) {
                    if (posPiecePairWhites.second->getMoves.at(i) == posPiecePairBlacks.first) {
                        return BoardStatus::BlackCheck;
                    }
                }
            }
        }
    }
    for (const auto& posPiecePairWhites : mapOfWhitePieces) {
        if (posPiecePairWhites.second->getType() == Piecetype::King) {
            for (const auto& posPiecePairBlacks : mapOfBlackPieces) {
                for (int i = 0; i < posPiecePairBlacks.second->getMoves(*this).size(); i++) {
                    if (posPiecePairBlacks.second->getMoves.at(i) == posPiecePairWhites.first) {
                        return BoardStatus::WhiteCheck;
                    }
                }
            }
        }
    }
    return BoardStatus::Normal;
}

void Board::resetBoard() {
    for (auto& posPiecePair : this->actualPosOfPieces) {
        delete posPiecePair.second;
        posPiecePair.second = nullptr;
    }
    this->actualPosOfPieces.clear();
    // make black first row
    this->actualPosOfPieces.emplace(std::make_pair(0, 0), new Rook(std::make_pair(0, 0), Side::Black));
    this->actualPosOfPieces.emplace(std::make_pair(0, 1), new Knight(std::make_pair(0, 1), Side::Black));
    this->actualPosOfPieces.emplace(std::make_pair(0, 2), new Bishop(std::make_pair(0, 2), Side::Black));
    this->actualPosOfPieces.emplace(std::make_pair(0, 3), new Queen(std::make_pair(0, 3), Side::Black));
    this->actualPosOfPieces.emplace(std::make_pair(0, 4), new King(std::make_pair(0, 4), Side::Black));
    this->actualPosOfPieces.emplace(std::make_pair(0, 5), new Bishop(std::make_pair(0, 5), Side::Black));
    this->actualPosOfPieces.emplace(std::make_pair(0, 6), new Knight(std::make_pair(0, 6), Side::Black));
    this->actualPosOfPieces.emplace(std::make_pair(0, 7), new Rook(std::make_pair(0, 8), Side::Black));
    // make black pawn row
    for (int i = 0; i < 8; i++) {
        this->actualPosOfPieces.emplace(std::make_pair(1, i), new Pawn(std::make_pair(1, i), Side::Black));
    }
    // make white pawn row
    for (int i = 0; i < 8; i++) {
        this->actualPosOfPieces.emplace(std::make_pair(6, i), new Pawn(std::make_pair(6, i), Side::White));
    }
    // make white last row
    this->actualPosOfPieces.emplace(std::make_pair(7, 0), new Rook(std::make_pair(7, 0), Side::White));
    this->actualPosOfPieces.emplace(std::make_pair(7, 1), new Knight(std::make_pair(7, 1), Side::White));
    this->actualPosOfPieces.emplace(std::make_pair(7, 2), new Bishop(std::make_pair(7, 2), Side::White));
    this->actualPosOfPieces.emplace(std::make_pair(7, 3), new Queen(std::make_pair(7, 3), Side::White));
    this->actualPosOfPieces.emplace(std::make_pair(7, 4), new King(std::make_pair(7, 4), Side::White));
    this->actualPosOfPieces.emplace(std::make_pair(7, 5), new Bishop(std::make_pair(7, 5), Side::White));
    this->actualPosOfPieces.emplace(std::make_pair(7, 6), new Knight(std::make_pair(7, 6), Side::White));
    this->actualPosOfPieces.emplace(std::make_pair(7, 7), new Rook(std::make_pair(7, 8), Side::White));
}
