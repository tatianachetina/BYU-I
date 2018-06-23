/*****************************************************************************
 * Source File:
 *    Bullet : The representation of a bullet
 * Author:
 *    Scott Currell
 * Summary:
 *    Child of FlyingObject class.
 ****************************************************************************/

#include "bullet.h"
#include <cassert>

/*****************************************************************************
 * BULLET - default constructor
 ****************************************************************************/
Bullet :: Bullet()
{
   setAlive(true);
}

/*****************************************************************************
 * DRAW
 ****************************************************************************/
void Bullet :: draw()
{
   drawDot(getPoint());
}

/*****************************************************************************
 * FIRE
 ****************************************************************************/
void Bullet :: fire(Point riflePoint, float angle)
{
   setPoint(riflePoint);

   Velocity velocity;

   velocity.setDx(cos((float)(180 - angle) * M_PI/180) * BULLET_SPEED);
   velocity.setDy(sin((float)(180 - angle) * M_PI/180) * BULLET_SPEED);

   setVelocity(velocity);
}
