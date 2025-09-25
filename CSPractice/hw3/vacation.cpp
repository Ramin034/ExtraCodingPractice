//vacation.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 3 - Problem # 6

#include <iostream>
using namespace std;

int main()
{
    int choice;
    cout<<"Enter country: 1.South Africa 2.Mexico 3.India 4.Costa Rica"
        <<endl;
    cin >> choice;
    switch(choice)
    {
    case 1: 
        cout<< "Enter city: 1.Cape Town 2.Johannesburg"<<endl;
        cin>> choice;
        switch(choice)
        {
        case 1:
            cout<< "Your trip will be $1200."<<endl;
            break;
        case 2:
            cout<< "Your trip will be $1000."<<endl;
            break;
        default:
            cout<< "Please enter a valid input"<<endl;
        }
        break;
    case 2:
        cout<< "Enter city: 1.Cancun 2.Mexico City"<<endl;
        cin>> choice;
        switch(choice)
        {
        case 1:
            cout<< "Your trip will be $950."<<endl;
            break;
        case 2:
            cout<< "Your trip will be $800."<<endl;
            break;
        default:
            cout<< "Please enter a valid input."<<endl;
            break;
        }
        break;
    case 3:
        cout<< "Enter city: 1.Manali 2.Kochi"<<endl;
        cin>> choice;
        switch(choice)
        {
        case 1:
            cout<< "Your trip will be $1100."<<endl;
            break;
        case 2:
            cout<< "Your trip will be $900."<<endl;
            break;
        default:
            cout<< "Please enter a valid input."<<endl;
            break;
        }
        break;
    case 4:
        cout<< "Enter city: 1.San Jose 2.San Vicente"<<endl;
        cin>> choice;
        switch(choice)
        {
        case 1:
            cout<< "Your trip will be $800."<<endl;
            break;
        case 2:
            cout<< "Your trip will be $1300."<<endl;
            break;
        default:
            cout<< "Please enter a valid input."<<endl;
            break;
        }
        break;
    default:
        cout<< "Please enter a valid input."<<endl;
        break;
    }
}