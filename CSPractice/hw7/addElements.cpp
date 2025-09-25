// addElements.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 7 - Problem # 1


#include <iostream>
#include <vector>

using namespace std;

/**
 * algorithm: finds the sum of the elements inside the vector between the min and max
 * 1. if min is bigger than the max return -1
 * 2. if the min and max exceed the bounds of the vector return -1
 * 3. in a for loop add the sum of all elements in the vector
 * Parameters: Vector<int>vect, min_index(int), max_index(int)
 * Returns: returns -1 when min is bigger than max, returns -2 if bounds of vector are exceeded, returns the sum.
*/

int addElements(vector<int>vect, int min_index, int max_index)
{
    int sum=0;
    if(min_index>max_index) // if min is bigger than max return -1
    {
        return -1;
    }
    if(min_index<0 || max_index>=vect.size())  // if min and max exceed vector bounds return -2
    {
        return -2;
    }
    for(int i=min_index; i<=max_index; i++) //initialize i at min_index since that is the starting index
    {
        sum= sum + vect[i];
    }
    return sum;
}



int main()
{
    vector<int> vect1{10, 20, 30, 40, 50};
    int min_index = 1, max_index = 3;
    cout << addElements(vect1, min_index, max_index) << endl;

    //vector<int> vect3{2, 4, 6, 8, 10, 12, 14, 16, 18};
    //int min_index = 3, max_index = 15;
    //cout << addElements(vect3, min_index, max_index) << endl;
}