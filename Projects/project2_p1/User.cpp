// User.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 4



#include "User.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

User::User()
{
    _username="";
    _numRatings=0;
    for(int i=0; i<size;i++)    //loop allows array to initialize to 0
    {
        _ratings[i]= 0;
    }
    
}

User::User(string username, int ratings[], int numRatings)
{
    _username=username;
    for(int i=0; i<size; i++)
    {
        if(i<numRatings)
        {
            _ratings[i]=ratings[i]; 
        }
        else
        {
            _ratings[i]=0;
        }
        
    }
    
    _numRatings=numRatings;
}

//getters
string User::getUsername()
{
    return _username;
}

int User::getRatingAt(int index)
{
    if(index>=size || index<0)  //if index is equal to or bigger than size or index is less then 0 then return -1
    {
        return -1;
    }
    else
    {
        return _ratings[index];
    }
}

int User::getNumRatings()
{
    return _numRatings;
}

int User::getSize()
{
    return size;
}


// Setters
void User::setUsername(string username)
{
    _username=username;
}

bool User::setRatingAt(int index, int value)
{
    if(index<size && 0<=value && value<=5)
    {
        _ratings[index]=value;  //if conditions are met update _ratings at index with value given
        return true;
    }
    else
    {
        return false;
    }
    
}

void User::setNumRatings(int numRatings)
{
    _numRatings=numRatings;
}

