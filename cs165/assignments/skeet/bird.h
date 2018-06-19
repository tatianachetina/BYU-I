/***********************************************************************
 * Header File:
 *    BIRD : A representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything wee need to know about the bird: how fast it's moving in
 *    along the X and Y axes.
 ************************************************************************/

#ifndef BIRD_H
#define BIRD_H

// #include "point.h"

/*********************************************
 * BIRD
 * A single position.  
 *********************************************/
class Bird
{
private:
   Point birdPoint;
   Velocity birdVelocity;

public:
   // constructors
   Bird();
   Bird(Point, Velocity);
};

#endif // BIRD_H
