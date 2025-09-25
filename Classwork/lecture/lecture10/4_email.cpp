#include <iostream>
#include <string>
using namespace std;
// string_var.substr(starting_position,num_of_characters)

int main()
{
    string email = "csci1300@colorado.com";

    int len = email.length(); // storing length of email

    for(int i = 0; i<len; i++)
    {
        if(email[i]=='@')
        {
            cout<< "valid email"<< endl;
            break;
        }
    }

    
    //if()
    //{
        //cout << "this is a valid email" << endl;
   // }
    //else
    //{
       // cout << "this is not a valid email" << endl;
    //}
    
    //return 0;
}






