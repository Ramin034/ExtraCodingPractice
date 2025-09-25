// amusementPark.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 3 - Problem # 2

#include <iostream>
using namespace std;

int main()
{
    double height;
    char ride;
    double min_height;
    cout << "How tall are you in inches?"<< endl;
    cin >> height;
     if(height<0)
    {
        cout<<"Please enter a valid input."<<endl;
        return 0;
    }
    cout<< "What ride would you like to take(c, t, or i)?"<< endl;
    cin >> ride;
    
   
     if (ride== 'c')
    {
        min_height=30;
    }
    else if(ride== 't')
    {
        min_height=36;
    }
    else if (ride== 'i')
    {
        min_height=45;
    }
    else
    {
        cout<< "Please enter a valid input."<<endl;
        return 0;
    }
    if(height>=min_height)
    {
        cout<< "Yes, you are allowed to go on that ride!"<<endl;
    }
    else if(height<min_height)
    {
        cout<< "Sorry, you cannot go on that ride."<<endl;
    }
    return 0;
}