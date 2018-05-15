/***********************************************************************
* Program:
*    Checkpoint 04a, classes
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// classes
class Book
{
   // member variables
   public:
      string title;
      string author;

   // member functions (methods)
   public:
      void prompt(string &title, string &author);
};

// prototypes

void Book :: prompt(string &title, string &author)
{
   cout << "Title: ";
   getline(cin, title);
   cout << "Author: ";
   getline(cin, author);

   return;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // instantiate a Book object
   Book book;

   book.prompt(book.title, book.author);

   cout << "\"" << book.title << "\" by " << book.author << endl;
   
   return 0;
}
