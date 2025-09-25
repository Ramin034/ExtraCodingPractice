// Movie.h

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 1


#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
using namespace std;

class Movie
{
    private:
        string _title;
        string _releaseYear;


    public:
        Movie(); //default constructor
        Movie(string title, string releaseYear); //parameterized constructor
        // getters
        string getTitle();
        string getReleaseYear();

        // setters
        void setTitle(string title);
        void setReleaseYear(string releaseYear);
};

#endif