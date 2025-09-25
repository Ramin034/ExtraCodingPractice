#include <iostream>

using namespace std;
void printArray(double arr[],int size)
{
    for(int i=0; i< size; i++)
    {
        cout<< arr[i]<<setw(10);
    }
}

int main()
{
    // constant variables (const keyword) cannot be modified after initialization
    // naming style - all caps
    const int SIZE = 12;

    // declare array
    double sales_2021[SIZE] = {32, 54, 67.5, 29, 35, 80, 115, 98, 100, 65, 210.5, 140};


    // print sales_2021
    // for(int i = 0; i < SIZE; i++)
    // {
    //     cout << sales_2021[i] << endl;
    // }

    int arr[SIZE] = {1, 2, 3, 4, 5};

    // print arr
    // for(int i = 0; i < SIZE; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    return 0;
}
