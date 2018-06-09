/***********************************************************************
 * Implementation File:
 *    LANDER : A class representing the lunar landscape
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything you needed to know about the lander but were afraid to ask
 ************************************************************************/

#include "lander.h"
// using namespace std;

/********************************************
 * LANDER :: CONSTRUCTOR
 ********************************************/
   Lander :: Lander()
   {
      setAlive(true);
      setLanded(false);
      setThrust(true);
      setFuel(500);
   }

   // setters
   void Lander :: setAlive(bool alive)
   {
      this -> alive = alive;
   }

   void Lander :: setLanded(bool landed)
   {
      this -> landed = landed;
   }

   void Lander :: setThrust(bool thrust)
   {
      this -> thrust = thrust;
   }

   void Lander :: setFuel(int fuel)
   {
      this -> fuel = fuel;
   }

   // methods
   bool Lander :: isAlive()
   {
      return alive;
   }

   bool Lander :: isLanded()
   {
      return landed;
   }

   bool Lander :: canThrust()
   {
      return thrust;
   }
   
   void Lander :: applyGravity(float gravity)
   {

   }

   void Lander :: applyThrustLeft()
   {

   }

   void Lander :: applyThrustRight()
   {

   }

   void Lander :: applyThrustBottom()
   {

   }

   void Lander :: advance()
   {

   }

   void Lander :: draw()
   {
      drawLander(landerPoint);
   }
