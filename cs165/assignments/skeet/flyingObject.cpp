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
 * FLYINGOBJECT : CONSTRUCTOR WITH POINT, VELOCITY
 * Initialize the flyingObject to the passed parameters
 ****************************************************************************/
// taken from Point class. Needed?.?.
// FlyingObject::FlyingObject(Point flyingObjectPoint, Velocity flyingObjectVelocity) // : x(0.0), y(0.0)// taken from Point class. Needed?.?.
// {
//    setPoint(flyingObjectPoint); // ??? SWC
//    setVelocity(flyingObjectVelocity); // ??? SWC
// }

/*****************************************************************************
 * SET POINT
 ****************************************************************************/
void FlyingObject :: setPoint(Point point)
{
   flyingObjectPoint = point;
}

/*****************************************************************************
 * SET VELOCITY
 ****************************************************************************/
void FlyingObject :: setVelocity(Velocity velocity)
{
   flyingObjectVelocity = velocity;
} 

/*****************************************************************************
 * SET ALIVE
 ****************************************************************************/
void FlyingObject :: setAlive(bool alive)
{
   this -> alive = alive;
}

/*****************************************************************************
 * DRAW OBJECT
 ****************************************************************************/
void FlyingObject :: draw()
{
   drawCircle(getPoint(), 15);
}

/*****************************************************************************
 * KILL OBJECT
 ****************************************************************************/
void FlyingObject :: advance()
{
   flyingObjectPoint.addX(flyingObjectVelocity.getDx());
   flyingObjectPoint.addY(flyingObjectVelocity.getDy());
}

/*****************************************************************************
 * KILL OBJECT
 ****************************************************************************/
void FlyingObject :: kill()
{ 
   alive = false;
}
