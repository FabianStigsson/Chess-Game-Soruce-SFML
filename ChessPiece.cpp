//
// Created by Fabian J. Stigsson on 03/05/16.
//

#include "ChessPiece.h"

ChessPiece::ChessPiece(bool isWhite, std::string pieceName) {
    this->pieceName_ = pieceName;
    this->isWhite_ = isWhite;
}

bool ChessPiece::checkMove(int xDisplacement, int yDisplacement, bool collide, bool attack) {
    return getActionProtocol().validateMove(xDisplacement, yDisplacement) && !collide;
}

bool ChessPiece::isWhite() const {
    return isWhite_;
}

bool ChessPiece::isKing() const {
    return false;
}

ActionProtocol &ChessPiece::getActionProtocol() {
    return this->protocol_;
}

std::string ChessPiece::getPieceName() const {
    return this->pieceName_;
}





