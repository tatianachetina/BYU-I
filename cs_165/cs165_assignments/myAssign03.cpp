/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics with Corrupt Files
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Prompt the user for the name of a file containing user access records.
*    Prompt the user for a start and end time for comparison. Display a list
*    of all files that were accessed during that period along with the users
*    who accessed them.
*
*    Estimated:  6.0 hrs   
*    Actual:     12.0 hrs
* Please describe briefly what was the most difficult part:
*    I struggled more with last week's assignment. The only thing that
*    tripped me up this week was figuring out how to iterate through the
*    array of records. I didn't know how to find the number of lines in
*    the file. I ended up creating a counter in the read function to keep
*    track of how many lines were read. Maybe there's a better way, but this
*    worked for me
************************************************************************/

#include <cassert>  // assert lib
#include <iostream> // console in/out statements (cin/cout)
#include <iomanip>  // we will use setw() in this example
#include <fstream>  // file in/out statements (fin/fout)
#include <string>   // to use string class
#include <sstream>  // used to parse a line
using namespace std;

// defines and consts
#define MAX_NUM_RECORDS 500

// structures
// access record
struct AccessRecord
{
   string filename;
   string username;
   long timestamp;
};

// user data
struct UserData
{
   string sourceFile;
   long startTime;
   long endTime;
};

// prototypes
void promptForFilename(UserData & file);
void parseFile(UserData & userData);
void parseLine(string line,
               AccessRecord logRecords[],
               int recordNumber) throw(string);
void promptForStartAndEndTimes(UserData & times);

/***********************************************************************
 * MAIN
 * This is the entry point and driver for the program.
 *    Vars: input [struct] - user-defined data and number of records
 *          logRecords [array] - access records: filename
 *                                               username
 *                                               timestamp
 ************************************************************************/
int main()
{
   // new instance of UserData
   UserData input;

   // get the source file name
   promptForFilename(input);
   // read access records from source file
   parseFile(input);
   // get start/end times
   promptForStartAndEndTimes(input);
   // display matched records on screen
   // displayAccessRecords(logRecords, input);

   return 0;
}

void promptForFilename(UserData & file)
{
   cout << "Enter the access record file: ";
   cin >> file.sourceFile;

   return;
}

void parseFile(UserData & userData)
{
   // number of lines in file
   int lineNumber = 0;

   // open the source file (convert string to c-string)
   ifstream fin(userData.sourceFile.c_str());

   // check for read errors
   if (fin.fail())
   {
      // tell user there's something wrong with the file
      cout << "invalid file: " << userData.sourceFile << endl;

      return;
   }

   string line;

   // read content to the end of the file one line at a time
   while (getline(fin, line))
   {
      // fin.ignore(256, '\n');
      AccessRecord logRecords[MAX_NUM_RECORDS];

      try
      {
         parseLine(line, logRecords, lineNumber);
      }
      catch (string text)
      {
         cout << "Error parsing line: " << text << endl;
      }

      // increment the count so we know how many records there are
      lineNumber++;
   }

   // close the read file
   fin.close();

   return;
}

void parseLine(string line,
               AccessRecord logRecords[],
               int recordNumber) throw(string)
{

   stringstream buffer(line);

   buffer >> logRecords[recordNumber].filename
          >> logRecords[recordNumber].username
          >> logRecords[recordNumber].timestamp;

   if (logRecords[recordNumber].timestamp < 1000000000 ||
       logRecords[recordNumber].timestamp > 10000000000)
   {
      throw line;
   }

}

void promptForStartAndEndTimes(UserData & times)
{
   cout << "\nEnter the start time: ";
   cin >> times.startTime;
   cout << "Enter the end time: ";
   cin >> times.endTime;

   return;
}
