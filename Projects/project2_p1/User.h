// User.h

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 4


#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User
{
    private:
        const static int size=50;
        string _username;
        int _numRatings;
        int _ratings[size];
    
    public:
        User(); //default constructor
        User(string username, int ratings[], int numRatings);   //parameterized constructor

        //getters
        string getUsername();
        int getRatingAt(int index);
        int getNumRatings();
        int getSize();

        //setters
        void setUsername(string username);
        bool setRatingAt(int index, int value);
        void setNumRatings(int numRatings);
};

#endif