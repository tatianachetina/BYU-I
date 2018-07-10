/*****************************************************************************
 * Header File:
 *    Rock : The representation of a rock
 * Author:
 *    Scott Currell
 * Summary:
 *    Rock class. Children will inherit from this class.
 ****************************************************************************/

#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"

/*****************************************************************************
 * ROCK
 ****************************************************************************/
class Rock : public FlyingObject
{
private:
   int radius;
public:
   // constructor
   Rock();
   // getters
   int getRadius() const { return radius; }
   // setters
   void setRadius();
   // methods
   virtual void draw();
   // virtual void hit();
   // virtual void kill();
};

/*****************************************************************************
 * BIG ROCK
 ****************************************************************************/
class BigRock : public Rock
{

};

/*****************************************************************************
 * MEDIUM ROCK
 ****************************************************************************/
class MediumRock : public Rock
{

};

/*****************************************************************************
 * SMALL ROCK
 ****************************************************************************/
class SmallRock : public Rock
{

};

#endif /* rocks_h */
