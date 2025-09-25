#include "Movie.h"
#include "User.h"
#include "Blockbustr.h"
#include <fstream>
#include <iostream>
#include <string>
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
    do
    {
        int num=0;
        Blockbustr myBlockbustr;
        cout<<"======Main Menu=====\n"
        "1. Read movies\n"
        "2. Read ratings\n"
        "3. Print movies by year\n"
        "4. Get rating\n"
        "5. Find number of movies user rated\n"
        "6. Quit"<<endl;
        cin>>num;

        switch(num)
        {
        case 1: 
            cout<< "Enter a movie file name:"<<endl;
            cin>> filename;
            value=readMovies(filename,movies, numMovies, 50);
            if(value==-1)
            {
                cout<<"No movies saved to the database."<<endl;
            }
            else if(value==-2)
            {
                cout<< "Database is already full. No movies were added."<<endl;
            }
            else if(value==50)
            {
                cout<<"Database is full. Some movies may have not been added."<<endl;
            }
            else
            {
                cout<<"Total movies in the database: "<<value<<endl;
            }
            break;
        case 2:
            cout<<"Enter a user file name:"<<endl;
            cin>> filename;
            value=readRatings(filename,users,numUsers, 100, 50);
            if(value==)
        }
    } while (false);
    
}