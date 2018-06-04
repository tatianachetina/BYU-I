/***********************************************************************
 * Header File:
 *    Lander : The representation of a position on the screen
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef LANDER_H
#define LANDER_H

#include <iostream>

/*********************************************
 * LANDER
 * A single position.  
 *********************************************/
class Lander
{
private:
   Point position;

public:
   Lander()
   {

   }

   Point getPoint();
   Velocity getVelocity();

   int getFuel();
   
   bool isAlive();
   bool isLanded();
   bool canThrust();
   
   void setLanded(bool);
   void setAlive(bool);
   void setFuel(int);
   void applyGravity(float);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();
   void advance();
   void draw();
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Lander & pt);
std::istream & operator >> (std::istream & in,        Lander & pt);

#endif // LANDER_H
