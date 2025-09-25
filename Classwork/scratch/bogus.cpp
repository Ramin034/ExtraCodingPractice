#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    int day;
    cout<<"Enter the day:"<<endl;
    cin>>day;
    switch(day)
    {
    case 0:
        cout<<"SLEEPDAY"<<endl;
        break;
    case 1:
    case 6:
        cout<<"MONDAY"<<endl;
        break;
    case 2:
    case 3:
    case 4:
        cout<< "WORKDAY"<<endl;
        break;
    case 5:
        cout<< "FUNDAY"<<endl;
        break;
    default:
        cout<<"INVALID"<<endl;
        return 0;
    }
}