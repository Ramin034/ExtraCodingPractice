// movieDriver.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 1



#include "Movie.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    //test case 1
    Movie m1;
    assert(m1.getTitle()=="");
    assert(m1.getReleaseYear()=="");
    //expected: all tests pass 
    

    //test case 2
    Movie m2("Spiderman", "2002");
    assert(m2.getTitle()=="Spiderman");
    assert(m2.getReleaseYear()=="2002");
    //expected: all test pass


    //test case 3
    m2.setTitle("John Wick");
    assert(m2.getTitle()=="John Wick");
    assert(m2.getReleaseYear()=="2002");
    // expected: all tests pass


    //test case 4
    m2.setReleaseYear("2014");
    assert(m2.getReleaseYear()=="2014");
    assert(m2.getTitle()=="John Wick");
    //expected: all tests pass

    cout<< "all tests pass"<<endl;
}