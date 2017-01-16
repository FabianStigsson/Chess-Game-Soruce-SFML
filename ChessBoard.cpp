//
// Created by Fabian J. Stigsson on 06/05/16.
//

#include "ChessBoard.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "SFML/Graphics.hpp"


ChessBoard::ChessBoard(int width, int height) {
    kingAlive_ = true;
    isPieceSelected_ = false;
    iswhitePlayerTurn_ = true;
    height_ = height;
    width_ = width;
    createGrid();
    createGraphicalGrid();
}

void ChessBoard::createGraphicalGrid() {

    graphicalSquares_ = new ChessGraphicsSquare **[8];


    for (int row = 0; row < 8; row++) {
        graphicalSquares_[row] = new ChessGraphicsSquare *[8];
        for (int col = 0; col < 8; col++) {


            int width = width_ / 8;
            int height = height_ / 8;

            int posX = width_ / 8 * col;
            int posY = height_ / 8 * row;

            sf::Color color;

            if (row % 2 == 0) {
                color = col % 2 != 0 ? sf::Color(223, 238, 239) : sf::Color(240, 181, 19);
            } else {
                color = col % 2 == 0 ? sf::Color(223, 238, 239) : sf::Color(240, 181, 19);
            }

            graphicalSquares_[row][col] = new ChessGraphicsSquare(width, height, posX, posY, col, row, color);

            if (!(isEmpty(col, row))) {

                sf::Texture texture;

                std::string color = chessPieces_[row][col]->isWhite() ? "Black" : "White";
                //
                texture.loadFromFile(
                        "/Users/Fabian/Desktop/chess/" + (color) + "_" + chessPieces_[row][col]->getPieceName() +
                        ".png");
                texture.setSmooth(true);

                graphicalSquares_[row][col]->setTexture(texture);

            }
        }
    }

}

void ChessBoard::createGrid() {

    chessPieces_ = new ChessPiece **[8];

    for (int row = 0; row < 8; row++) {

        chessPieces_[row] = new ChessPiece *[8];

        bool white = row == 0 || row == 1 ? false : true;

        for (int col = 0; col < 8; col++) {

            if (row <= 1 || row >= 6) {

                if (row == 1 || row == 6) {
                    chessPieces_[row][col] = new Pawn(white, "Pawn");
                } else if (row == 0 || row == 7) {

                    if (col == 0 || col == 7) {
                        chessPieces_[row][col] = new Rook(white, "Rook");
                    } else if (col == 1 || col == 6) {
                        chessPieces_[row][col] = new Bishop(white, "Bishop");
                    } else if (col == 2 || col == 5) {
                        chessPieces_[row][col] = new Knight(white, "Knight");
                    } else if (col == 3) {
                        chessPieces_[row][col] = new Queen(white, "Queen");
                    } else {
                        chessPieces_[row][col] = new King(white, "King");
                    }
                }

            } else {
                chessPieces_[row][col] = nullptr;
            }
        }
    }
}


void ChessBoard::movePiece(const MoveCommand &moveCommand) {

    if (chessPieces_[moveCommand.getToY()][moveCommand.getToX()] != nullptr) {
        // if piece is killed the memory of that chess peice is freed and set to 'nullptr'
        killPiece(moveCommand.getToX(), moveCommand.getToY());
    }
    // sets the new position in the array to point to the moved piece
    chessPieces_[moveCommand.getToY()][moveCommand.getToX()] = chessPieces_[moveCommand.getFromY()][moveCommand.getFromX()];

    chessPieces_[moveCommand.getFromY()][moveCommand.getFromX()] = nullptr;

    // updates the graphical squares to graphically show the move, this is done by setting the texture of the square which
    // the chess piece moved to, to its texture.
    graphicalSquares_[moveCommand.getToY()][moveCommand.getToX()]->setTexture(
            *(graphicalSquares_[moveCommand.getFromY()][moveCommand.getFromX()]->getSpriteOfSquare().getTexture()));
    // delets chess piece graphics of the square which the chess piece previously resided on
    graphicalSquares_[moveCommand.getFromY()][moveCommand.getFromX()]->removeChessPieceGraphics();

    // change turn when player has moved
    iswhitePlayerTurn_ = iswhitePlayerTurn_ ? false : true;

}

