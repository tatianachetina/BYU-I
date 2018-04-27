#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>   // we will use setw() in this example
#include <cstdlib> // for atof()
using namespace std;

// prototypes
int getSize();
void getList(int list[], int size);
void displayMultiples(int list[], int size);

/**
 * MAIN
 * This is the entry point and driver for the program
 */
// int main()
// {
//    bool b = false || true && false || true;

//    // configure the output to display money for monthly income
//    cout.setf(ios::fixed);     // no scientific notation
//    cout.setf(ios::showpoint); // always show the decimal point
//    cout.precision(1);         // one decimals for cents

//    cout << b << endl;

//    return 0;
// }

char value = 'a';

int main()
{
   char value = 'b';

   if (true)
   {
      char value = 'c';
   }

   cout << value << endl;

   return 0;
}
