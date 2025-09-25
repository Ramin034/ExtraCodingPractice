// almondMilk.cpp

// CSCI 1300 Spring 2022</br>
// Author: Ramin Akbari </br>
// Recitation: 102 – Nikhith Sannidhi</br>
// Homework 2 - Problem # 3


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double side_length;   //variables are set for the side length and height.
    double height;
    cout << "What is the side length of the base of the carton in inches?"<< endl;
    cin >> side_length;     // User inputs side length
    cout << "What is the height of the carton in inches?"<< endl;
    cin >> height;      //user inputs height
    double volume= side_length * side_length * height;  // The volume is computed and stored
    double ounces= .55 * volume;        // ounces is then calculated
    cout << fixed << setprecision(2);
    cout << "The carton has a volume of "<< ounces<< " ounces."<< endl;
    
    
}