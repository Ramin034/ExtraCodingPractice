#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // argc= argument count.
    // argv= argument vactor.

    // (./prog -v (txt file))

    cout << "you have entered " << argc << " arguments:"<<endl;

    for(int i=0; i<argc; i++)
    {
        cout<< argv[i]<< endl;
        return 0;
    }
}