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
void promptForFilename(AccessRecord & filename);

void readFile()
{
   // declare the input stream
   ifstream fin("number.txt");

   if (fin.fail())
   {
      return;
   }

   // read the data
   string data;
   
   fin >> data;
   
   // close the stream
   fin.close();
   
   return;
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
   // user log data
   AccessRecord logData;

   promptForFilename(logData);

   // cout << "filename: " << logData.filename << endl; // 86

   // string data = readFile(logData.filename);

   // cout << data;

   return 0;
}

/**
 * PROMPT FOR FILENAME
 * Get the location of the user access records
 *    INPUT: filename [AccessRecord]
 */
void promptForFilename(AccessRecord & filename)
{
   // prompt user for location of the user access records
   cout << "Enter the access record file: ";
   // update AccessRecord.filename with location
   cin >> filename.filename;
}

