//
//  ChessGame.hpp
//  Chess
//
//  Created by Fabian J. Stigsson on 06/05/16.
//  Copyright © 2016 Fabian J. Stigsson. All rights reserved.
//

#ifndef ChessGraphics_hpp
#define ChessGraphics_hpp

#include <SFML/Graphics.hpp>
#include "ChessBoard.h"
#include "ChessBoard.h"
#include "ChessGraphicsSquare.hpp"

/**
 *
 * The chess game itself is the start point of the entire chess game. The class contains the game loop and renders
 * the graphics
 */
class ChessGame {

public:
    /**
     * Creates a chess game with a window size based on the width and height passed
     * @param width
     * @param height
     */
    ChessGame(int width, int height);
    /**
     * Destroys the dynamically allocated members of the chess game.
     */
    ~ChessGame();

private:
    /**
     * Starts the game loop, which constantly checks user inputs and decide what to do with it
     */
    void startGraphics();
    /**
     * Draws all the squares of the chess board and chess pieces by looping through 8x8 grid and drawing the square which
     * corresponds to that coordinate
     */
    void renderChessBoard();

    sf::RenderWindow *chessWindow_;

    ChessBoard *chessBoard_;
    
    int width_, height_;

};


#endif /* ChessGame_hpp */
