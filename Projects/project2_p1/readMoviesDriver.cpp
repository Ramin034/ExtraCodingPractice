// readMoviesDriver.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 2


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

    if(numMoviesStored==movieArrSize)   // returns -2 if they are equal
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
            numsplits=split(line,',', arr, 2);  //call split to separate the string whenever a comma appears
            
            if(line=="")
            {
                continue;
            }
            if(numsplits==2)
            {
                movies[count].setTitle(arr[0]); // sets the title for the movies
                movies[count].setReleaseYear(arr[1]);   // sets the release date of the movies.
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
    Movie movies[100];
    Movie movies2[100];
    Movie movies3[40];
    int numMovies=readMovies("movies.txt", movies, 0);

    //test case 1
    assert(numMovies==5);
    assert(movies[0].getTitle()=="Titanic");
    assert(movies[0].getReleaseYear()=="1997");
    //expected: all tests pass


    //test case 2
    assert(movies[4].getTitle()=="Garfield: A Tail of Two Kitties");
    assert(movies[4].getReleaseYear()=="2006");
    //expected: all tests pass


    //test case 3
    numMovies=readMovies("movies.txt", movies, 100, 100);
    assert(numMovies==-2);
    //expected: all tests pass

    //test case 4
    numMovies=readMovies("nofile.txt", movies, 0);
    assert(numMovies==-1);
    //expected: all tests pass


    //test case 5
    movies2[0].setTitle("John Wick");
    movies2[0].setReleaseYear("2014");
    numMovies=readMovies("Movies.txt", movies2, 1);
    assert(numMovies==6);
    assert(movies2[0].getTitle()=="John Wick");
    assert(movies2[0].getReleaseYear()=="2014");
    //expected: all tests pass


    //test case 6
    numMovies=readMovies("movies_50.txt", movies3, 0,40);
    assert(numMovies==40);
    assert(movies3[39].getTitle()=="Ayla: The Daughter of War");
    //expected: all tests pass
    


    cout<< "all test pass"<<endl;


}