/*****************************************************************************
 * Header File:
 *    Bullete : The representation of a bullet
 * Author:
 *    Scott Currell
 * Summary:
 *    Child bullet class.
 ****************************************************************************/

#ifndef BULLET_H
#define BULLET_H
#define BULLET_SPEED 10.0

#include "flyingObject.h"

/*****************************************************************************
 * POINT
 * A single position.  
 ****************************************************************************/
class Bullet : public FlyingObject
{
   private:

   public:
      void fire(Point, float);

};

#endif // BULLET_H
