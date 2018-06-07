/***********************************************************************
 * Header File:
 *    VELOCITY : The representation of a position on the screen
 * Author:
 *    Scott Currell
 * Summary:
 *    ... add summary ...
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
