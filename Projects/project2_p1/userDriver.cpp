// userDriver.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 1 - Problem # 4


#include "User.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

int main()
{
    User u1;
    //test case 1
    assert(u1.getUsername()=="");
    assert(u1.getNumRatings()==0);
    //expected: success
    
    //test case 2
    u1.setUsername("Alex");
    u1.setRatingAt(2, 1);
    assert(u1.getUsername()=="Alex");
    assert(u1.getRatingAt(2)==1);
    //expected: success
   

    cout<< "success"<<endl;
}