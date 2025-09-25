// isValidNote.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 1 - Problem # 1



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

int main()
{
    //test 1 for if note is true or false
    cout<< boolalpha <<  isValidNote("C8") <<endl;
    //test 2 for if note is true or false
    cout<< isValidNote("c4") <<endl;
    //test 3 for if note is true or false
    cout<< isValidNote("H4") <<endl;
    //test 4 for if note is true or false
    cout<< isValidNote("C0") <<endl;
    //test 5 for if note is true or false
    cout<< isValidNote("C23") <<endl;
    return 0;
}