#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std; 
int main()
{
    int weight1;
    int weight2;
    int weight3;
    cout<< "Enter first weight:"<<endl;
    cin>> weight1;
    cout<< "Enter second weight:"<<endl;
    cin>> weight2;
    cout<< "Enter third weight:"<<endl;
    cin>> weight3;
    
    if(weight1>> weight2 && weight1>>weight3)
    {
        cout<<"The heaviest item in this list is "<< weight1<<endl;
    }
    else if(weight2>>weight1 && weight2>>weight3)
    {
        cout<< "The heaviest item in this list is "<<weight2<<endl;
    }
    else if(weight1<<weight3 && weight3>>weight2)
    {
        cout<<"The heaviest item in this list is "<<weight3<<endl;
    }
    else
    {
        cout<<"invalid"<<endl;
    }
    
}