/***********************************************************************
 * Header File:
 *    Velocity : The representation of a position on the screen
 * Author:
 *    Scott Currell
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/


#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>

/*********************************************
 * VELOCITY
 * A single position.  
 *********************************************/
class Velocity
{
private:
   Point position;
public:
   void draw();
};

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Velocity & pt);
std::istream & operator >> (std::istream & in,        Velocity & pt);

#endif // VELOCITY_H
