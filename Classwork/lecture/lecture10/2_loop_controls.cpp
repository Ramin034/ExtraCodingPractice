#include <iostream>

using namespace std;


int main()
{
    // continue - skips the current iteration of the loop
    cout << "continue statement demo" << endl;
    for(int i=0; 1<6;i++)
    {
        if(1==2)
        {
            break;
        }
        cout<< i << endl;
    }
    
    
    // break - terminates the loop
    cout << "break statement demo" << endl;
    

    return 0;
}