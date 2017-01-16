//
//  MoveCommand.hpp
//  Chess
//
//  Created by Fabian J. Stigsson on 08/05/16.
//  Copyright © 2016 Fabian J. Stigsson. All rights reserved.
//

#ifndef MoveCommand_hpp
#define MoveCommand_hpp

#include <stdio.h>

/**
 * A Move command class contains information about the 8x8 x, y coordinate from which a move is requested from and the
 *  8x8 x, y coordinate which a move is requested to.
 */
class MoveCommand {

public:
    /**
     * Creates a MoveCommand object.
     *
     * @param fromX the x location which the move starts at
     * @param fromY the y location which the move starts at
     * @param toX the x location which the move ends at
     * @param toY the y location which the move ends at
     */
    MoveCommand(int fromX, int fromY, int toX, int toY);

    /**
     * Default copy constructor
     */
    MoveCommand(const MoveCommand &other) = default;

    /**
     * Default destructor
     */
    virtual ~MoveCommand() = default;

    /**
     * @return the 8x8 x coordinate which the chess piece move from
     */
    int getFromX() const;

    /**
     * @return the 8x8 y coordinate which the chess piece move from
     */
    int getFromY() const;

    /**
     * @return the 8x8 x coordinate which the chess piece move to
     */
    int getToX() const;

    /**
     * @return the 8x8 y coordinate which the chess piece move to
     */
    int getToY() const;

    /**
     * @return the displacement on the x axis
     */
    int getDisplacementX() const;

    /**
     * @return the displacement on the y axis
     */
    int getDisplacementY() const;

private:

    int fromX_, fromY_, toX_, toY_, directionOffset_;


};


#endif /* MoveCommand_hpp */
