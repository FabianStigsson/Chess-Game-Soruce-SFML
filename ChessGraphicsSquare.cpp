//
//  ChessGraphicsSquare.cpp
//  Chess
//
//  Created by Fabian J. Stigsson on 09/05/16.
//  Copyright © 2016 Fabian J. Stigsson. All rights reserved.
//

#include "ChessGraphicsSquare.hpp"
#include "SFML/Graphics.hpp"


ChessGraphicsSquare::ChessGraphicsSquare(int sizeX, int sizeY, int xPos, int yPos, int gridXPos, int gridYPos,
                                         sf::Color color) {
    this->color_ = color;
    gridPoint_ = sf::Vector2i(gridXPos, gridYPos);
    square_.setSize(sf::Vector2f(sizeX, sizeY));
    square_.setPosition(xPos, yPos);
    square_.setFillColor(color);
    sprite_.setPosition(xPos, yPos);
}

void ChessGraphicsSquare::setTexture(const sf::Texture &texture) {
    this->texture_ = texture;
    this->sprite_.setTexture(texture_);
}

const sf::Sprite &ChessGraphicsSquare::getSpriteOfSquare() const {
    return this->sprite_;
}

const sf::RectangleShape &ChessGraphicsSquare::getGraphicsSquare() const {
    return this->square_;
}

bool ChessGraphicsSquare::contains(float x, float y) const {
    return square_.getGlobalBounds().contains(x, y);
}

void ChessGraphicsSquare::select() {
    square_.setFillColor(sf::Color(200, 200, 200));
}

void ChessGraphicsSquare::deselect() {
    square_.setFillColor(color_);
}

sf::Vector2i ChessGraphicsSquare::getSquareGridPoint() const {
    return gridPoint_;
}

void ChessGraphicsSquare::removeChessPieceGraphics() {
    sprite_.setTexture(sf::Texture());
}



