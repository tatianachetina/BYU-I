/***************************************************************
 * File: address.h
 * Author: Scott Currell
 * Purpose: Contains the definition of the Address class
 ***************************************************************/
#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream> // console in/out statements (cin/cout)
#include <iomanip>  // we will use setw() in this example
#include <string>   // to use string class
using namespace std;

// address details and methods
class Address {
   private:
      // member variables
      string street;
      string city;
      string state;
      string zip;

   public:
      // default constructor
      Address();
      // non-default constructors
      Address(string street,
              string city,
              string state,
              string zip);
      // member methods
      void display();
      // getters
      string getStreet();
      string getCity();
      string getState();
      string getZip();
      // setters
      void setStreet(string);
      void setCity(string);
      void setState(string);
      void setZip(string);
};

#endif
