// insertConsonants.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 5 - Problem # 3b


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
        inputCharacters[i+1] = inputCharacters[i];
        inputCharacters[i]= charToInsert;
    }
    
    
    return true;
}

bool isconsonant(char conson)   //this function is created to see if the inputCharacter is a consonant
{
    switch(conson)
    {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return false;
        default:
            return true;
    }
    

}

/**
  * algorithm: find consonants and insert capitalized versions of them right after the consonant
  * 1. accept inputCharacters, numElements, size, numConsonants which then runs through function
  * 2. if numElements is bigger  than size or numConsonants+numElements is bigger than size, return the number of elements 
  * 3. Create another function(isconsonant) to find all values that are consonants
  * 4. if inputCharacters is a consonant call insertAfter and insert consonants.
  * Parameters: inputCharacters(char), numElements(int), size(int), numConsonants(int)
  * Returns: number of elements in array after the consonants are added or original number of elements.
*/

int insertConsonants(char inputCharacters[], int numElements, int size, int numConsonants)
{
    if(numElements>size || numConsonants+numElements>size)
     {
        return numElements;
     }

    for(int i=0; i<numElements; i++)
    {
        if(isconsonant(inputCharacters[i]))
        {
            insertAfter(inputCharacters, numElements, size, i, inputCharacters[i]- 32);
            i++;
            numElements++;
        }
    }
    return numElements;
}


int main()
{
    int size = 5;
    char inputCharacters[size] = "cat";
    int numElements = 3;
    int numConsonants = 2;
    // updating numElements with the updated value returned by insertConsonants
    numElements = insertConsonants(inputCharacters, numElements, size, numConsonants);
    // print numElements
    cout << "Function returned value: " << numElements << endl;
    // print array contents
    for(int i = 0; i < size; i++)
    {
        cout << inputCharacters[i];
    } 

}
