/*****************************************************************************
 * Header File:
 *    Bird : The representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Child bird class. Children (standard/tough/sacred) will inherit from this
 *    class.
 ****************************************************************************/

#ifndef BIRD_H
#define BIRD_H

#include "flyingObject.h"

/*****************************************************************************
 * POINT
 * A single position.  
 ****************************************************************************/
class Bird : public FlyingObject
{
   private:

   public:
      virtual int hit();

};

#endif // BIRD_H
