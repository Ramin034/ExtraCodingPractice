// videoGameStats.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 6 - Problem # 3

#include <iostream>
#include <fstream>
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

/*
 * algorithm: Finds the drivers and their stats
 * 1. Accepts string filename, string drivers[], int attributes[][3],int arrSize, int splits
      which then pass through the function
 * 2. If file is open call for split function
 * 3. If the number of splits is equal to 4 then read lines that fit requirements
 * 4. count the number of drivers
 * 5. if file could not open print error message
 * Parameters: filename(string), drivers[](string), attributes[][3](int), arrSize(int), splits(int)
 * Returns: Number of drivers in the array, -1 if file cant open    
*/

int readData(string filename, string drivers[], int attributes[][3],int arrSize, int splits)
{
    ifstream fin;

    fin.open(filename);

    if(fin.is_open())
    {
        string line;
        string arr[4];
        int numsplits=0;
        int count=0;
        
        while(getline(fin,line) && count<arrSize)
        {
            numsplits=split(line,',', arr, 4);  //saves the number of splits
            if(numsplits==4)
            {
                drivers[count]= arr[0];
                attributes[count][0]=stoi(arr[1]);  //turns the string in the array into integers
                attributes[count][1]=stoi(arr[2]);
                attributes[count][2]=stoi(arr[3]);
                count++;
            }
        }
        return count;   //returns the count
    }
    else
    {
        cout<<"Could not open file."<<endl;
        return -1;
    }

    fin.close();
    return 0;
}


int main()
{
    
    string filename = "game_sample.txt";
    // max number of splits
    int splits = 4;
    // number of drivers
    int numDrivers = 3;
    // call read data function
    string drivers[numDrivers];
    int attributes[numDrivers][3];
    int numLines = readData(filename, drivers, attributes, numDrivers, splits);
    if (numLines != -1)
    {
    cout << "Number of lines: " << numLines << "." << endl;
    // printNames will be provided for the Coderunner tests
    for(int i=0; i<numLines; i++)
    {
        cout<<drivers[i]<<endl;
        cout<< attributes[i][0]<<endl;
        cout<< attributes[i][1]<<endl;
        cout<<attributes[i][2]<<endl;
    }
       // printNames(drivers, numLines);
     //printAttributes will also be provided for the Coderunner tests
        //printAttributes(attributes, numLines);
    }
}