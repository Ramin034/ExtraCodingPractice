// Blockbustr.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 2 - Problem # 0



#include "User.h"
#include "Movie.h"
#include "Blockbustr.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

Blockbustr::Blockbustr()
{
    _numMovies=0;
    _numUsers=0;
}


//getters
int Blockbustr::getSizeMovie()
{
    return _sizeMovie;
}

int Blockbustr::getSizeUser()
{
    return _sizeUser;
}

int Blockbustr::getNumMovies()
{
    return _numMovies;
}

int Blockbustr::getNumUsers()
{
    return _numUsers;
}

//other member functions
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
  * algorithm:reads the movie and release date of each movie
  * 1. accepts filename which then pass through function
  * 2. opens file
  * 3. checks if the number of movies is equal to movie array size
  * 4. if file is open read each line in txt file
  * 5. call split function
  * 6. if the line is empty continue
  * 7. set title and release year into movies array
  * Parameters filename(string)
  * Returns: returns -2 if number of movies stored and Movie array size are equal, returns total number
    of movies in system, returns -1 if file does not open
*/


int Blockbustr::readMovies(string filename)
{
    
    ifstream fin;
    fin.open(filename);

    if(_numMovies==_sizeMovie)   // returns -2 if they are equal
    {
        return -2;  
    }

    if(fin.is_open())
    {
        string line;
        string arr[2];
        int numsplits=0;
        
        
        while(getline(fin,line) && _numMovies<_sizeMovie)
        {
            numsplits=split(line,',', arr, 2);  //call split to separate the string whenever a comma appears
            
            if(line=="")
            {
                continue;
            }
            if(numsplits==2)
            {
                _movies[_numMovies].setTitle(arr[0]); // sets the title for the movies
                _movies[_numMovies].setReleaseYear(arr[1]);   // sets the release date of the movies.
                _numMovies++;
            }
        }
        return _numMovies;
    }
    else
    {
        return -1;
    }
}


/**
 * algorithm: prints all movies in the given array which have a releaseYear matching the given year
 * 1. Accepts string year which then pass through the function
 * 2. if the number of movies stored is less then or equal to 0 print "No movies are stored"
 * 3. find whenever release year is equal to the year given
 * 4. print the movies in the given year
 * 5. if there are no movies that came out the given year print "There are no stored movies released in given year"
 * parameters: year(string)
 * Returns: nothing(void)
*/


void Blockbustr::printMoviesByYear(string year)
{
    if(_numMovies<=0)
    {
        cout<<"No movies are stored"<<endl;
        return;
    }
    int count=0;
    for(int i=0; i<_numMovies; i++)
    {
        if(_movies[i].getReleaseYear()==year)
        {
            if(count==0)
            {
                cout<< "Here is a list of movies released in "<< year <<endl;
            }
            cout<< _movies[i].getTitle()<<endl;
            count++;
        }
    }
    
    if(count==0)
    {
        cout<<"There are no stored movies released in "<< year<<endl;
    }
}


/**
 * algorithm: reads the Users and their ratings in a txt file
 * 1. Accepts filename which then pass through the function
 * 2. open file 
 * 3. if file doesn't open return -1
 * 4. if number of users stored is equal to the users array size return -2
 * 5. if the file opens read the lines in the file using a loop
 * 6. call split function and store it into another array
 * 7. if line is empty skip it
 * 8. set username
 * 9. in a loop convert the ratings into integers and set the ratings with the values
 * Parameter: filename(string)
 * Return: return -2 if numUsersStored is equal to userArrSize, returns the number of users if file opens,
   returns -1 if file does not open
*/


int Blockbustr::readRatings(string filename)
{
    ifstream fin;

    fin.open(filename);

    if(_numUsers==_sizeUser)
    {
        return -2;
    }

    if(fin.is_open())
    {
        string line;
        string arr[50+1];
        int numsplits=0;
        
        while(getline(fin,line) && _numUsers<_sizeUser)
        {
            numsplits=split(line,',', arr, 50+1);

            if(line=="")
            {
                continue;
            }
            if(numsplits>0)
            {
                _users[_numUsers].setUsername(arr[0]);   //sets the username where the string is saved
                for(int i=1; i<numsplits; i++)
                {
                    int value =stoi(arr[i]);    //converts the ratings in the array to integers
                    _users[_numUsers].setRatingAt(i-1,value);    //saves the ratings in Users[]

                }
                _numUsers++;
            }
        }
        return _numUsers;
    }
    else
    {
        return -1;
    }
    
    
}


/**
 * algorithm: finds the rating a user gave for a certain movie
 * 1. Accept username, title which then pass through the function
 * 2. initialize variables for rating, index, and the count.
 * 3. find what index the movie is located and saves it to index
 * 4. if the title is not found return -3
 * 5. Then find the username and find the rating at the specific index
 * parameters: username(string), title(string)
 * returns: returns -3 if title isn't found, returns the rating for specific movie
*/


