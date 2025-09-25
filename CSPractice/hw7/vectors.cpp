// vectors.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 7 - Problem # 3


#include <iostream>
#include <vector>
using namespace std;

// helper function

void printVector(vector<int>vect)
{
    for(int i=0; i<vect.size(); i++)
    {
        cout<< vect[i]<< " ";
    }
    cout<<endl;
}

/**
 * algorithm: asks user to enter numbers and adds them to vector
 * 1. prompt user to unput value
 * 2. if the value is 0 or less than -1 return "number should be positive"
 * 3. if the vector is empty then insert user input into vector
 * 4. if the vector is not empty and the value is divisible by 3 remove an element from the end of the vector
 * 5. if the vector is not empty and divisible by 5 remove an element from the beginning
 * 6. all other values insert at the end of the vector
 * 7. when -1 is chosen and the vector is empty print "vector is empty"
 * 8. when -1 is chosen and the vector has elements print the min and max aswell as the numbers in the vector
*/

int main()
{
    int num=0;
    int min=0x7fffffff; // largest possible int
    int max=0;
    vector<int>vect;
    do
    {
        
        cout<< "Please enter a number:"<<endl;  // prompts user to input value
        cin>>num;

        if(num<-1 || num==0)
        {
            cout<<"The number should be a positive integer or -1."<<endl;  // if num is less than -1 and equal to 0 print this
            continue;
        }
        
        if(vect.size()>1)   // if the vector is not empty go through this 
        {
            if(num%3!=0 && num%5!=0 && num!=-1)
            {
                vect.push_back(num);
            }

            if(num%5==0)
            {
                vect.erase(vect.begin()); 
            }

            if (num%3==0)
            { 
                vect.pop_back();
            }   
        }
        else
        {
            if(num!=-1) // if vector is empty insert user input
            {
                vect.push_back(num);
            }
        }
        
        if(num==-1)
            {
                if(vect.size()==0)  // if vector is empty at the end print this
                {
                    cout<<"The vector is empty."<<endl;
                    return 0;
                }
                for(int i=0; i<vect.size(); i++)    // checks for the min and max
                {
                    if(vect[i]<min)
                    {
                        min=vect[i];
                    }
                    if(vect[i]>max)
                    {
                        max=vect[i];
                    }
                }
                cout<<"The elements in the vector are: ";
                printVector(vect);  // prints the elements in the vector
                cout<< "Min = "<<min<<endl; //prints min and max
                cout<< "Max = "<<max<<endl;
            }  
        
        

    }
    while(num!=-1);
    return 0;
}