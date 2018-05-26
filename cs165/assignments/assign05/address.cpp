/***************************************************************
 * File: address.cpp
 * Author: Scott Currell
 * Purpose: Contains the method implementations for the Address class.
 ***************************************************************/
#include "address.h"

// constructors
Address :: Address()
{
   street = "unknown";
   city   = "";
   state  = "";
   zip    = "00000";
}
Address :: Address(string street,
                   string city,
                   string state,
                   string zip)
{
   setStreet(street);
   setCity(city);
   setState(state);
   setZip(zip);
}

// Put your method bodies for the address class here

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
void Address :: display()
{
   cout << street << endl
        << getCity() << ", " << getState() << " " << getZip() << endl;
}

/***************************************************************
 * GET STREET
 * Add description here
 * INPUT: 
 ***************************************************************/
string Address :: getStreet()
{
   return street;
}

/***************************************************************
 * GET CITY
 * Add description here
 * INPUT: 
 ***************************************************************/
string Address :: getCity()
{
   return city;
}

/***************************************************************
 * GET STATE
 * Add description here
 * INPUT: 
 ***************************************************************/
string Address :: getState()
{
   return state;
}

/***************************************************************
 * GET ZIP
 * Add description here
 * INPUT: 
 ***************************************************************/
string Address :: getZip()
{
   return zip;
}

/***************************************************************
 * SET STREET
 * Add description here
 * INPUT: 
 ***************************************************************/
void Address :: setStreet(string street)
{
   this -> street = street;
}

/***************************************************************
 * SET CITY
 * Add description here
 * INPUT: 
 ***************************************************************/
void Address :: setCity(string city)
{
   this -> city = city;
}

/***************************************************************
 * SET STATE
 * Add description here
 * INPUT: 
 ***************************************************************/
void Address :: setState(string state)
{
   this -> state = state;
}

/***************************************************************
 * SET ZIP
 * Add description here
 * INPUT: 
 ***************************************************************/
void Address :: setZip(string zip)
{
   this -> zip = zip;
}
