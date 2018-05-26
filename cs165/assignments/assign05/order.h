/***************************************************************
 * File: order.h
 * Author: Scott Currell
 * Purpose: Contains the definition of the Order class
 ***************************************************************/
#ifndef ORDER_H
#define ORDER_H

#include <iostream>  // console in/out statements (cin/cout)
#include <iomanip>   // we will use setw() in this example
#include <string>    // to use string class
#include "product.h"
#include "customer.h"
using namespace std;

// order details and methods
class Order {
   private:
      // member variables
      int quantity;
      Product product;
      Customer customer;

   public:
      // default constructor
      Order();
      // non-default constructors
      Order(int quantity,
            Product product,
            Customer customer);
      // member methods
      void displayShippingLabel();
      void displayInformation();
      // getters
      void getProduct();     // should these be voids?
      void getQuantity();    // should these be voids?
      void getCustomer();    // should these be voids?
      void getShippingZip(); // should these be voids?
      void getTotalPrice();  // should these be voids?
      // setters
      void setProduct();     // should these be voids?
      void setQuantity();    // should these be voids?
      void setCustomer();    // should these be voids?
};

#endif
