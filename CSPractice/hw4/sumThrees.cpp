// sumThrees.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 4 - Problem # 1

#include <iostream>
using namespace std;

int main()
{
    int num;
    int sum=0;  //initialized variables
    int i=0;
    cout<<"Enter a positive integer:"<<endl;    //prompts user
    cin>> num;     //user declares variable num
    while(i<=num)   //stops loop when variable is less then i
    {
        if(i%3==0)  //searches for number divisible by 3
        {
            sum= sum + i;   //this lists numbers divisible by 3 into sum
            
        }
        
        i++;
    }
    if(num<=0)  //if user declares anything that is less than or equal to zero
    {
        cout<<"Invalid input."<<endl;   //prints invalid input
        return 0;
    }
    cout<< "Sum: "<< sum <<endl;    //displays the sum of threes from the users input
}