/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/








#ifndef GAME_H
#define GAME_H

#include <vector>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"







// my bullet and rock classes
#include "rocks.h"
// #include "bullet.h"

/*****************************************************************************
 * GAME
 * The main game class containing all the state
 ****************************************************************************/
class Game
{
public:
   /**************************************************************************
    * Constructor
    * Initializes the game
    *************************************************************************/
   Game(Point tl, Point br);
   ~Game();
   
   /**************************************************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *************************************************************************/
   void handleInput(const Interface & ui);
   
   /**************************************************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *************************************************************************/
   void advance();
   
   /**************************************************************************
    * Function: draw
    * Description: draws everything for the game.
    *************************************************************************/
   void draw(const Interface & ui);
   
private:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   int score;
   int roundsFired;
   int hitCount;
   int accuracy;

   // Rifle rifle;
   // std::vector<Bullet> bullets;
   
   // declare rock
   Rock * rock = new Rock;

   /**************************************************************************
    * Private methods to help with the game logic.
    *************************************************************************/
   bool isOnScreen(const Point & point);
   void advanceBullets();
   void advanceRock();
   Rock* createRock();
   
   void handleCollisions();
   void cleanUpZombies();
};

#endif /* GAME_H */
