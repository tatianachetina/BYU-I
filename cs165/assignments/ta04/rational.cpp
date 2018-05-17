/***************************************************************
 * File: rational.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"
#include <cassert>
#include <iostream>
using namespace std;

// put your method bodies here
void Rational :: prompt()
{
   cout << "Top: ";
   cin >> top;
   cout << "Bottom: ";
   cin >> bottom;
}

void Rational :: display()
{
   if(top > bottom && top % bottom != 0)
   {
      cout << top / bottom << ' ' << top % bottom << '/' << bottom << endl;
   }
   else if(top > bottom)
   {
      cout << top / bottom << endl;
   }
   else
   {
      cout << top << '/' << bottom << endl;
   }
}

void Rational :: displayDecimal()
{
   float fraction = (float)top / (float)bottom;

   cout << fraction << endl;
}

void Rational :: multiplyBy()
{
   // Accepts another rational number and changes the value of the current
   // object (multiply the two numerators to get the new numerator and the two
   // denominators to get the new denominator).
}

void Rational :: reduce()
{
   // Reduces rational numbers to their most basic equivalent form (e.g., 2/6
   // becomes 1/3).
   int topFactors[10];
   int topSize = 0;
   int bottomFactors[10];
   int bottomSize = 0;

   for (int i = 0; i < top; i++)
   {
      assert(top > 0); // top num is positive
      if (top % i + 1 == 0)
      {
         assert(top % i + 1 == 0); // top num equls 0
         topFactors[topSize] = i + 1;
         assert(topFactors[topSize]); // num in array exists
         topSize++;
      }
   }

   for (int i = 0; i <= topSize; i++)
   {
      cout << topFactors[i] << endl;
   }

}
