// printMoviesByYearDriver.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 3


#include "Movie.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
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
 * algorithm: prints all movies in the given array which have a releaseYear matching the given year
 * 1. Accepts Movie movies, int numMoviesStored, string year which then pass through the function
 * 2. if the number of movies stored is less then or equal to 0 print "No movies are stored"
 * 3. find whenever release year is equal to the year given
 * 4. print the movies in the given year
 * 5. if there are no movies that came out the given year print "There are no stored movies released in given year"
 * parameters: movies(Movie), numMoviesStored(int), year(string)
 * Returns: nothing(void)
*/

void printMoviesByYear(Movie movies[],int numMoviesStored, string year)
{
    if(numMoviesStored<=0)
    {
        cout<<"No movies are stored"<<endl;
        return;
    }
    int count=0;
    for(int i=0; i<numMoviesStored; i++)
    {
        if(movies[i].getReleaseYear()==year)
        {
            if(count==0)
            {
                cout<< "Here is a list of movies released in "<< year <<endl;
            }
            cout<< movies[i].getTitle()<<endl;
            count++;
        }
    }
    
    if(count==0)
    {
        cout<<"There are no stored movies released in "<< year<<endl;
    }
    
    
}


int main()
{
    Movie m1[50];
    int numMovies=readMovies("movies_50.txt", m1, 0);

    //test case 1
    printMoviesByYear(m1, 50,"2006");
    /*expected: Here is a list of movies released in 2006
    The Prestige
    The Departed
    The Lives of Others
    */

   //test case 2
   printMoviesByYear(m1,50,"1998");
   /* expected: Here is a list of movies released in 1998
      Saving Private Ryan
   */
    

    //test case 3
    printMoviesByYear(m1,50, "2022");
    // expected: There are no stored movies released in 2022

}