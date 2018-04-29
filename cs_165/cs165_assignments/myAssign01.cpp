/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Walker, CS165
* Author:
*    Scott Currell
* Summary: 
*    Prompt the user for his/her DNA sequence, a number of relatives, their
*    names and respective DNA sequences, then compare each sequence to the
*    researcher's sequence. Return a percentage "match" score for each
*    relative.
*
*    Estimated:  3.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <string> // to use string class
using namespace std;

// prototypes
string getDNASequence();
int getNumRelatives();
void getRelativesNames(char relatives[][256],
                       int numRelatives);
void getRelativesDNASequences(char relatives[][256],
                              char dnaSequences[][11],
                              int numRelatives);
void matchDNASequences(char relatives[][256],
                       char dnaSequences[][11],
                       int numRelatives,
                       string dnaSequence);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   // base DNA sequence
   string dnaSequence = getDNASequence();
   // number of relatives
   int numRelatives = getNumRelatives();
   // names of relatives [max num possible relatives][names]
   char relatives[50][256];
   // relatives' DNA sequences [max num possible relatives][DNA sequences]
   char relativesDNASequences[50][11];

   getRelativesNames(relatives, numRelatives);
   getRelativesDNASequences(relatives, relativesDNASequences, numRelatives);
   matchDNASequences(relatives, relativesDNASequences, numRelatives, dnaSequence);

   return 0;
}

/**
 * GET DNA SEQUENCE
 * Prompt user for a DNA sequence as a base for comparison.
 * @return dnaSequence [String]
 */
string getDNASequence()
{
   // DNA sequence
   string dnaSequence;

   // prompt user for DNA sequence
   cout << "Enter your DNA sequence: ";
   // update DNA sequence with user-provided entry
   cin >> dnaSequence;

   // return DNA sequence
   return dnaSequence;
}

/**
 * GET NUMBER OF RELATIVES
 * Prompt user for a number of relatives.
 * @return numRelatives[Int]
 */
int getNumRelatives()
{
   // number of relatives
   int numRelatives;

   // prompt user for number of relatives
   cout << "Enter the number of potential relatives: ";
   // update number of relatives
   cin >> numRelatives;

   // return number of relatives
   return numRelatives;
}

/**
 * GET RELATIVES' NAMES
 * Prompt user for relatives' names
 * @return relatives[Array]
 */
void getRelativesNames(char relatives[][256],
                       int numRelatives)
{
   // start with a new line return
   cout << endl;

   // prompt user for 'n' number of names (based on what s/he provided) as a
   // number of relatives
   for(int i = 0; i < numRelatives; i++)
   {
      // prompt user for relatives' names
      cout << "Please enter the name of relative #" << i + 1 << ": ";
      // update array of names
      cin >> relatives[i];
   }

   // end function
   return;
}

/**
 * GET RELATIVES' DNA SEQUENCES
 * Prompt user for relatives' DNA sequences
 * @return dnaSequences[Array]
 */
void getRelativesDNASequences(char relatives[][256],
                              char dnaSequences[][11],
                              int numRelatives)
{
   // start with a new line return
   cout << endl;

   // prompt user for 'n' number of DNA sequences (based on what s/he
   // provided) as a number of relatives
   for(int i = 0; i < numRelatives; i++)
   {
      // prompt user for relatives' DNA sequences
      cout << "Please enter the DNA sequence for " << relatives[i] << ": ";
      // update array of names
      cin >> dnaSequences[i];
   }

   // end function
   return;
}

void matchDNASequences(char relatives[][256],
                       char dnaSequences[][11],
                       int numRelatives,
                       string dnaSequence)
{
   // start with a new line return
   cout << endl;

   int percentMatch = 0;

   for(int i = 0; i < numRelatives; i++)
   {
      for(int j = 0; j < 10; j++)
      {
         if(dnaSequences[i][j] == dnaSequence[j])
         {
            percentMatch++;
         }
      }
      cout << "Percent match for " << relatives[i] << ": " << percentMatch * 10 << "%\n";
      percentMatch = 0;
   }

   // end function
   return;
}
