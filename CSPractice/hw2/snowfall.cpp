// snowfall.cpp

// CSCI 1300 Spring 2022</br>
// Author: Ramin Akbari </br>
// Recitation: 102 – Nikhith Sannidhi</br>
// Homework 2 - Problem # 4


#include <iostream>
using namespace std;

int main()
{
    int days;
    cout<< "How many days in the future would you like a prediction for?" 
        << endl;
    cin >> days;        // user inputs # of days
    int breckenridge= 28 + 15 * days - 4 * days;      //the users input is then put in the calculations
    int vail = 33 + 11 * days - 7 * days;
    int copper_mountain = 55 + 3 * days - 2 * days;
    cout<< "Breckenridge will have " << breckenridge << " inches, ";
    cout<< "Vail will have " << vail << " inches, " ;
    cout<< "and Copper Mountain will have " << copper_mountain << " inches.";

}