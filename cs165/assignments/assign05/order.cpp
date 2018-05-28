/***************************************************************
 * File: order.cpp
 * Author: Scott Currell
 * Purpose: Contains the method implementations for the Order class.
 ***************************************************************/
#include "order.h"

// constructors
Order :: Order()
{
   quantity = 0;
}
Order :: Order(Product product,
               int quantity,
               Customer customer)
{
   setCustomer(customer);
   setProduct(product);
   setQuantity(quantity);
}

// Put your the method bodies for your order class here

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
void Order :: displayShippingLabel()
{
   cout << customer.getName() << endl
        << customer.getAddress().getStreet() << endl
        << customer.getAddress().getCity() << ", " << customer.getAddress().getState() << " " << customer.getAddress().getZip() << endl;
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
void Order :: displayInformation()
{
   cout << customer.getName() << endl
        << product.getName() << endl
        << "Total Price: $" << getTotalPrice() << endl;
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
Customer Order :: getCustomer()
{
   return customer;
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
Product Order :: getProduct()
{
   return product;
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
int Order :: getQuantity()
{
   return quantity;
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
string Order :: getShippingZip()
{
   return customer.getAddress().getZip();
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
float Order :: getTotalPrice()
{
   return product.getTotalPrice();
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
void Order :: setCustomer(Customer customer)
{
   this -> customer = customer;
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
void Order :: setProduct(Product product)
{
   this -> product = product;
}

/***************************************************************
 * DISPLAY
 * Add description here
 * INPUT: 
 ***************************************************************/
void Order :: setQuantity(int quantity)
{
   this -> quantity = quantity;
}
