#include "Board.h"

Piecetype Board::getTypeOfPiece(std::pair<int, int> location) {
  Piece *p = this->pieces.at(location.first).at(location.second);
  if (p) {
    return p->getType();
  } else {
    return Piecetype::NoPiece;
  }
}

Side Board::getSideOfPiece(std::pair<int, int> location) {
  Piece *p = this->pieces.at(location.first).at(location.second);
  if (p) {
    return p->side;
  } 
  else {
    return Side::None;
  }
}

bool Board::pieceAtPosMoved(std::pair<int,int> location) {
  Piece *p = this->pieces.at(location.first).at(location.second);
  if (p) {
    return p->pieceMoved();
  } 
  else {
    return false;
  }
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
  }
}

void Board::removePieceInSetup(std::pair<int , int> location) {
    if (this->inSetupMode) {
        if (this->pieces.at(location.first).at(location.second) != nullptr) {
            delete this->pieces.at(location.first).at(location.second);
            this->pieces.at(location.first).at(location.second) = nullptr;
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
