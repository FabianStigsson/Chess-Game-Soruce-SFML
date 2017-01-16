//
// Created by Fabian J. Stigsson on 04/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_BISHOP_H
#define CS_100_CHESS_WITH_AI_BISHOP_H


#include "ChessPiece.h"

/**
 * A Bishop chess piece which inherits its functions from the abstract ChessPiece class. A bishop implements the
 * setActionProtocol() function
 */
class Bishop : public ChessPiece {

public:
    /**
     * Creates a Bishop which is either white of black given the boolean value of isWhite, and the name of this chess piece
     * which should be set to "Bishop"
     */
    Bishop(bool isWhite, std::string pieceName);

protected:
    /**
     * Sets the action protocol of the Bishop which should be implemented as (xSteps = 0, ySteps = 0, diagonalSteps  = 8)
     */
    virtual void setActionProtocol() override;
};


#endif //CS_100_CHESS_WITH_AI_BISHOP_H
