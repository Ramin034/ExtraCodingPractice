// BlockbustrDriver.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 2 - Problem # 0


#include "Blockbustr.h"
#include "Movie.h"
#include "User.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Blockbustr bb;
    int value=0;

    //test case 1
    bb.readMovies("movies.txt");
    assert(bb.getNumMovies()==5);
    bb.printMoviesByYear("2014");
    /* Expected:
    Here is a list of movies released in 2014
    Whiplash 
    */



    bb.readRatings("ratings.txt");
    
    //test case 2
    assert(bb.getNumUsers()==4);
    assert(bb.getRating("Alex", "Titanic")==1);
    assert(bb.getCountWatchedMovies("Alex")==5);
    //expected success

    //test case 3
    bb.readRatings("ratingfile.txt");
    assert(bb.getNumUsers()==7);
    assert(bb.getCountWatchedMovies("User3")==0);
    //expected success

    //cout<<bb.calcAvgRating("Titanic")<<endl;;

    //test case 4
    assert(bb.calcAvgRating("Titanic")==1);
    //expected success

    //cout<<bb.calcAvgRating("whiplash")<<endl;;
    assert(bb.calcAvgRating("whiplash")==3);

    assert(bb.calcAvgRating("John Wick")==-3);

    bb.addUser("Wick");
    assert(bb.getNumUsers()==8);

    bb.addUser("Punith");
    cout<< bb.addUser("Punith")<<endl;
    assert(bb.getNumUsers()==8);

    bb.readRatings("ratings_50.txt");
    value=bb.readRatings("ratings_50.txt");
    cout<<value<<endl;
    assert(value==100);

    value = bb.addUser("GG");
    assert(bb.getNumUsers()==100);
    assert(value==-2);

    value = bb.rentMovie("WiCk","TiTaniC",3);
    assert(value==1);
    assert(bb.getRating("Wick", "Titanic")==3);

    assert(bb.rentMovie("wack", "Titanic",5)==-3);

    assert(bb.rentMovie("wack", "Titanic",7)==-4);

    assert(bb.rentMovie("Wick", "tinTanic",5)==-3);
    

    

    cout<<"success"<<endl;
}


