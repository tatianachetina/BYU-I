/**********************************************************************
 * File: ta03.cpp
 * Author: Br. Burton
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Scripture
{
   string book;
   int chapter;
   int verse;
   int end;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture &scripture)
{
   cout << scripture.book << " ";
   cout << scripture.chapter << ":";
   cout << scripture.verse;
   if (scripture.end)
      cout << "-" << scripture.end;
}

void readFile(char filename[], Scripture &  scripture)
{
   string reference;
   
   ifstream fin(filename);

   getline(fin, reference);

//   cout << reference;
   
   stringstream buffer(reference);

   buffer >> scripture.book;
   buffer >> scripture.chapter;
   buffer >> scripture.verse;
   buffer >> scripture.end;
   if (buffer.fail())
      scripture.end = 0;
   
   fin.close();
   
   return;
}

/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
   // Insert your code here to prompt for the name of a file
   // and pass it to a readFile function
   char filename[256];
   Scripture scripture;
   
   cout << "Filename: ";
   cin >> filename;
   readFile(filename, scripture);
   display(scripture);
   
   return 0;
}
