// getCountWatchedMoviesDriver.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 7


#include "Movie.h"
#include "User.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;




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


int readRatings(string filename, User Users[], int numUserStored, int usersArrSize, int maxRatings)
{
    

    ifstream fin;

    fin.open(filename);

    if(numUserStored==usersArrSize)
    {
        return -2;
    }

    if(fin.is_open())
    {
        string line;
        string arr[maxRatings+1];
        int numsplits=0;
        int count=numUserStored;
        while(getline(fin,line) && count<usersArrSize)
        {
            numsplits=split(line,',', arr, maxRatings+1);

            if(line=="")
            {
                continue;
            }
            if(numsplits>0)
            {
                Users[count].setUsername(arr[0]);
                for(int i=1; i<numsplits; i++)
                {
                    int value =stoi(arr[i]);
                    Users[count].setRatingAt(i-1,value);

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



bool caseinsensitive(string upperuser, string loweruser)
{
    char up;
    char upper;
    if(upperuser.length()!=loweruser.length())
    {
        return false;
    }
    for(int i=0; i<upperuser.length(); i++)
    {
        up=upperuser.at(i);
        upper=loweruser.at(i);
        if(loweruser.at(i)>=97 && loweruser.at(i)<=122)
        {
            upper=loweruser.at(i)-32;
        }
        if(upperuser.at(i)>=97 && upperuser.at(i<=122))
        {
            up=upperuser.at(i)-32;
        }
        if(up!=upper)
        {
           return false;
        }
    }
    return true;
    
}


/**
 * algorithm: finds the number of ratings a user has given
 * 1. Accepts username, users, numUsersStored, and numMoviesStored which then passes through the function
 * 2. check the username is equal to Users in the function
 * 3. if the number of movies stored is 0 return -3
 * 4. check through user array and find rating at a specific index the count
 * parameters: username(string), users(User), numUsersStored(int), numMoviesStored(int)
 * Returns: returns -3 if user is not found and movies are not found, returns number of watched movies.
*/



int getCountWatchedMovies(string username, User users[], int numUsersStored, int numMoviesStored)
{   
    int count=0;
    for(int i=0; i<numUsersStored; i++)
    {
        if(caseinsensitive(users[i].getUsername(),username))
        {
            if(numMoviesStored==0)
            {
                return -3;
            }
            for(int j=0; j<numMoviesStored; j++)
            {
                if(users[i].getRatingAt(j)>0)
                {
                    count++;
                }
            }
            return count;
        }
    }
    return -3;
    
}

int main()
{
    User users[6];
    int numusers=0;
    int watchedmovies=0;

    //test case 1
    numusers = readRatings("ratings.txt", users, 0, 6, 5);
    watchedmovies=getCountWatchedMovies("Alex",users, numusers, 5);
    assert(watchedmovies==5);
    //expected success

    //test case 2
    numusers = readRatings("ratingfile.txt",users, 0, 6,3);
    watchedmovies= getCountWatchedMovies("User1", users, numusers, 3);
    assert(watchedmovies==3);
    //expected success


    // test case 3
    watchedmovies= getCountWatchedMovies("USeR2", users, numusers, 3);
    assert(watchedmovies==2);
    //expected success

    //test case 4
    watchedmovies= getCountWatchedMovies("user3", users, numusers, 3);
    assert(watchedmovies==0);
    //expected success

    //test case 5
    watchedmovies= getCountWatchedMovies("User4", users, numusers, 3);
    assert(watchedmovies==-3);
    //expected success
    
    
    cout<<"success"<<endl;
}