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
   cout << top << '/' << bottom << endl;
}

void Rational :: displayDecimal()
{
   float fraction = (float)top / (float)bottom;

   cout << fraction << endl;
}
