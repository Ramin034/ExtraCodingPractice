// arrayPilgrimage.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 5 - Problem # 1


#include <iostream>
using namespace std;





int main()
{
    double distance[10]={42.42, 42.42, 42.42, 42.42, 42.42, 42.42, 42.42, 42.42, 42.42, 42.42};
    string fruit[]={"Strawberry", "Orange", "Apple", "Banana", "Pineapple"};
    int sequence[100];
    char letters[52];


    /**
      * algorithm: create and populate arrays
      * 1. Accept distance into a for loop to print all 10 floating point numbers
      * 2. Accept fruit which then passes through the for loop and prints out the string inside array
      * 3. Accept sequence which then passes through the for loop and prints the first 100 integers divisible by 7
      * 4. Accepts letters which passes through the loop
      * 5. When i is even then print out uppercase letters and when i is odd print lowercase letters.
    */
    for(int i=0; i < 10; i++)
    {
        cout<<distance[i]<<endl;    //prints out floating point numbers in the distance array
    }

    for(int i=0; i < 5; i++)
    {
        cout<< fruit[i]<<endl;  //prints out the string inside the fruits array
    }


    for(int i=0; i < 100; i++)
    {
        sequence[i] = 7 * i + 7;    // fills array with integers divisible by 7
        cout <<sequence[i]<< "   "<<endl;
    }

    for(int i=0; i < 52; i++) 
    {
        
        if(i%2==0)  //if i is even it will print out the uppercase
        {
            letters[i]= i/2+65;
        }
        else    //if i is odd it will print lowercase
        {
            letters[i]= i/2+97;
        }
        cout<< letters[i]<<endl;
    }
}