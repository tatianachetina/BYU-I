/***************************************************************
 * File: customer.cpp
 * Author: Scott Currell
 * Purpose: Contains the method implementations for the Customer class.
 ***************************************************************/
#include "customer.h"

// constructors
Customer :: Customer()
{
   name    = "unspecified";
   address = Address(); // the address's default constructor
}
Customer :: Customer(string name,
                     Address address)
{
   setName(name);
   setAddress(address);
}

// Put the method bodies for your customer class here

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
void Customer :: display()
{
   cout << getName() << endl;
   address.display();
}

/***************************************************************
 * GET NAME
 * Add description here
 * INPUT: 
 ***************************************************************/
string Customer :: getName()
{
   return name;
}

/***************************************************************
 * GET ADDRESS
 * Add description here
 * INPUT: 
 ***************************************************************/
Address Customer :: getAddress()
{
   return address;
}

/***************************************************************
 * SET NAME
 * Add description here
 * INPUT: 
 ***************************************************************/
void Customer :: setName(string name)
{
   this -> name = name;
}

/***************************************************************
 * SET ADDRESS
 * Add description here
 * INPUT: 
 ***************************************************************/
void Customer :: setAddress(Address address)
{
   this -> address = address;
}
