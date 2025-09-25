#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    double num1;
    double num2;
    double ans;
    char op;
    cout<< fixed<< setprecision(2);
    cout<< "Enter a number:"<<endl;
    cin>> num1;
    cout<< "Enter another number:"<<endl;
    cin>> num2;
    cout<< "Enter an operator:"<<endl;
    cin>> op;
    switch(op)
    {
    case '+':
        ans= num1+num2;
        break;
    case '-':
        ans= num1-num2;
        break;
    case '*':
        ans=num1*num2;
        break;
    case '/':
        ans=num1/num2;
        break;
    default:
        cout<< "Invalid operator!"<<endl;
        return 0;
    }
   cout<< num1<< " "<< op << " " <<num2<<" = "<< ans <<endl;
}