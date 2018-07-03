/*********************************************************************
 * File: game.h
 * Author: Scott Currell
 * 
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>

// include classes
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"
#include "rocks.h"

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
   private:
      // The coordinates of the screen
      Point topLeft;
      Point bottomRight;

      // Declare a rock object
      Rock * rock = new Rock;

   public:
      /*********************************************
       * Constructor
       * Initializes the game
       *********************************************/
      Game(Point tl, Point br);
      ~Game();

      /*********************************************
       * Function: handleInput
       * Description: Takes actions according to whatever
       *  keys the user has pressed.
       *********************************************/
      void handleInput(const Interface & ui);
      
      /*********************************************
       * Function: advance
       * Description: Move everything forward one
       *  step in time.
       *********************************************/
      void advance();
      
      /*********************************************
       * Function: draw
       * Description: draws everything for the game.
       *********************************************/
      void draw(const Interface & ui);
};

#endif /* GAME_H */
