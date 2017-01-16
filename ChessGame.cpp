//
//  ChessGame.cpp
//  Chess
//
//  Created by Fabian J. Stigsson on 06/05/16.
//  Copyright © 2016 Fabian J. Stigsson. All rights reserved.
//

#include "ChessGame.hpp"


ChessGame::ChessGame(int width, int height) {
    this -> width_ = width;
    this -> height_ = height;
    chessWindow_ = new sf::RenderWindow(sf::VideoMode(width, height), "Chess", sf::Style::Close);
    chessBoard_ = new ChessBoard(width, height);
    startGraphics();
}

ChessGame::~ChessGame() {
    delete chessWindow_;
    delete chessBoard_;
}

void ChessGame::startGraphics() {
    

    while (chessWindow_->isOpen()) {
        // Process events
        sf::Event event;

        while (chessWindow_->pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                chessWindow_->close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                chessWindow_->close();
            }
            // selects a chess piece and sends the location of the click to the select | deselect function, which
            // validates movement and keep track on whose turn it is etc
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i clickLocation = sf::Mouse::getPosition(*chessWindow_);
                if (event.mouseButton.button == sf::Mouse::Right) {
                    chessBoard_->deselect(clickLocation.x, clickLocation.y);
                } else {
                    chessBoard_->select(clickLocation.x, clickLocation.y);
                }

            }

        }

       //. chessWindow_->clear(sf::Color::Black);
        
        

        if (chessBoard_->isKingAlive())
            renderChessBoard();
        else {
            // restarts the game
            delete chessBoard_;
            chessBoard_ = new ChessBoard(width_, height_);
            

        }
        // Update the window
        
        chessWindow_->display();
    }

}

void ChessGame::renderChessBoard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            chessWindow_->draw(chessBoard_->getSquareGraphics(col, row));
            chessWindow_->draw(chessBoard_->getChessPieceGraphics(col, row));

        }
    }
}








