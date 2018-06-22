/*****************************************************************************
 * Source File:
 *    Bullet : The representation of a bullet
 * Author:
 *    Scott Currell
 * Summary:
 *    Child bullet class.
 ****************************************************************************/

#include "bullet.h"
#include <cassert>

/*****************************************************************************
 * FIRE
 ****************************************************************************/
void Bullet :: fire(Point point, float angle)
{
   setPoint(point);

   Velocity velocity;

   velocity.setDx(cos((float)(180 - angle) * M_PI/180) * BULLET_SPEED);
   velocity.setDy(sin((float)(180 - angle) * M_PI/180) * BULLET_SPEED);

   setVelocity(velocity);
}
