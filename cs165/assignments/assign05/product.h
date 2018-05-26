/***************************************************************
 * File: product.h
 * Author: Scott Currell
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream> // console in/out statements (cin/cout)
#include <iomanip>  // we will use setw() in this example
#include <string>   // to use string class
using namespace std;

// product details and methods
class Product {
   private:
      // member variables
      string name;
      float basePrice;
      float weight;
      string description;

   public:
      // default constructor
      Product();
      // non-default constructors
      Product(string name,
              float basePrice,
              float weight,
              string description);
      // member methods
      void prompt();
      void diaplayAdvertising();
      void diaplayInventory();
      void diaplayReceipt();
      // getters
      float getSalesTax();
      float getShippingCost();
      float getTotalPrice();
      void getName();        // should these be voids?
      void getDescription(); // should these be voids?
      void getBasePrice();   // should these be voids?
      void getWeight();      // should these be voids?
      // setters
      void setName();        // should these be voids?
      void setDescription(); // should these be voids?
      void setBasePrice();   // should these be voids?
      void setWeight();      // should these be voids?
};

#endif
