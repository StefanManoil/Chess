#include "Board.h"

Piecetype Board::getTypeOfPiece(std::pair<int, int> location) {
  /*Piece *p = this->pieces.at(location.first).at(location.second);
  if (p) {
    return p->getType();
  } else {
    return Piecetype::NoPiece;
  }*/
  for (int i = 0; i < this->actualPieces.size(); i++) {
      if (location.first == this->actualPieces.at(i)->getCoordinates().first &&
          location.second == this->actualPieces.at(i)->getCoordinates().second) {
              return this->actualPieces.at(i)->getType();
          }
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
  for (int i = 0; i < this->actualPieces.size(); i++) {
      if (location.first == this->actualPieces.at(i)->getCoordinates().first &&
          location.second == this->actualPieces.at(i)->getCoordinates().second) {
              return this->actualPieces.at(i)->side;
          }
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
  for (int i = 0; i < this->actualPieces.size(); i++) {
      if (location.first == this->actualPieces.at(i)->getCoordinates().first &&
          location.second == this->actualPieces.at(i)->getCoordinates().second) {
              return this->actualPieces.at(i)->pieceMoved();
          }
  }
  return false;  // or return true not sure
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
    if (this->inSetupMode) {
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
    if (this->inSetupMode) {
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
  std::set<std::pair<int, int>> actualPiecesCoordinates;
  for (int i = 0; i < this->actualPieces.size(); i++) {
      actualPiecesCoordinates.insert(this->actualPieces.at(i)->getCoordinates());
  }

  for (int i = 0; i < 8; i++) {
      std::cout << 8 - i << " ";
      for (int j = 0; j < 8; j++) {
          std::pair<int, int> currentPair = std::make_pair(i, j);
          if (actualPiecesCoordinates.count(currentPair) > 0) {
              std::cout << actualPiecesCoordinates->toString(); // this needs tweaking not right
          }
          else {
              std::cout << ((((i + j) % 2) == 0) ? " " : "-");
          }
      }
      std::cout << std::endl;
  }
  std::cout << std::endl << "  abcdefgh" << std::endl << std::endl;
}
