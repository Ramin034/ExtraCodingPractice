// ducks.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 3 - Problem # 3

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    int ducks;
    cout<< "How many ducks would you like to order?"<<endl;
    cin>> ducks;
    if(ducks<0)
    {
        cout<<"Please enter a valid input."<<endl;
        return 0;
    }
    
    cout<<fixed<<setprecision(2);
    if(ducks<=20)
    {
        cout<< "Your total is $"<< ducks*.50<<endl;
    }
    else if(20<ducks && ducks<=100)
    {
        cout<< "Your total is $"<< (ducks*.50)*.90<<endl;
    }
    else if(100<ducks && ducks<=500)
    {
        cout<< "Your total is $"<< (ducks*.50)*.80<<endl;
    }
    else
    {
        cout<< "Your total is $"<< (ducks*.50)*.50<<endl;
    }
    return 0;
}