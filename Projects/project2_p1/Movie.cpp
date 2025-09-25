// Movie.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 1


#include "Movie.h"
#include <iostream>
#include <iomanip>
using namespace std;

Movie::Movie() //sets title and release year to empty strings
{
    _title="";
    _releaseYear="";
}
Movie::Movie(string title, string releaseYear)
{
    _title=title;
    _releaseYear=releaseYear;
}

// getters
string Movie::getTitle()
{
    return _title;
}
string Movie::getReleaseYear()
{
    return _releaseYear;
}

// setters
void Movie::setTitle(string title)
{
    _title=title;
}
void Movie::setReleaseYear(string releaseYear)
{
    _releaseYear=releaseYear;
}