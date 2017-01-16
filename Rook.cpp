//
// Created by Fabian J. Stigsson on 04/05/16.
//

#include "Rook.h"


Rook::Rook(bool isWhite, std::string pieceName) : ChessPiece(isWhite, pieceName) {
    this->setActionProtocol();
}


void Rook::setActionProtocol() {
    this->getActionProtocol().setMoveDiagonal(0);
    this->getActionProtocol().setMoveY(8);
    this->getActionProtocol().setMoveX(8);

}
