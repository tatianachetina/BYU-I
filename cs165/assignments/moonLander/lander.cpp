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
   // Lander :: Lander()
   // {
      
   // }

   // setters
   void Lander :: setLanded(bool landed)
   {

   }

   void Lander :: setAlive(bool alive)
   {

   }

   void Lander :: setFuel(int fuel)
   {

   }

   // methods
   bool Lander :: isAlive()
   {
      return true;
   }

   bool Lander :: isLanded()
   {
      return false;
   }

   bool Lander :: canThrust()
   {
      return true;
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
