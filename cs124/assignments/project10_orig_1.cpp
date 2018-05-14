/***********************************************************************
* Program:
*    Project 10, Calendar
*    Brother Schwieder, CS124
* Author:
*    Scott Currell
* Summary: 
*    The second part of the Mad Lib project: read the Mad Lib from a file and
*    prompt the user.
*
*    Estimated:  6 hrs   
*    Actual:     12 hrs
*
* Please describe briefly what was the most difficult part:
*    This one was brutal. What DIDN'T I have trouble with :)
*    Thank you so much for your help, Brother Schwieder!
*
************************************************************************/

#include <iostream>  // cin/cout statements
#include <fstream>   // to read from files
#include <cctype>    // for toupper and tolower
#include <cassert>   // use asserts
using namespace std;

// styleChecker doesn't like this formatting, but it's consistent with the
// book.
#define MAX_NUM_WORDS 256
#define MAX_NUM_LETTERS 33

int readFile(char story[][MAX_NUM_LETTERS]);
void askQuestions(char word[]);
void getFilename(char fileName[]);
void displayStory(char story[][MAX_NUM_LETTERS], int numOfWordsRead);
bool playAgain();
void replaceTokenPunct(char word[]);

/**********************************************************************
 * MAIN
 * Read words from a user-provided file and extract token phrases.
 ***********************************************************************/
int main()
{

   // start off true so the game plays at least once
   bool playGame = true;

   // play the game at least once, then loop back if the user wants to replay
   do
   {
      // the Mad Lib story
      char story[MAX_NUM_WORDS][MAX_NUM_LETTERS];
      // number of words in the story
      int numOfWordsRead = readFile(story);
      // display the updated story (with tokens replaced) on screen
      displayStory(story, numOfWordsRead);
      // ask the user if s/he wants to replay
      playGame = playAgain();
   }
   // continue loop if parameter == true
   while(playGame);

   return 0;
}

/**********************************************************************
 * READ FILE
 * Read the words from the file.  Make sure there is no more words in the
 * file than we have room in our array!
 *    INPUT:   filename, word array (story)
 *    OUTPUT:  updated word array (story) via pass-by-reference
 ***********************************************************************/
int readFile(char story[][MAX_NUM_LETTERS])
{
   // fetch the filename via user prompt
   char fileName[256];
   // get the file name
   getFilename(fileName);
   // open the file for reading
   // open the input stream to fileName
   ifstream fin(fileName);
   // check for read errors
   if (fin.fail())
   {
      cout << "ERROR: Unable to read file "
           // display the filename we tried to read
           << fileName
           << endl;
      // return the error condition: none read
      return 0;
   }

   // no words read at the start
   int numOfWordsRead = 0;
   // loop through the file, reading
   // the elements one at a time
   // don't read more than the list holds
   while (numOfWordsRead < MAX_NUM_WORDS &&
          // read and check for errors
          fin >> story[numOfWordsRead])
   {
      // prompt the user for a token
      askQuestions(story[numOfWordsRead]);
      // increment the index by one
      numOfWordsRead++;
   }
   
   // close the file and return
   fin.close();
   // report the number successfully read
   return numOfWordsRead;
}

/**********************************************************************
 * ASK QUESTIONS
 * Prompt the user for a question from the tokens in the Mad Lib file.
 *    INPUT:   word
 *    OUTPUT:  token phrase
 ***********************************************************************/
void askQuestions(char word[])
{
   // if word is not a token
   if (word[0] != '<' || !isalpha(word[1]))
   {
      return;
   }

   // print the first letter of the token phrase to the screen and capitalize
   cout << "\t" << (char)toupper(word[1]);

   // then every other letter that is not a closing angle bracket (>)
   for (int i = 2; word[i] != '>'; i++)
   {
      // replace underscores
      if (word[i] == '_')
      {
         // with a space
         cout << ' ';
      }
      else
      {
         // make sure the rest is lowercase
         cout << (char)tolower(word[i]);
      }
   }

   // close question with a colon
   cout << ": ";

   // collect the users answer
   cin.getline(word, MAX_NUM_LETTERS);

   return;
}

/*********************************************************************
 * GET FILENAME
 * Prompt the user for the name of the file and return it.
 *    OUTPUT: fileName (name of the file where Mad Lib is stored)
 *********************************************************************/
void getFilename(char fileName[])
{
   // prompt for a filename
   cout << "Please enter the filename of the Mad Lib: ";
   // write the filename back to the pointer
   cin >> fileName;
   // ignore new line characters
   cin.ignore();
   return;
}

/*
DISPLAY
 */
void displayStory(char story[][MAX_NUM_LETTERS], int numOfWordsRead)
{

   // put some space above the story
   cout << endl;

   // print each word of the story to the screen
   for(int i = 0; i < numOfWordsRead; i++)
   {
      // replace token placeholder for actual punctuation
      if (story[i][0] == '<' && !isalpha(story[i][1]))
      {
         replaceTokenPunct(story[i]);
      }

      // print word or puntuation
      if (story[i][0] == '<')
      {
         cout << story[i][1];
      }




      else
      {
         cout << story[i] << ' ';
      }
   }

   // put some space below the story
   cout << endl;

   return;
}

/**
 * IS PUNCTUATION
 */
void replaceTokenPunct(char word[])
{
   switch (word[1])
   {
      case '#':
         word[1] = '\n';
         break;
      case '{':
         word[1] = '"';
         break;
      case '}':
         word[1] = '"';
         break;
      case '[':
         word[1] = '\'';
         break;
      case ']':
         word[1] = '\'';
         break;
   }

   return;

   // bool punct;
   // ispunct(word) ? punct = true : punct = false;
   // return punct;
}

/**
 * PLAY AGAIN
 */
bool playAgain()
{
   // assume user doesn't want to play again (no one can play forever)
   bool replay = false;
   // y/n || Y/N
   char response;

   // ask the user if s/he wants to play again
   cout << "Do you want to play again (y/n)? ";
   // record the response
   cin >> response;
   
   // if y || Y, replay
   // if n || N, thank the user and quit
   switch (response)
   {
      case 'y':
      case 'Y':
         replay = true;
         break;
      case 'n':
      case 'N':
         replay = false;
         cout << "Thank you for playing.\n";
   }

   return replay;
}
