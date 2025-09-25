#include <iostream>
using namespace std;

int main()
{
    int water_drank, water_goal= 64;

    cout<< "How much water did you drink today?"<<endl;
    cin>> water_drank;

    if(water_drank<0 || water_drank > 1000)
    {
        cout<< "not valid input" << endl;
    }
    else if( water_drank>=0 && water_drank<=32)
    {
        cout<< "you're very, very dehydrated"<<endl;
    }
    

}