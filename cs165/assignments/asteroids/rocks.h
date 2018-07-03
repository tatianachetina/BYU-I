/*****************************************************************************
 * Header File:
 *    Rocks : The representation of a rock
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of FlyingObject class.
 ****************************************************************************/

#ifndef rocks_h
#define rocks_h

#include "flyingObject.h"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

// Define the following classes here:
/*****************************************************************************
 * Rock
 ****************************************************************************/
class Rock : public FlyingObject
{
   public:
      Rock();
      Rock(Point);

      virtual void draw();
      virtual int hit();
};

/*****************************************************************************
 * BigRock
 ****************************************************************************/

/*****************************************************************************
 * MediumRock
 ****************************************************************************/

/*****************************************************************************
 * SmallRock
 ****************************************************************************/

#endif /* rocks_h */
