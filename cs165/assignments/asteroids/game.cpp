/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include <cassert>
#include <vector>

#define OFF_SCREEN_BORDER_AMOUNT 5

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;



/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br)
{
   // Set up the initial conditions of the game
   score = 0;

   // Num rounds fired
   roundsFired = 0;

   // hit count
   hitCount = 0;

   // accuracy
   accuracy = 0;

   // TODO: Set your rock pointer to a good initial value (e.g., NULL)
   Rock * rock = NULL;
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently a rock allocated
   //       and if so, delete it.
   if(rock != NULL)
   {
      delete rock;
      rock = NULL;
   }

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceRock();

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet has left the screen
            bullets[i].kill();
         }
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE ROCK
 *
 * 1. If there is no rock, create one with some probability
 * 2. If there is a rock, and it's alive, advance it
 * 3. Check if the rock has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceRock()
{
   if (rock == NULL)
   {
      // there is no rock right now, possibly create one
      
      // "resurrect" it will some random chance
      if (random(0, 30) == 0)
      {
         // create a new rock
         rock = createRock();
      }
   }
   else
   {
      // we have a rock, make sure it's alive
      if (rock -> isAlive())
      {
         // move it forward
         rock -> advance();
         
         // check if the rock has gone off the screen
         if (!isOnScreen(rock -> getPoint()))
         {
            // We have missed the rock
            rock -> kill();
         }
      }
   }
   
}

/**************************************************************************
 * GAME :: CREATE ROCK
 * Create a rock of a random type according to the rules of the game.
 **************************************************************************/
Rock* Game :: createRock()
{
   Rock* newRock = NULL;

   // TODO: Fill this in
   switch(random(1, 4))
   {
      case 1:
         newRock = new Rock;
         break;
      case 2:
         newRock = new ToughRock;
         break;
      case 3:
         newRock = new SacredRock;
         break;
   }

   return newRock;
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a rock and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the rock is at this point (in case it was hit)
         if (rock != NULL && rock -> isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - rock -> getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - rock -> getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the rock
               int points = rock -> hit();
               score += points;
               
               // the bullet is dead as well
               bullets[i].kill();

               // hit count (NOT POINTS!!!)
               ++hitCount;

               // accuracy

               if (hitCount)
               {
                  assert(hitCount > 0);
                  accuracy = hitCount / roundsFired * 100;
               }
            }
         }
      } // if bullet is alive
      
   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate rock)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead rock
   if (rock != NULL && !rock -> isAlive())
   {
      // the rock is dead, but the memory is not freed up yet
      
      // TODO: Clean up the memory used by the rock
      delete rock;
      rock = NULL;   
   }
   
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...
         
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight())
   {
      rifle.moveRight();
   }
   
   // Check for "Spacebar
   if (ui.isSpace())
   {
      Bullet newBullet;
      newBullet.fire(rifle.getPoint(), rifle.getAngle());

      roundsFired++;
      
      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // draw the rock

   // TODO: Check if you have a valid rock and if it's alive
   // then call it's draw method
   if(rock != NULL && rock -> isAlive())
   {
      rock -> draw();
   }

   // draw the rifle
   rifle.draw();
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
   
   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   
   drawNumber(scoreLocation, score);

   // Rounds Fired Label
   Point roundsFiredLabel;
   roundsFiredLabel.setX(topLeft.getX() + 295);
   roundsFiredLabel.setY(topLeft.getY() - 15);

   drawText(roundsFiredLabel, "Rounds Fired: ");

   // Rounds Fired Value
   Point roundsFiredValue;
   roundsFiredValue.setX(topLeft.getX() + 380);
   roundsFiredValue.setY(topLeft.getY() - 5);

   drawNumber(roundsFiredValue, roundsFired);

   // Num Hits Label
   Point hitCountLabel;
   hitCountLabel.setX(topLeft.getX() + 295);
   hitCountLabel.setY(topLeft.getY() - 30);

   drawText(hitCountLabel, "Hits: ");

   // Num Hits Value
   Point hitCountValue;
   hitCountValue.setX(topLeft.getX() + 380);
   hitCountValue.setY(topLeft.getY() - 20);

   drawNumber(hitCountValue, hitCount);

   // Accuracy Label
   Point accuracyLabel;
   accuracyLabel.setX(topLeft.getX() + 295);
   accuracyLabel.setY(topLeft.getY() - 45);

   drawText(accuracyLabel, "Accuracy (%): ");

   // Accuracy Value
   Point accuracyValue;
   accuracyValue.setX(topLeft.getX() + 380);
   accuracyValue.setY(topLeft.getY() - 35);

   drawNumber(accuracyValue, accuracy);

}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}
*/
