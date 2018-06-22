/*****************************************************************************
 * Header File:
 *    FlyingObject : The representation of a flying object
 * Author:
 *    Scott Currell
 * Summary:
 *    Base flying object class. Children (bird/bullet) will inherit from this
 *    class.
 ****************************************************************************/

#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/*****************************************************************************
 * POINT
 * A single position.  
 ****************************************************************************/
class FlyingObject : public Point, public Velocity
{
   private:
      Point flyingObjectPoint;         // base object point
      Velocity flyingObjectVelocity;   // base object velocity
      bool alive;                      // base state: alive/dead

   public:
      // constructors
      // FlyingObject(); // ??? SWC
      // FlyingObject(Point, Velocity); // ??? SWC

      // getters
      Point getPoint()        const { return flyingObjectPoint; }
      Velocity getVelocity()  const { return flyingObjectVelocity; }
      bool isAlive()          const { return alive; }

      // setters
      void setPoint(Point);
      void setVelocity(Velocity);
      void setAlive(bool);

      // methods
      virtual void draw(); // ??? SWC
      virtual void advance(); // ??? SWC
      virtual void kill(); // ??? SWC
};

#endif // FLYINGOBJECT_H
