//
// Created by Fabian J. Stigsson on 04/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_ROOK_H
#define CS_100_CHESS_WITH_AI_ROOK_H


#include "ChessPiece.h"

/**
 * Rook inherits from Chess piece and sets its own action protocol
 */
class Rook : public ChessPiece {


public:
    /**
     * Creates a Rook.
     * @param isWhite true if the rook should be white and false if it should be black
     * @param pieceName the name of the rook
     */
    Rook(bool isWhite, std::string pieceName);

protected:
    /**
     * Sets the action protocol of the rook to ( 8 steps in x, 8 steps in y, 0 steps diagonally)
     */
    virtual void setActionProtocol() override;
};


#endif //CS_100_CHESS_WITH_AI_ROOK_H
