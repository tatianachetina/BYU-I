/***********************************************************************
 * Implementation File:
 *    VELOCITY : A class representing the lander's velocity
 * Author:
 *    Scott Currell
 * Summary:
 *    ... add summary ...
 ************************************************************************/

#include "velocity.h"
// using namespace std;

/********************************************
 * VELOCITY :: CONSTRUCTOR
 ********************************************/
   Velocity :: Velocity()
   {
      setDx(0.0);
      setDy(0.0);
   }

   Velocity :: Velocity(float xVelocity, float yVelocity)
   {
      setDx(xVelocity);
      setDy(yVelocity);
   }

   // getters
   float Velocity :: getDx()
   {
      return xVelocity;
   }

   float Velocity :: getDy()
   {
      return yVelocity;
   }

   // setters
   void Velocity :: setDx(float xVelocity)
   {
      this -> xVelocity = xVelocity;
   }

   void Velocity :: setDy(float yVelocity)
   {
      this -> yVelocity = yVelocity;
   }
