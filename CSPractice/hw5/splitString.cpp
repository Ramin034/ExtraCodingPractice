// splitString.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 5 - Problem # 4


#include <iostream>
using namespace std;

/**
  * algorithm: takes a string, splits it at every occurrence of a delimiter
  * 1. Accept inputString, separator, arr, size which then passes through the function
  * 2. if the string has a length bigger than 0 pass through loop
  * 3. find when the inputString has the separators and split it
  * 4. save the inputString into the array 
  * 5. everytime inputString has a separator in is count it.
  * 6. if count is bigger than or equal too size then return -1
  * 7. if their is nothing in the array return 0
  * Parameter: inputString(string), separator(char), arr(string), size(int)
  * Returns: return the number of pieces the string split into, if a delimiter isn't found return 1,
    if the string is empty return 0
*/


int split(string inputString, char separator, string arr[], int size)
{
    int savepoint=0;    //a savepoint and count is initialized.
    int count=0;
    for(int i=0; i<inputString.length(); i++)
    {
        if(inputString[i]==separator)
        {
            arr[count]=inputString.substr(savepoint, i-savepoint);  //each part of the string is saved into the array
            savepoint=i+1;
        }

        if(inputString[i]==separator)   //whenever a character in the string is the separator the count adds 1
        {
            count++; 
        }

        if(count>=size)
        {
            return -1;
        }
    }

     arr[count]=inputString.substr(savepoint);

    if(inputString.length()==0)
    {
        return 0;
    }

    return count+1;

}


int main()
{
    string testcase = "ABC DE FG";
    char separator = ' ';
    int size = 2;
    string arr[size];
    // numSplits is the value returned by split
    int numSplits = split(testcase, separator, arr, size);
    cout << "Function returned value: " << numSplits << endl;
    for (int i=0 ;i < size; i++){
    cout << "arr["<< i << "]:" << arr[i] << endl;
    }
}