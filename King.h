//
// Created by Fabian J. Stigsson on 04/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_KING_H
#define CS_100_CHESS_WITH_AI_KING_H


#include "ChessPiece.h"


/**
 * King Chess piece, inherits from Chesspiece
 */
class King : public ChessPiece {


public:
    /**
     * Create a king object.
     * @param isWhite true if this chess piece should be white and false if it should be black
     * @param pieceName name of the chess piece
     */
    King(bool isWhite, std::string pieceName);

    /**
     * @return true because this class is a King
     */
    virtual bool isKing() const override;

protected:
    /**
     * Sets the action protocol to ( 1 steps in x, 1 steps in y, 1 steps diagonally)
     */
    virtual void setActionProtocol() override;

};


#endif //CS_100_CHESS_WITH_AI_KING_H
