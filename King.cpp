//
// Created by Fabian J. Stigsson on 04/05/16.
//

#include "King.h"


King::King(bool isWhite, std::string pieceName) : ChessPiece(isWhite, pieceName) {
    this->setActionProtocol();
}

void King::setActionProtocol() {
    this->getActionProtocol().setMoveY(1);
    this->getActionProtocol().setMoveDiagonal(1);
    this->getActionProtocol().setMoveX(1);
}

bool King::isKing() const {
    return true;
}
