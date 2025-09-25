// calcSigmoid.cpp

// CSCI 1300 Spring 2022</br>
// Author: Ramin Akbari </br>
// Recitation: 102 – Nikhith Sannidhi</br>
// Homework 2 - Problem # 6


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x;       //x is set for the variable
    cout << "Enter a value for x:" << endl;
    cin >> x;       //user inputs number for x
   double sigmoid= 1 / (1 + exp(-x));       //x is then plugged in to the equation for sigmoid
   cout<< "The sigmoid for x="<< x << " is "<< sigmoid<< endl;
}