// stock.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 3 - Problem # 4

#include <iostream>
using namespace std;

int main()
{
    double week_1;
    double week_2;
    double week_3;
    
    cout<< "Enter stock prices over last 3 weeks"<< endl;
    cin >> week_1 >> week_2 >> week_3;
    if(week_1<0 || week_2<0 || week_3<0)
    {
        cout << "Please enter a valid input." <<endl;
        return 0;
    }
    
    if(week_1< week_2  &&  week_2< week_3)
    {
        cout<<"The value is rising!"<<endl;
    }
    else if(week_1> week_2 && week_2> week_3)
    {
        cout<< "The value is tanking."<<endl;
    }
    else
    {
        cout<< "Neither"<<endl;
    }
}