void ChessBoard::killPiece(int x, int y) {
    if (chessPieces_[y][x]->isKing()) {
        kingAlive_ = false;
    }
    delete chessPieces_[y][x];
    chessPieces_[y][x] = nullptr;
}

bool ChessBoard::checkMove(const MoveCommand &moveCommand, bool collide, bool attack) const {
    return chessPieces_[moveCommand.getFromY()][moveCommand.getFromX()]->checkMove(moveCommand.getDisplacementX(),
                                                                                   moveCommand.getDisplacementY(), collide, attack);
}

bool ChessBoard::isEmpty(int x, int y) const {
    return chessPieces_[y][x] == nullptr;
}


const sf::RectangleShape &ChessBoard::getSquareGraphics(int x, int y) const {
    return this->graphicalSquares_[y][x]->getGraphicsSquare();
}


const sf::Sprite &ChessBoard::getChessPieceGraphics(int x, int y) const {
    return this->graphicalSquares_[y][x]->getSpriteOfSquare();
}


ChessBoard::~ChessBoard() {
    for (int row = 0; row < 8; row++) {

        for (int col = 0; col < 8; col++) {
            delete chessPieces_[row][col];
            delete graphicalSquares_[row][col];
        }
        delete chessPieces_[row];
        delete graphicalSquares_[row];
    }

    delete[] graphicalSquares_;
    delete[] chessPieces_;

}

void  ChessBoard::select(int x, int y) {

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (graphicalSquares_[row][col]->contains(x, y)) {

                if (isPieceSelected_) {
                    MoveCommand command(selectedPieceCoord_.x, selectedPieceCoord_.y, col, row);
                    if (isValidCommand(command))
                        movePiece(command);

                    graphicalSquares_[selectedPieceCoord_.y][selectedPieceCoord_.x]->deselect();
                    isPieceSelected_ = false;

                } else {
                    selectedPieceCoord_ = sf::Vector2i(col, row);
                    graphicalSquares_[row][col]->select();
                    isPieceSelected_ = true;
                }

                return;
            }
        }
    }
}

void  ChessBoard::deselect(int x, int y) {

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (graphicalSquares_[row][col]->contains(x, y)) {
                graphicalSquares_[row][col]->deselect();
                isPieceSelected_ = false;
                return;
            }
        }
    }
}


bool ChessBoard::collides(const MoveCommand &command) const {

    int xDisplacement = command.getDisplacementX();
    int yDisplacement = command.getDisplacementY();


    int x = command.getFromX(), y = command.getFromY();

    int limitX = command.getToX(), limitY = command.getToY();

    // last square to check for collision is decremented with one, because we want to distinguish whether the
    // move is an attack, that is 'collides in its last step', which is done elsewhere
    if (xDisplacement != 0)
        limitX -= xDisplacement / abs(xDisplacement);
    if (yDisplacement != 0)
        limitY -= yDisplacement / abs(yDisplacement);

    // steps through all the steps and checks for collision
    while (y != limitY || x != limitX) {
        if (xDisplacement != 0)
            x += xDisplacement / abs(xDisplacement);
        if (yDisplacement != 0)
            y += yDisplacement / abs(yDisplacement);


        if (!isEmpty(x, y)) {
            return true;
        }

    }
    return false;
}


bool ChessBoard::isValidCommand(const MoveCommand &command) const {

    // if selected square is empty false is returned
    if (isEmpty(command.getFromX(), command.getFromY())) {
        return false;
    }

    bool attack = !isEmpty(command.getToX(), command.getToY());
    bool collision = collides(command);
    // is other player's turn
    if (iswhitePlayerTurn_ == (chessPieces_[command.getFromY()][command.getFromX()]->isWhite())) {
        return false;
        // player tries to kill own chess piece
    }
    if (attack && (iswhitePlayerTurn_ != (chessPieces_[command.getToY()][command.getToX()]->isWhite()))) {
        return false;
        // requested move is in line with the capacity of the chess piece which is requested to move
    } else if (checkMove(command, collision, attack)) {
        return true;
    }

    return false;
}


bool ChessBoard::isKingAlive() const {
    return kingAlive_;
}



