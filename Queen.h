//
// Created by Fabian J. Stigsson on 05/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_QUEEN_H
#define CS_100_CHESS_WITH_AI_QUEEN_H


#include "ChessPiece.h"

/**
 * Queen inherits from Chess piece and sets its own Action Protocol
 */
class Queen : public ChessPiece {


public:
    /**
     * Creates a Queen
     * @param isWhite true if the queen should be white and false if should be black
     * @param pieceName the name of this chess piece
     */
    Queen(bool isWhite, std::string pieceName);

protected:
    /**
     * Sets the action protocol of the queen to ( 8 steps in x, 8 steps in y, 8 steps diagonally)
     */
    virtual void setActionProtocol();
};


#endif //CS_100_CHESS_WITH_AI_QUEEN_H
