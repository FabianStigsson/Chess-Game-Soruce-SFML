//
// Created by Fabian J. Stigsson on 06/05/16.
//

#ifndef CS_100_CHESS_WITH_AI_CHESSBOARD_H
#define CS_100_CHESS_WITH_AI_CHESSBOARD_H


#include "ChessPiece.h"
#include <string>
#include "MoveCommand.hpp"
#include "ChessGraphicsSquare.hpp"


/**
 * Chess board class contains the graphical representation of each component of the chess board, and the raw Chess piece
 * data eg. chess pieces location, color and so on. The class is the main component of the game and serves as the brain of chess.
 */
class ChessBoard {

public:

    /**
     * Creates a chess board with the specific width and height
     * @param width
     * @param height
     */
    ChessBoard(int width, int height);
    /**
     * Prevents the chess grid from being copied
     */
    ChessBoard(const ChessBoard & other) = delete;

    /**
     * Delete dynamic allocated members
     */
    virtual ~ChessBoard();
    /**
     * No assginment
     */
    ChessBoard & operator=(const ChessBoard & rhs) = delete;
    /**
     * Gets the graphics of a chess square. This function should be called to render the chess square, it is especially
     * important to call it after a move has occured
     *
     * @param x 8x8 x coord
     * @param y 8x8 y coord
     * @return The square graphics on a specific grid coordinate to be rendered on the screen
     */
    const sf::RectangleShape & getSquareGraphics(int x, int y) const;
    /**
     * Gets the graphics associated with a chess piece
     * @param x 8x8 x coord
     * @param y 8x8 y coord
     * @return The sprite of a chess piece or an empty sprite, depending on whether a chess piece is located on the passed
     * location
     */
    const sf::Sprite & getChessPieceGraphics(int x, int y) const;
    /**
     * Selects a square on the chess board. This function will update the Grahpics chess square at the passed location
     * and record the chess piece that has been selected. The next time select is called a move command can be deduced
     * based on the previous selected square and the one selected now. If the move is valid the chess pice will move.
     * @param x 8x8 x coord
     * @param y 8x8 y coord
     */
    void select(int x, int y);
    /**
     * Deselects the square at x, y which updates the graphics of a chess square and resets the recorded move command if
     * select() was called before.
     * @param x 8x8 x coord
     * @param y 8x8 y coord
     */
    void deselect(int x, int y);
    /**
     * @return true if the king has not been killed and false if he is dead
     */
    bool isKingAlive() const;
    
    
private:
    
    ChessPiece ***chessPieces_;
    
    ChessGraphicsSquare *** graphicalSquares_;
    
    bool isPieceSelected_;
    
    bool iswhitePlayerTurn_;
    
    bool kingAlive_;
    
    sf::Vector2i selectedPieceCoord_;
    
    int width_, height_;
    /**
     * Deletes a chess piece from the chess board. This function should be called if a chess piece takes out another
     * @param x 8x8 x coord
     * @param y 8x8 y coord
     */
    void killPiece(int x, int y);
    /**
     * Creates the graphical grid by initiating the array containing all the graphical chess squares. This function
     * should only be called from the constructor
     */
    void createGraphicalGrid();
    /**
     * Creates the chess grid which contains all the chess pieces. This function should only be called from the constructor
     */
    void createGrid();
    /**
     * Checks whether the chess pice can move in accordance with the move command, a chess piece of the same color is
     * selected first, if the move collides with any chess pieces etc.. See implmentation for more detail.
     * @param command the movement command requested
     * @return true if it the move command is legal
     */
    bool isValidCommand (const MoveCommand &command) const;
    /**
     * Checks whether the move command would result in collision.
     * @return true if the move of the chess piece collides with a enemy chess piece or a same colored chess piece
     * on its steps before reaching the command's target location, else other wise
     */
    bool collides(const MoveCommand &command) const;
    /**
     * Moves the piece according to the passed move command. Validation should be made of the moved before this function
     * is called.
     * @param moveCommand
     */
    void movePiece(const MoveCommand & moveCommand);
    /**
     * Check if the move command is within the limits of the Action Protocol of the chess piece which is requested to move
     *
     * @param collide true if the chess piece would collide on the way to target
     * @param attack true if the chess piece ends up on the same location as an enemy piece
     * @param moveCommand the movement requested
     * @ return true if the chess piece has the abillity of moving according to the requested move and false if not
     */
    bool checkMove(const MoveCommand & moveCommand, bool attack, bool collide) const;
    /**
     * @return true if the x, y location does not contain a chess piece false if it does
     */
    bool isEmpty(int x, int y) const;
    
   

};


#endif //CS_100_CHESS_WITH_AI_CHESSBOARD_H