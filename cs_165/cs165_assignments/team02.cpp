/***********************************************************************
* Program:
*    Team Activity 02, structs
*    Brother Walker, CS165
* Author:
*    Team #1 (Scott Currell)
* Summary: 
*    Display a scripture on screen. Then prompt the user for a new scripture
*    and display that new scripture on screen.
* ***********************************************************************/

#include <iostream>
using namespace std;

// structures
struct Scripture
{
   string book;
   int chapter;
   int verse;
};

// prototypes
void displayScripture(Scripture & passedScripture);
void promptScripture(Scripture & newScripture);

/**********************************************************************
 * Function: main
 * Purpose: Display a scripture on screen. Then prompt the user for a new
 *          scripture and display that new scripture on screen.
 ***********************************************************************/
int main()
{
   // new instance of Scripture data type called "initialScripture"
   Scripture initialScripture = {
      "Alma",
      31,
      5
   };

   // print initialScripture to the screen: Alma 31:5
   displayScripture(initialScripture);
   // prompt for new scripture
   promptScripture(initialScripture);
   // print new scripture to screen
   displayScripture(initialScripture);

   return 0;
}

/**********************************************************************
 * PROMPT USER FOR SCRIPTURE
 * Ask the user to provide a scripture
 * @param newScripture [Scripture]
 ***********************************************************************/
void promptScripture(Scripture & newScripture)
{
   // prompt for book
   cout << "Book: ";
   // update book
   cin >> newScripture.book;
   // prompt for chapter
   cout << "Chapter: ";
   // update chapter
   cin >> newScripture.chapter;
   // prompt for verse
   cout << "Verse: ";
   // update verse
   cin >> newScripture.verse;

   return;
}

/**********************************************************************
 * DISPLAY SCRIPTURE ON SCREEN
 * Receive a scripture as a parameter and print it on screen
 * @param passedScripture [Scripture]
 ***********************************************************************/
void displayScripture(Scripture & passedScripture)
{
   // print scripture to screen
   cout << passedScripture.book
        << ' '
        << passedScripture.chapter
        << ':'
        << passedScripture.verse
        << endl;

   return;
}
