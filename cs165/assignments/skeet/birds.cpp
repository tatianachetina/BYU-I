/*****************************************************************************
 * Source File:
 *    Bird : The representation of a bird
 * Author:
 *    Scott Currell
 * Summary:
 *    Child bird class. Children (standard/tough/sacred) will inherit from this
 *    class.
 ****************************************************************************/

#include "birds.h"
#include <cassert>

/*****************************************************************************
 * HIT
 ****************************************************************************/
int Bird :: hit()
{
   kill();
   return 1;
}
