// numValidNotes.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 1 - Problem # 3




#include <iostream>
using namespace std;

/**
  * algorithm: finds whether a the note is valid or invalid/True or false
  * 1. string note is passed through the function
  * 2. If the string meets and of the conditions it's invalid/false
  * 3. If none of the conditions are met the note is then valid
  * Parameters: note(string)
  * Returns: indication of whether the note is true or false
*/


bool isValidNote(string note)
{
    int len= note.length();
    if(len != 2)
    {
        return false;
    }
    if(int(note[0])>71 || int(note[0])<65) 
    {
        return false;
    }
    if(int(note[1])<48 || int(note[1])>57) 
    {
        return false;
    }
    return true;
}


/**
  * algorithm: finds the number of valid notes
  * 1. accept input which is passed to the function
  * 2. initialize variable for count
  * 3. string is put in for loop
  * 4. isValidNote is called and checks whether the input is true
  * 5. if the input is true then the count adds by 1
  * Parameters: input(string)
  * Returns: The number of valid notes in the string (int)
*/

    
int numValidNotes(string input)
{
    int count=0; 
    for(int i=0; i<input.length(); i++) //we're going through all the characters of the string
    {
        if(isValidNote(input.substr(i,2)))
        {
            count++;
        }
    }
    return count;
}


int main()
{
    cout<< numValidNotes("V0D2EF5L9M00") << endl;
    cout<< numValidNotes("AA2B3") << endl;
    cout<< numValidNotes("hello world") << endl;
    
}