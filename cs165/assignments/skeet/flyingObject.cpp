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
// FlyingObject :: FlyingObject(Point point, Velocity velocity) // : x(0.0), y(0.0)// taken from Point class. Needed?.?.
// {
//    setPoint(point); // ??? SWC
//    setVelocity(velocity); // ??? SWC
// }

/*****************************************************************************
 * SET POINT
 ****************************************************************************/
void FlyingObject :: setPoint(Point point)
{
   this -> point = point;
}

/*****************************************************************************
 * SET VELOCITY
 ****************************************************************************/
void FlyingObject :: setVelocity(Velocity velocity)
{
   this -> velocity = velocity;
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
