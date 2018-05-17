/***************************************************************
 * File: rational.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"

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
   int topFactors[100];
   int topSize = 0;
   int bottomFactors[100];
   int bottomSize = 0;

   for (int i = 0; i < top; i++)
   {
      if (top % i == 0)
      {
         topFactors[topSize] = i;
         topSize++;
      }
   }

   for (int i = 0; i <= topSize; i++)
   {
      cout << topFactors[i] << endl;
   }

}
