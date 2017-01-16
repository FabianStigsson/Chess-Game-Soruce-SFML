//
// Created by Fabian J. Stigsson on 04/05/16.
//

#include "Bishop.h"


Bishop::Bishop(bool isWhite, std::string pieceName) : ChessPiece(isWhite, pieceName) {
    this->setActionProtocol();
}


void Bishop::setActionProtocol() {
    this->getActionProtocol().setMoveDiagonal(8);
    this->getActionProtocol().setMoveY(0);
    this->getActionProtocol().setMoveX(0);
}