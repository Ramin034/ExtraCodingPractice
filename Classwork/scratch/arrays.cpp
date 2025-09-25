#include <iostream>
using namespace std;

int main()
{
//contant variables cannot be changed at any point in the program
const int SIZE=20;

//declare array
double arr[SIZE]; // once created it cannot store more than size

// initialize array- individual elements
arr[0]=10.5;
arr[1]=90

//print array
for(int i=0; i<SIZE; i++)
{
    cout<<arr[i]<<endl;
}

//intitialize array through loop
for(int i=0; i<SIZE; i++)
{
    arr[i]=0;
    //overwriting the first 2
}


int arr2[10]={1,2,3,4,5,6,7,8,9,10};

int arr3[SIZE]={}; // initialize these elements to 0

for(int i=0; i<SIZE; i++)//i<=11
{
    cout << arr3[i] <<endl;
}

//bounds eroor 
//if array has SIZE = 10 then you can access elements from arr[0] 

for(int i=0; i<SIZE; i++)//i<=11
{
    cout << arr3[i] <<endl; // of size 10
}
return 0;


}