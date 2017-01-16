//
// Created by Fabian J. Stigsson on 05/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_KNIGHT_H
#define CS_100_CHESS_WITH_AI_KNIGHT_H


#include "ChessPiece.h"

/**
 * Knight inherits from Chess piece
 */
class Knight : public ChessPiece {

public:
    /**
     * Creates a Knight
     * @param isWhite sets whehther the knight is white or not
     * @param pieceName the name of this chess piece
     */
    Knight(bool isWhite, std::string pieceName);

    /**
     * Checks if the move requested is in line with the walking capabillities of the Knight
     * @return true if the move is valid and false it is invalid
     */
    virtual bool checkMove(int xDisplacement, int yDisplacement, bool collide, bool attack) override;

protected:
    /**
     * Sets the user protocol
     */
    virtual void setActionProtocol() override;
};


#endif //CS_100_CHESS_WITH_AI_KNIGHT_H
