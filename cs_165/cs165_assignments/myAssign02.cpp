/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    [list summary here]
*
*    Estimated:  3.0 hrs   
*    Actual:     6.0 hrs
* Please describe briefly what was the most difficult part:
*    [list difficulties here]
************************************************************************/

#include <iostream>
#include <string> // to use string class
#include <fstream>
using namespace std;

// structures
struct AccessRecord
{
   string username;
   string filename;
   long timestamp;
};

// prototypes
string promptForFilename();

void readAccessRecords(string logFile)
{
   // // open the input stream to fileName
   ifstream fin(logFile.c_str()); // convert to c-string
   // // check for read errors
   if (fin.fail())
   {
      cout << "invalid file\n";
      return;
   }

   // word(s)
   string data;

   // loop through file until end
   while (fin >> data)
   {
      cout << data << endl;
   }

}

/***********************************************************************
 * Prompt the user for a 10-character DNA marker sequence, a number of
 * potential relatives, the names of each of these potential relatives, and
 * a 10-character DNA marker sequence of each of the potential relatives.
 * Display each potential relative along with the percentage that their
 * sequence matched the target user.
 ************************************************************************/
int main()
{
   // get the log file name
   string logFile = promptForFilename();

   // read access records
   readAccessRecords(logFile);

   return 0;
}

/**
 * PROMPT FOR FILENAME
 * Get the location of the user access records
 *    INPUT: filename [string]
 */
string promptForFilename()
{
   // prompt user for location of the user access records
   cout << "Enter the access record file: ";

   // log filename
   string filename;

   // update filename
   cin >> filename;

   return filename;
}
