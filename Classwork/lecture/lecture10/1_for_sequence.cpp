#include <iostream>

using namespace std;
/*
    while(condition)
    {
        statements;
    }
    // infinite loop-> run forever
    while(1)
    {

    }

*/

/*
    // loop variable - i,j
    for (initialization; condition; update) // uodate -> i++ -> i=i+1; i-- -> i = i-1
    { 
        statements; // also called loop body
    }
    // if you know the count

    OR

    initialization;
    while(condition)
    {
        statements;
        update;
    }

*/

int main()
{
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    
    // print numbers from 0 -> num == 0 1 2 3 .... num
    for(int i=0;  i< num; i++) // 3 statements // i=2
    {
        cout<< i << endl;
        // update will be exectuted
    }
    int j=0;
    while(j<num)
    {
        cout<< j << endl;
        j++;
    }
    
    
    // print every other number from 0 -> num -- 0 2 4 6 8 
    // approach 1
    for(int i=2; i<num; i++)
    {
        if(i % 2 == 0)
        {
            cout<< i << endl;
        }
    }
    // approach 2
    for(int i=2; i<num; i++) // i= i +2; i+=2; 
    {
            cout<< i << endl;
    }
    
    return 0;
}