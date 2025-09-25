#include <iostream>
using namespace std;

void swap(int myArray[], int startIndex, int endIndex)
{
    int temp= myArray[startIndex];
    myArray[startIndex] = myArray[endIndex];
    myArray[endIndex]= temp;
}


void reverseArray (int myArray[], int myArrayLength);
{
    
    startIndex=0;
    endIndex= size-1;
    while(start<end)
    {
        swap(int myArray[], int startIndex, int endIndex);
        startIndex++;
        endIndex--;
    }
}



int main()
{
    int arrSize;
    cout<< "enter size"<<endl;
    cin>> arrSize;

    if(arrSize<=0)
    {
        cout<< "invalid input"<<endl;
        return 0;
    }

    int myarr(arrSize);

    for(int i=0;i<arrSize;i++)
    {
        cin>>myArray[i];
    }

    reverseArray(myArray, arrSize);
    cout<< "The reverse array is"<<endl;

    for(int i=0; i<arrSize; i++)
    {
        cout<<myArray[i]<< "  ";
    }
    cout<<endl;

    return 0;
}