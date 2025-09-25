// lotterTicket.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 3 - Problem # 1

#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "How old are you?"<< endl;
    cin >> age;
    if (age<0)
    {
        cout<< "Please enter a valid input."<<endl;
    }
    else if (age>=18)
    {
    cout<< "You can buy a ticket! Good luck."
        <<endl;
    }
    else
    {
    cout<< "You cannot buy a lottery ticket yet."
        <<endl;
    }

}