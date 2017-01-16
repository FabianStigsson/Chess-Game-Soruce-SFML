//
// Created by Fabian J. Stigsson on 03/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_PAWN_H
#define CS_100_CHESS_WITH_AI_PAWN_H


#include "ChessPiece.h"

/**
 * Pawn inherits from Chess piece and implements its own checkMove function
 */
class Pawn : public ChessPiece {

public:
    /**
     * Create a pawn object
     * @param isWhite true if the pawn is white and false if it is black
     * @param pieceName the name of the pawn
     */
    Pawn(bool isWhite, std::string pieceName);

    /**
     * Check whether the pawn can move as requested.
     * @param xDisplacement the displacement in x
     * @param yDisplacement the displacement in y
     * @param collide true if the pawn collides on its way to the target location and false otherwise
     * @param attack true if the pawn is attack an enemy piece
     * @return true if the move is valid given the displacement in x and y and false other wise
     */
    virtual bool checkMove(int xDisplacement, int yDisplacement, bool collide, bool attack) override;

protected:
    /**
     * Sets the action protocol of the pawn to ( 0 steps in x, 1 steps in y, 0 steps diagonally)
     */
    virtual void setActionProtocol() override;

private:

    bool hasMoved_;
};


#endif //CS_100_CHESS_WITH_AI_PAWN_H
