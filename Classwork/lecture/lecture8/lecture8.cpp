#include <iostream>
using namespace std;

int main()
{
    //Example buy supplied from store
    char option;
    cout << "what category of supplies would you like to browse today?"<<endl;
    cout << "what is your choice"<<endl;
    cout << "a: fishing" <<endl;
    cout << "b: skiing" <<endl;
    cout << "c: biking"<<endl;
    cout << "d: quit"<<endl;
    cin>> option;

    switch(option)
    {
        // if (option == 'a')
        case 'a':cout<< "you chose to fish"<<endl; 
            break; //indicates end fo this case
        case 'b': cout<< "you chose to skii"<<endl;
            break;
        case 'c': cout<< "you chose to bike"<<endl;
            break;
        case 'd': cout<< "you chose to bike"<<endl;
            break;
        default: 
            break;
    }
   
    

    if(option == 'a')
{
    cout<< "you chose to fish"<<endl;
}
else if (option == 'b')
{
    cout<<"you chose to skii"<<endl;
}
else if (option == 'c')
{
    cout<< "you chose to bike"<<endl;
}





}