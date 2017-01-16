//
// Created by Fabian J. Stigsson on 05/05/16.
//

#include "ActionProtocol.h"
#include <stdlib.h>

void ActionProtocol::setMoveDiagonal(int steps) {
    this->diagonalSteps_ = steps;
}

void ActionProtocol::setMoveY(int steps) {
    this->ySteps_ = steps;
}

void ActionProtocol::setMoveX(int steps) {
    this->xSteps_ = steps;
}

bool ActionProtocol::validateMove(int xDisplacement, int yDisplacement) const {

    xDisplacement = abs(xDisplacement);
    yDisplacement = abs(yDisplacement);

    if (xDisplacement != 0 && yDisplacement != 0) {
        return validateDiagonalMove(xDisplacement, yDisplacement);
    }
    // if the requested steps are higher than those permitted false is returnes
    if (xDisplacement > this->xSteps_ || yDisplacement > this->ySteps_) return false;


    return true;;
}


bool ActionProtocol::validateDiagonalMove(int moveX, int moveY) const {
    int diagonalSteps = diagonalSteps_;
    // checks if moveX and moveY is zero before diagonalSteps is, if so the move is permitted
    while (moveX != 0 && moveY != 0) {
        moveX--;
        moveY--;
        diagonalSteps--;
    }

    return diagonalSteps >= 0;
}



