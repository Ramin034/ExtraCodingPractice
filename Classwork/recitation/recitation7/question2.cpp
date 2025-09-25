#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    string line;
    ifstream fin;

    cout<< "Enter the filename:" <<endl;
    fin.open("card_swipe.txt");
    
    if(fin.fail())
    {
        cout<< "Could not open file/files."<<endl;
        return -1;
    }

    while(getline(fin,line))
    {
        cout<<line<<endl;
    }

    fin.close();
    return 0;
    
}