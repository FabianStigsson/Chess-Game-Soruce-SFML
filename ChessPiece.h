//
// Created by Fabian J. Stigsson on 03/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_CHESSPIECE_H
#define CS_100_CHESS_WITH_AI_CHESSPIECE_H

#include <string>
#include <iostream>
#include "ActionProtocol.h"
#include <SFML/Graphics.hpp>

/**
 * A Chess piece serves as the abstract base class for the Rook, Bishop, Pawn, King, Queen and Knight. This class
 * provides general member pertitent to a chess piece such as, information about its color, its name. It also permits
 * users to check if a move is permitted by this chess piece. The pure virtual setActionProtocol() is implemented by
 * sub classes which lets subclasses specify their own movement limits.
 */
class ChessPiece {


public:
    /**
     * Creates a chess piece
     *
     * @param isWhite whether this chess piece is white or not
     * @param pieceName the name of this piece
     */
    ChessPiece(bool isWhite, std::string pieceName);

    /**
     * Default copy of this chess piece
     */
    ChessPiece(const ChessPiece &other) = default;

    /**
     * Default constructor
     */
    virtual ~ChessPiece() = default;

    /**
     * Check if the requested move is compatible with the limits spcified by the Action Protocol
     * @param xDisplacement
     * @param yDisplacement
     * @param collide true if this piece is colliding on its way to the target location
     * @param attack true if an enemy chess piece is located at this piece's target location
     * @return true if xDisplacement and yDisplacement is compatible with the action protocol, and whether the chess
     * piece collides or not can change what the function return.
     */
    virtual bool checkMove(int xDisplacement, int yDisplacement, bool collide, bool attack);

    /**
     * @return the chess piece name of this chess piece.
     */
    std::string getPieceName() const;

    /**
     * @return true if this chess piece is the king
     */
    virtual bool isKing() const;

    /**
     * @return true if this chess piece is white false if black
     */
    bool isWhite() const;

protected:
    /**
     * Gets the reference to the action protocol, this function should be called when setting the action protocol.
     * @return a reference to the action protocol
     */
    virtual ActionProtocol &getActionProtocol();

    /**
     * Sets the action protocol, each sub class should implement the action protocol to limit its movement.
     */
    virtual void setActionProtocol() = 0;


private:

    ActionProtocol protocol_;

    bool isWhite_;

    std::string pieceName_;


};


#endif //CS_100_CHESS_WITH_AI_CHESSPIECE_H
