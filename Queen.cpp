//
// Created by Fabian J. Stigsson on 05/05/16.
//

#include "Queen.h"


Queen::Queen(bool isWhite, std::string pieceName) : ChessPiece(isWhite, pieceName) {
    this->setActionProtocol();
}

void Queen::setActionProtocol() {
    this->getActionProtocol().setMoveDiagonal(8);
    this->getActionProtocol().setMoveY(8);
    this->getActionProtocol().setMoveX(8);

}
