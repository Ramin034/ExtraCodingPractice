// Blockbustr.h

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 2 - Problem # 0



#ifndef BLOCKBUSTR_H
#define BLOCKBUSTR_H
#include <iostream>
#include "Movie.h"
#include "User.h"
using namespace std;


class Blockbustr
{
    private:
        const static int _sizeMovie=50;
        const static int _sizeUser=100;
        Movie _movies[_sizeMovie];
        User _users[_sizeUser];
        int _numMovies;
        int _numUsers;

    public:
        Blockbustr();


        //getters
        int getSizeMovie();
        int getSizeUser();
        int getNumMovies();
        int getNumUsers();

        int readMovies(string filename);
        void printMoviesByYear(string year);
        int readRatings(string filename);
        int getRating(string username, string title);
        int getCountWatchedMovies(string username);
        double calcAvgRating(string title);
        int addUser(string username);
        int rentMovie(string username, string title, int newRating);
};

#endif