//
// Created by Fabian J. Stigsson on 03/05/16.
//

#include "Pawn.h"

Pawn::Pawn(bool isWhite, std::string pieceName) : ChessPiece(isWhite, pieceName) {
    this->setActionProtocol();
    this->hasMoved_ = false;
}


bool Pawn::checkMove(int xDisplacement, int yDisplacement, bool collide, bool attack) {

    // pawn can only attack diagonally
    if (attack) {
        getActionProtocol().setMoveDiagonal(1);
        getActionProtocol().setMoveY(0);
    }
    // pawn can move 2 extra steps in the beginning
    if (!hasMoved_) {
        getActionProtocol().setMoveY(2);
    }

    // return false if pawn tries to move through other pieces or tries to move backwards
    if (collide || (yDisplacement * (isWhite() ? -1 : 1)) < 0) {
        setActionProtocol();
        return false;
    }


    if (getActionProtocol().validateMove(xDisplacement, yDisplacement)) {

        hasMoved_ = true; // pawn has moved thus the 2 step bump expries
        setActionProtocol(); // resets the action protocol to the original state
        return true;
    } else {
        setActionProtocol(); // resets the action protocol, (if attack was requested and the move capacity of the pawn did not permit the move, action protocol must be reset)
        return false;
    }
}

void Pawn::setActionProtocol() {
    this->getActionProtocol().setMoveY(1);
    this->getActionProtocol().setMoveX(0);
    this->getActionProtocol().setMoveDiagonal(0);

}
