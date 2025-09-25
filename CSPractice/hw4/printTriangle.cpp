// printTriangle.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 4 - Problem # 5

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int height; //variable 
    int savepoint=0; //savepoint variable used for position in the substring
    string alph="abcdefghijklmnopqrstuvwxyz";   //alphabet stored into the string alph
    cout<< "Enter the height:"<<endl;
    cin>> height;   //user inputs height
     if(height<=0)  //if the height they chose is less than or equal to zero then it's invalid
    {
        cout<<"Invalid input."<<endl;
        return 0;   //used to end the program
    }
    while(height>0)
    {
        alph.substr(savepoint,height);  //savepoint is used for staring point
        cout<< alph.substr(savepoint,height);
        savepoint=savepoint+height; //the savepoint is then added by the height the user chose 
        height--;
        if(savepoint>=26)   //when the savepoint reaches past the amount in the alphabet it runs through this if
        {
            savepoint=savepoint-26; //this is so the savepoint stays in the alphabet
            cout<<alph.substr(0,savepoint);
        }
        cout<<endl; //this is so there are no endlines in the program
    }
}