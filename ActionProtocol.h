//
// Created by Fabian J. Stigsson on 05/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_ACTIONPROTOCOL_H
#define CS_100_CHESS_WITH_AI_ACTIONPROTOCOL_H

/**
 * Action protocol holds information about all the actions a chess piece can take
 * Users of this class can set the diagonal movement, x movement and y movement.
 */
class ActionProtocol {

public:
    /**
     * Default constructor
     */
    ActionProtocol() = default;

    /**
     * Sets the maximum steps a chess piece can take diagonally
     * @param steps
     */
    void setMoveDiagonal(int steps);

    /**
     * Sets the maximum steps a chess piece can take along the y axis
     */
    void setMoveY(int steps);

    /**
     * Sets the maximum steps a chess piece can take along the x axis
     * @param steps
     */
    void setMoveX(int steps);

    /**
     * Checks whether the movement in x and y is permitted given the x, y and diagonal step limits.
     * @param moveX
     * @param moveY
     */
    bool validateMove(int moveX, int moveY) const;

private:
    /**
     * Checks the limit of the diagonal movement requested by the user
     * @param moveX
     * @param moveY
     */
    bool validateDiagonalMove(int moveX, int moveY) const;

    int diagonalSteps_, xSteps_, ySteps_;

};


#endif //CS_100_CHESS_WITH_AI_ACTIONPROTOCOL_H
