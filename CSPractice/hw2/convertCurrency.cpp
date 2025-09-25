// covertCurrency.cpp

// CSCI 1300 Spring 2022</br>
// Author: Ramin Akbari </br>
// Recitation: 102 – Nikhith Sannidhi</br>
// Homework 2 - Problem # 5


#include <iostream>
using namespace std;

int main()
{

    int knuts;      //varibles are set
    int galleons;
    int sickles;
    cout<< "Enter the number of Knuts:" << endl;
    cin>> knuts;
    sickles= knuts/29;      //29 knuts are 1 sickle
    knuts= knuts % 29;      // when turning knuts to sickles there is a remainder of 3
    galleons= sickles/17;   //we do the same process but for galleons
    sickles= sickles % 17;
    cout << galleons << " Galleon(s) " << sickles <<  " Sickle(s) " << knuts << " Knut(s)"<< endl;
    
}