//
// Created by Fabian J. Stigsson on 05/05/16.
//

#include "Knight.h"

Knight::Knight(bool isWhite, std::string pieceName) : ChessPiece(isWhite, pieceName) {
    this->setActionProtocol();

}

bool Knight::checkMove(int xDisplacement, int yDisplacement, bool collide, bool attack) {
    int moveX = abs(xDisplacement), moveY = abs(yDisplacement);

    if (moveX == 1 && moveY == 2) {
        return true;
    } else if (moveX == 2 && moveY == 1) {
        return true;
    }

    return false;
}


void Knight::setActionProtocol() {
    // protocol not needed

}
