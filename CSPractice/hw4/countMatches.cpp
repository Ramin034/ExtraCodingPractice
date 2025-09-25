// countMatches.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 4 - Problem # 4

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string search_str;  //string variables
    string search_substr;
    int i=0;    //initialized variables
    int occur=0;
    cout<< "Enter the search string:"<<endl;    //user is given intructions
    cin>> search_str;   //user inputs string
    cout<< "Enter the substring to be searched:"<<endl;
    cin>> search_substr;    //user enters substrings they want to be searched
    while(i < search_str.size())    //if i is less then the string size the loop will begin
    {
        if(search_str.substr(i,search_substr.size())==search_substr)    //this is used to show the number of occurences from the substring
        {
            occur++;    //everytime the substring occurs it runs through this if
        }
        i++;
    }
    cout<< "Number of occurrences: " << occur <<endl;   //the number of occurences are then displayed
    
    
}