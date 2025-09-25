#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line1;
    string line2;

    ifstream fin1;
    ifstream fin2;

    string outputfile;
    ofstream fout;

    cout<< "enter filename"<<endl;
    cin>>line1;
    cout<< "enter filename 2"<<endl;
    cin>>line2;

    fin1.open("input1.txt");
    fin2.open("input2.txt");
    fout.open(outputfile);

    if(fin1.is_open() && fin2.is_open())
    {
        string line;
        while(getline(fin1,line))
        {
            fout<< line << endl;
        }
        
        line="";
        while(getline(fin2,line))
        {
            fout<< line << endl;
        }

    }
    else
    {
        cout<< "unable to open files"<<endl;
        return 0;
    }

    fin1.close();
    fin2.close();
    return 0;


}