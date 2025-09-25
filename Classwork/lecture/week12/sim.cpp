#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    // rand() generates 
    // cout<< "RAND_MAX" <<RAND_MAX<<endl;
    srand(time(NULL)); //seed
    // you only call srand one time in your program; the first time in main()
    int max = 8;
    int min = 1;
    for(int i=0; i<=8; i++)
    {
        cout << (rand() % (max - min + 1)) + min << endl;
    }
    // if we want between 0 - 9 - rand % 10(0 + 1)
    // if we want between 1-10 - rand % n + 1
    // if we want between min and max - rand % (max - min) + min

    // 34/2=0 33/2=1
    // coin toss -> 0 and 1

    return 0;
}