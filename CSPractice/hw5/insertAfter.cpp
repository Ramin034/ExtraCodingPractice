// insertAfter.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 5 - Problem # 3a


#include <iostream>
using namespace std;

/**
  * algorithm: takes five parameters and inserts a specific character right after a specific index.
  * 1. Accept inputCharacters, numElements, size, index, charToInsert which then pass through function
  * 2. if the numElements is less then or equal to size return false or if index is bigger than or equal to size
  * 3. when character is successfully inputed return true
  * 4. at index insert charToInsert after
  * Parameter: inputCharacters(char), numElements(int), size(int), index(int), charToInsert(char)
  * Return: true if value is successfully inserted into array; return false if array is full or index value exceeds
*/

bool insertAfter(char inputCharacters[], int numElements, int size, int index, char charToInsert)
{
    if(numElements>=size || index>=size) 
    {
        return false;
    }

    for(int i=numElements; i>index; i--)
    {
        inputCharacters[i+1] = inputCharacters[i]; //inputCharacters is added by 1 so the charToInsert inserts after
        inputCharacters[i]= charToInsert;
    }
    
    
    return true;
}



int main()
{
    int size = 5;
    char inputCharacters[size] = "cat";
    int numElements = 3;
    int index = 2;
    char charToInsert = 's';
    // result contains the value returned by insertAfter
    bool result = insertAfter(inputCharacters, numElements, size, index, charToInsert);
    // print result
    cout << "Function returned value: "<< result << endl;
    // print array contents
    for(int i = 0; i < size; i++)
    {
        cout << inputCharacters[i];
    }


}
