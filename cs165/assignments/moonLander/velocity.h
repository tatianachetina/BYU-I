/***********************************************************************
 * Header File:
 *    Velocity : The representation of a position on the screen
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include "point.h"

/*********************************************
 * VELOCITY
 * A single position.  
 *********************************************/
class Velocity
{
private:
   float x;
   float y;

public:
   // constructors
   Velocity()
   {

   }

   Velocity(float x, float y)
   {

   }

   float getDx();
   float getDy();
   void setDx(float);
   void setDy(float);
};

#endif // VELOCITY_H
