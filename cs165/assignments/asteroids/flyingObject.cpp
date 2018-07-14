/*****************************************************************************
 * Source File:
 *    FlyingObject : The representation of a flying object
 * Author:
 *    Scott Currell
 * Summary:
 *    Base flying object class. Children (bird/bullet) will inherit from this
 *    class.
 ****************************************************************************/

#include "flyingObject.h"
#include <cassert>

/*****************************************************************************
 * DRAW OBJECT
 ****************************************************************************/
// void FlyingObject :: draw()
// {
//    drawCircle(getPoint(), 15);
// }

/*****************************************************************************
 * KILL OBJECT
 ****************************************************************************/
void FlyingObject :: advance(int screenSize)
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
}

/*****************************************************************************
 * KILL OBJECT
 ****************************************************************************/
void FlyingObject :: kill()
{ 
   alive = false;
}
