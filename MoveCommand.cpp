//
//  MoveCommand.cpp
//  Chess
//
//  Created by Fabian J. Stigsson on 08/05/16.
//  Copyright © 2016 Fabian J. Stigsson. All rights reserved.
//

#include "MoveCommand.hpp"


MoveCommand::MoveCommand(int fromX, int fromY, int toX, int toY){
    this -> fromX_ = fromX;
    this -> fromY_ = fromY;
    this -> toX_ = toX;
    this -> toY_ = toY;
}

int MoveCommand::getFromX() const{
    return this -> fromX_;
}

int MoveCommand::getFromY() const{
    return this -> fromY_;
}

int MoveCommand::getToX() const{
    return this -> toX_;
}

int MoveCommand::getToY() const{
    return this -> toY_;
}

int MoveCommand::getDisplacementX() const{
    return (this -> getToX() - this -> getFromX());
}

int MoveCommand::getDisplacementY() const{
    return (this -> getToY() - this -> getFromY());
}