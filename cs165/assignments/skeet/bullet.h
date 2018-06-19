/***********************************************************************
 * Header File:
 *    BULLET : A representation of a rilfe bullet
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything wee need to know about the bullet: how fast it's moving in
 *    along the X and Y axes.
 ************************************************************************/

#ifndef BULLET_H
#define BULLET_H

// #include "point.h"

/*********************************************
 * BULLET
 * A single position.  
 *********************************************/
class Bullet
{
private:
   Point bulletPoint;
   Velocity bulletVelocity;

public:
   // constructors
   Bullet();
   Bullet(Point, Velocity);
};

#endif // BULLET_H
