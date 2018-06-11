/***********************************************************************
 * Implementation File:
 *    LANDER : A class representing the lunar landscape
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything you needed to know about the lander but were afraid to ask
 ************************************************************************/

#include "lander.h"
#include "game.h"

/********************************************
 * LANDER :: CONSTRUCTOR
 ********************************************/
   Lander :: Lander()
   {
      // set random location
      // found random function in uiDraw.cpp
      landerPoint.setX(random(-200, 200));
      landerPoint.setY(200); // TODO: set this to a const somewhere
      setAlive(true);
      setLanded(false);
      setThrust(true);
      setFuel(500); // TODO: set this to a const somewhere
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
      landerVelocity.setDy(landerVelocity.getDy() - gravity);
      landerPoint.addY(-1.0 * gravity);
   }

   void Lander :: applyThrustLeft()
   {
      if (thrust)
      {
         landerVelocity.setDx(landerVelocity.getDx() + 0.1);
         landerPoint.addX(0.1);
         fuel -= 1;
      }
   }

   void Lander :: applyThrustRight()
   {
      if (thrust)
      {
         landerVelocity.setDx(landerVelocity.getDx() - 0.1);
         landerPoint.addX(0.1);
         fuel -= 1;
      }
   }

   void Lander :: applyThrustBottom()
   {
      if (thrust)
      {
         landerVelocity.setDy(landerVelocity.getDy() + 0.3);
         landerPoint.addY(0.3);
         fuel -= 3;
      }
   }

   void Lander :: advance()
   {
      landerPoint.addY(landerVelocity.getDy());
      landerPoint.addX(landerVelocity.getDx());
   }

   void Lander :: draw()
   {
      drawLander(landerPoint);
   }
