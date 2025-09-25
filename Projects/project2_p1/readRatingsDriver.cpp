// readRatingsDriver.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 5


#include "User.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>
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

/**
 * algorithm: reads the Users and their ratings in a txt file
 * 1. Accepts filename, Users[], numUsersStored, usersArrSize, maxRatings which then pass through the function
 * 2. open file 
 * 3. if file doesn't open return -1
 * 4. if numUsersStored is equal to usersArrSize return -2
 * 5. if the file opens read the lines in the file using a loop
 * 6. call split function and store it into another array
 * 7. if line is empty skip it
 * 8. set username
 * 9. in a loop convert the ratings into integers and set the ratings with the values
 * Parameter: filename(string), Users(User), numUsersStored(int), usersArrSize(int), maxRating(int)
 * Return: return -2 if numUsersStored is equal to userArrSize, returns the number of users if file opens,
   returns -1 if file does not open
*/

int readRatings(string filename, User Users[], int numUsersStored, int usersArrSize, int maxRatings)
{
    

    ifstream fin;

    fin.open(filename);

    if(numUsersStored==usersArrSize)
    {
        return -2;
    }

    if(fin.is_open())
    {
        string line;
        string arr[maxRatings+1];
        int numsplits=0;
        int count=numUsersStored;
        while(getline(fin,line) && count<usersArrSize)
        {
            numsplits=split(line,',', arr, maxRatings+1);

            if(line=="")
            {
                continue;
            }
            if(numsplits>0)
            {
                Users[count].setUsername(arr[0]);   //sets the username where the string is saved
                for(int i=1; i<numsplits; i++)
                {
                    int value =stoi(arr[i]);    //converts the ratings in the array to integers
                    Users[count].setRatingAt(i-1,value);    //saves the ratings in Users[]

                }
                count++;
            }
        }
        return count;
    }
    else
    {
        return -1;
    }
}



int main()
{
    int user1;
    User users[50];

    readRatings("ratings.txt", users, 0, 50, 5);
    //cout<<users[0].getRatingAt(0)<<endl;
    //cout<<users[1].getUsername()<<endl;
    //cout<< users[1].getRatingAt(0)<<endl;
    
    
    // test case 1
    assert(users[0].getUsername()=="Alex");
    assert(users[0].getRatingAt(0)==1);
    //expected: all tests pass


    // test case 2
    assert(users[1].getUsername()=="Punith");
    assert(users[1].getRatingAt(0)==1);
    //expected: all tests pass

    // test case 3
    assert(users[2].getUsername()=="Ryan");
    assert(users[2].getRatingAt(0)==1);
    //expected: all tests pass

    assert(users[0].getRatingAt(1)==3);
    assert(users[1].getRatingAt(1)==3);
    


    
    cout<< "all tests pass"<<endl;

}