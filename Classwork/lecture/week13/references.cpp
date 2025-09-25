#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int &r = i; //has to be a varaible
    cout << i << endl; 
    cout << r << endl;

    r=20;
    cout << i << endl;
    cout << r << endl;

    i=30;
    cout << i << endl;
    cout << r << endl;
}

/*
int main()
{
    int i = 10;
    int &r = i
    int a=20;
    r=a; this makes a = 20, r = 20, i = 20
    &r=a is not allowed
}
*/