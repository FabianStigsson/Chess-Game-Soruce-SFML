//
//  ChessGraphicsSquare.hpp
//  Chess
//
//  Created by Fabian J. Stigsson on 09/05/16.
//  Copyright © 2016 Fabian J. Stigsson. All rights reserved.
//

#ifndef ChessGraphicsSquare_hpp
#define ChessGraphicsSquare_hpp

#include "ChessGraphicsSquare.hpp"
#include "SFML/Graphics.hpp"

/**
 *
 * A ChessGraphicsSquare represent a square within the chess board. The square can either be empty, that is
 * only showing the color of the square, or it can show a chess piece, depending on whether a chess piece
 * reside on that grid coordinate. The class's always return its color passed in the
 * constructor to the user to draw unless the graphic square is selected; it then return a square with a grey color.
 * The class holds information about its grid position, that is its position on the 8x8 chess grid. it also holds data about
 * the graphical position on the graphic window.
 */
class ChessGraphicsSquare {
public:
    /**
     * Create a graphic square on the specific location and with the passed color.
     *
     * @param sizeX the size in x of the sqiare
     * @param sizeY the size in y of the square
     * @param xPos the graphical x coordinate of the square
     * @param yPos the graphical y coordinate of the square
     * @param gridXPos the 8x8 x coordinate of the square
     * @param gridYPos the 8x8 y coordinate of the square
     * @param color the color of the square
     */
    ChessGraphicsSquare(int sizeX, int sizeY, int xPos, int yPos, int gridXPos, int gridYPos, sf::Color color);

    /**
     * Sets the texture of this square that which should represent a chess piece image if the square is occupied by
     * a chess piece other wise this function should not be called
     * @param texture represents
     */
    void setTexture(const sf::Texture &texture);

    /**
     * This function returns a Drawable object reference which should be drawn on the screen to represent a chess piece. Note that
     * the user does not have to check whether this graphical square contains a chess piece or not before calling this
     * function since it wont cause any change if the sprite is drawn without containing a graphical representation of
     * a chess piece.
     *
     * @return the sprite (located within the square) to be drawn to represent a chess piece.
     */
    const sf::Sprite &getSpriteOfSquare() const;

    /**
     * This function should be called to get the current graphics of a x, y grid coord of the chess board.
     * @return a reference to a Rectangle Shape which represents a square of a chess board.
     */
    const sf::RectangleShape &getGraphicsSquare() const;

    /**
     * Check if a graphical x, y coordinate resides within this square.
     * @return true if this square contains the passed graphical x, y coordinates within its bounds, false otherwise
     */
    bool contains(float x, float y) const;

    /**
     * Selecting this chess square simply changes the color of this square to grey to show the user that it is selected.
     */
    void select();

    /**
     * Deselecting this chess square changes this color back from grey to its orginal color
     */
    void deselect();

    /**
     * Gets the grid x, y location of this square.
     * @return the x, y 8x8 coordinate of this square
     */
    sf::Vector2i getSquareGridPoint() const;

    /**
     * Removes the chess piece graphics of this square. This function should be called if this square no longer should
     * display a chess piece.
     */
    void removeChessPieceGraphics();


private:

    sf::RectangleShape square_;

    sf::Sprite sprite_;

    sf::Color color_;

    sf::Texture texture_;

    sf::Vector2i gridPoint_;

};

#endif /* ChessGraphicsSquare_hpp */
