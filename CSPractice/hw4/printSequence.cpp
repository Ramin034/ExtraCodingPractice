// printSequence.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 4 - Problem # 2

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long int n;     //variable made as long int so that large integers are stored
    cout<< "Enter a positive integer:"<<endl;   //prompts user what to do
    cin>> n;    //user declares variable
    if(n<1) //if user inputs anything less than one they run through this
    {
        cout<< "Invalid input."<<endl;
        return 0;
    }
    cout<< n <<endl;    //used to display the number chosen by the user
    while(n>1)  //when n is greater then the loop begins
    {
        if(n%2==0)  //if n is even then it runs through this calculation
        {
            n=sqrt(n);
            cout<< n << endl;   //calculation are then displayed
            
        }
        else    //if n is odd then it runs through this calculation
        {
            n=sqrt(pow(n,3));   //calculations are then displayed
            cout<< n <<endl;
        }
    }
    
    
}