int Blockbustr::getRating(string username, string title)
{
    int count=0;
    int index=0;
    int rating=-3;
    for(int i=0; i<_numMovies; i++)
    {
        if(caseinsensitive(_movies[i].getTitle(),title))
        {
            index= i;
        }   
    }
    if(!caseinsensitive(_movies[index].getTitle(),title))
    {
        return -3;
    }

    for(int i=0; i<_numUsers; i++)
    {
        if(caseinsensitive(_users[i].getUsername(),username))
        {
            rating = _users[i].getRatingAt(index);
        }
    }
    return rating;
    
}


/**
 * algorithm: finds the number of ratings a user has given
 * 1. Accepts username which then passes through the function
 * 2. check the username is equal to Users in the function
 * 3. if the number of movies stored is 0 return -3
 * 4. check through user array and find rating at a specific index the count
 * parameters: username(string)
 * Returns: returns -3 if user is not found and movies are not found, returns number of watched movies.
*/


int Blockbustr::getCountWatchedMovies(string username)
{
    int count=0;
    for(int i=0; i<_numUsers; i++)
    {
        if(caseinsensitive(_users[i].getUsername(),username))
        {
            if(_numMovies==0)
            {
                return -3;
            }
            for(int j=0; j<_numMovies; j++)
            {
                if(_users[i].getRatingAt(j)>0)
                {
                    count++;
                }
            }
            return count;
        }
    }
    return -3;
    
}

/**
 * algorithm: finds the average ratings of a specific movie
 * 1. Accepts title which passes through the function
 * 2. find the index of which a specific movie is located
 * 3. if movies does not exist return -3
 * 4. find all ratings for specific movie then add up the total
 * 5. add all ratings for movie then divide by the number of ratings
 * Parameter: title(string)
 * Return: the average of ratings for the movie, if movie is not found return -3, if the number of movies is 0 return 0;
*/

double Blockbustr::calcAvgRating(string title)
{
    double total=0.00;
    int count=0;
    int index=0;
    for(int i=0; i<_numMovies; i++)
    {
        if(caseinsensitive(_movies[i].getTitle(),title))
        {
            index= i;
        }   
    }
    if(!caseinsensitive(_movies[index].getTitle(),title))
    {
        return -3;
    }

    for(int i=0; i<_numUsers; i++)
    {
          
        if(_users[i].getRatingAt(index)>0)
        {
            total= total + _users[i].getRatingAt(index);
            count++;
        }
        
    }
    if(count==0)
    {
        return 0;
    }
    return total/count;
    
}


/**
 * algorithm: adds new user to the database
 * 1. Accepts username which then passes through the function
 * 2. sets the username
 * 3. if the new username is equal to a previous username return 0
 * 4. if the number of users is equal to the size of the users array then return -2
 * 5. set username after the number of original users
 * 6. also update the number of users and return 1 if successful
 * Parameters: username(string)
 * Returns: returns 1 if number of users is successfully updated, returns 0 if new username 
   is equal to previous usernames, returns -2 if number of users is equal to the users array.
*/


int Blockbustr::addUser(string username)
{
    User user;
    user.setUsername(username);
    for(int i=0; i<_numUsers; i++)
    {
      if(caseinsensitive(_users[i].getUsername(),username))
      {
          return 0;
      }
      if(_numUsers==_sizeUser)
      {
          return -2;
      }
    }
    int index=_numUsers;
    _users[index].setUsername(username);
    _numUsers++;
    return 1;
    
}


/**
 * algorithm: updates the rating of a movie for a user
 * 1. Accepts username, title, and rating which then pass through the function
 * 2. if the rating is not 0 to 5 return -4
 * 3. find the index in which the movie is located
 * 4. if the movie and user doesn't exist return -3
 * 5. if the username exists find the rating for the movie and update it 
 * 6. if it is succesfully updated return 1
 * Parameters: username(string), title(string), rating(int)
 * Returns: returns 1 if successfully updated, return -4 if the rating is not 0 to 5, return -3 if users and movies are not found
*/


int Blockbustr::rentMovie(string username, string title, int rating)
{
    int index=0;
    if(rating<0 || rating>5)
    {
        return -4;
    }
    for(int i=0; i<_numMovies; i++)
    {
        if(caseinsensitive(_movies[i].getTitle(),title))
        {
            index= i;
        }   
    }
    if(!caseinsensitive(_movies[index].getTitle(),title))
    {
        return -3;
    }

    for(int i=0; i<_numUsers; i++)
    {
        if(caseinsensitive(_users[i].getUsername(),username))
        {
            _users[i].setRatingAt(index,rating);
            return 1;
        }
    }
    return -3;
    
}