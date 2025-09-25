// isValidTune.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 1 - Problem # 2




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
  * algorithm: finds whether or not a given string length is a valid SPN.
  * 1. string input passes through function
  * 2. if string length is odd then it's false
  * 3. string is put in a for loop
  * 4. the input is then tested in pairs in the isValidNote
  * 5. if the input is false in isValidNote then return false
  * 6. if string length is even and the input is true in isValidNote then it's true
  * Parameters: input(string)
  * Returns: indication of whether the input is true or false
*/

bool isValidTune(string input)
{
    if(input.length() % 2 == 1 || input== "")
    {
        return false;
    }
    for(int i=0; i<input.length() / 2; i=i+2)
    {
        if(!isValidNote(input.substr(i,2)))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //test 1 to see if tune is true or false
    cout<< boolalpha <<  isValidTune("C8") <<endl;
    //test 2 to see if tune is true or false
    cout<< isValidTune("A4B2E1D7") <<endl;
    //test 3 to see if tune is true or false
    cout<< isValidNote("H4") <<endl;
    //test 4 to see if tune is true or false
    cout<< isValidNote("C23") <<endl;
    return 0;
}