// arrayStats.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 5 - Problem # 2

#include <iostream>
#include <iomanip>
using namespace std;

/**
  * algorithm:compute the maximum of the values in array
  * 1. Accepts arr and size which then pass through the function
  * 2. Create variable for maximum value
  * 3. values in the array bigger than the largest variable are then passed through the if statement
  * 4. largest value is stored
  * Parameters: arr(double), size(int)
  * Return: the maximum(largest in this case) of all values
*/

double max(double arr[], int size)
{
    double largest=arr[0];  //largest is initialized to whatever is inside the array
    for(int i=0; i<size; i++)
    {
        if(arr[i]>largest)  //if the values inside the array are bigger they go through this if statement
        {
            largest= arr[i]; //then the value is initialized in the variable
        }

    }
    return largest; //then after the the loop the function returns the largest variable
}

/**
  * algorithm: compute sum of all values in array
  * 1. accepts arr and size which then pass through function
  * 2. create total variable
  * 3. add total and arr[i] and store it into total again
  * Parameter: arr(double), size(int)
  * Return: sum of all values(total)
*/

double sum(double arr[], int size)
{
    double total=0;
    for(int i=0; i<size; i++)
    {
        total= total + arr[i];  //adds each array to total then saves it.
    }
    return total;
}

/**
  * algorithm: finds the average of all values in the array
  * 1. accepts arr and size which then pass through the function
  * 2. call the function sum(arr,size) the divide by size
  * Parameters: arr(double), size(int)
  * Return: the average of all values
*/

double average(double arr[], int size)
{
    return sum(arr,size)/size;  //returns average
}


int main()
{
    int len = 10;
double arr[len] = {0,1,2,3,4,5,6,7,8,9};
//test 1 maximum value
cout << "Max: " << fixed << setprecision(3)<< max(arr, len) << endl;
//test 2 sum of all values
cout << "Sum: " << fixed << setprecision(3) << sum(arr, len) << endl;
//test 3 average of all values
cout << "Avg: " << fixed << setprecision(3) << average(arr, len) << endl;
}