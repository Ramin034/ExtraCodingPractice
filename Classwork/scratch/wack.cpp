#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    int unit;
    double price;
    double total=0;
    cout<< "Enter units used:"<<endl;
    cin>> unit;
    
    if(unit>=0 && unit<=100)
    {
        total= unit*1.23;
    }
    else if(unit>100 && unit<=200)
    {
        total= 100*1.23 + (unit-100) * 1.14;
    }
    else if(unit>200)
    {
        total= 100*1.23 + 100 * 1.14 + (unit-200) * 1.08;
    }
    else
    {
        cout<< "Incorrect input"<<endl;
        return 0;
    }
    cout<< "Total cost: "<< total<< endl;
}