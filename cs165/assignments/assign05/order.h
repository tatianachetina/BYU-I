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
      Customer customer;
      Product product;
      int quantity;

   public:
      // default constructor
      Order();
      // non-default constructors
      Order(Product product,
            int quantity,
            Customer customer);
      // member methods
      void displayShippingLabel();
      void displayInformation();
      // getters
      Customer getCustomer();
      Product getProduct();
      int getQuantity();
      string getShippingZip();
      float getTotalPrice();
      // setters
      void setCustomer(Customer);
      void setProduct(Product);
      void setQuantity(int);
};

#endif
