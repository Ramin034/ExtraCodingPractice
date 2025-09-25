// getRatingDriver.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 6


#include "Movie.h"
#include "User.h"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
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


/**
  * algorithm:reads the movie and release date of each movie
  * 1. accepts filename, movies, numMoviesStored, int movieArrSize which then pass through function
  * 2. opens file
  * 3. checks if numMoviesStored is equal to movieArrSize
  * 4. if file is open read each line in txt file
  * 5. call split function
  * 6. if the line is empty continue
  * 7. set title and release year into movies array
  * Parameters filename(string), movies(Movies), numMoviesStored(int), movieArrSize(int)
  * Returns: returns -2 if numMoviesStored and MovieArrSize are equal, returns total number
    of movies in system, returns -1 if file does not open
*/


int readMovies(string filename, Movie movies[], int numMoviesStored, int movieArrSize=100)
{
    ifstream fin;
    fin.open(filename);

    if(numMoviesStored==movieArrSize)
    {
        return -2;
    }

    if(fin.is_open())
    {
        string line;
        string arr[2];
        int numsplits=0;
        int count=numMoviesStored;
        while(getline(fin,line) && count<movieArrSize)
        {
            numsplits=split(line,',', arr, 2);
            
            if(line=="")
            {
                continue;
            }
            if(numsplits==2)
            {
                movies[count].setTitle(arr[0]);
                movies[count].setReleaseYear(arr[1]);
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
 * algorithm: finds the rating a user gave for a certain movie
 * 1. Accept username, title, users, movies, numUsersStored, numMoviesStored which then pass through the function
 * 2. initialize variables for rating, index, and the count.
 * 3. find what index the movie is located and saves it to index
 * 4. if the title is not found return -3
 * 5. Then find the username and find the rating at the specific index
 * parameters: (username(string), title(string), users(User), movies(Movie), numUsersStored(int), numMoviesStored(int))
 * returns: returns -3 if title isn't found, returns the rating for specific movie
*/

int getRating(string username, string title, User users[], Movie movies[], int numUsersStored, int numMoviesStored)
{
    int count=0;
    int index=0;
    int rating=-3;
    for(int i=0; i<numMoviesStored; i++)
    {
        if(caseinsensitive(movies[i].getTitle(),title))
        {
            index= i;
        }   
    }
    if(!caseinsensitive(movies[index].getTitle(),title))
    {
        return -3;
    }

    for(int i=0; i<numUsersStored; i++)
    {
        if(caseinsensitive(users[i].getUsername(),username))
        {
            rating = users[i].getRatingAt(index);
        }
    }
    return rating;
    
}


int main()
{
    User users[50];
    Movie movies[50];
    int rating=0;
    //test case 1 
    rating = getRating("Alex", "Titanic", users, movies, 0, 0);
    assert(rating==-3);
    //expected success


    readRatings("ratings.txt", users, 0, 50, 5);
    readMovies("movies.txt", movies, 0);

    //test case 2
    rating=getRating("alex", "WHiplash", users, movies, 4, 5);
    assert(rating== 3);
    //expected success

    //test case 3
    rating=getRating("punith","johN wick", users, movies,4,5);
    assert(rating==-3);
    //expected success


    //assert(caseinsensitive("PunITh", "pUNiTh"));
    //assert(!caseinsensitive("puNiTh", "puMith"));

    //assert(!caseinsensitive("Tomas","Tom"));

    cout<<"success"<<endl;
}