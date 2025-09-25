#include <iostream>
#include <cassert>
using namespace std;

bool isValidNote(string note)
{
    int len= note.length();
    if(len != 2)
    {
        return false;
    }
    if(int(note[0])>71 || int(note[0])<65) 
    {
        return false;
    }
    if(int(note[1])<48 || int(note[1])>57) 
    {
        return false;
    }
    return true;

}

bool isValidTune(string tune)
{
    if(tune.length() % 2 == 1 || tune== "")
    {
        return false;
    }
    for(int i=0; i<tune.length() / 2; i=i+2)
    {
        if(!isValidNote(tune.substr(i,2)))
        {
            return false;
        }
    }
    return true;
}

int numValidNotes(string tune)
{
    int count=0; 
    for(int i=0; i<tune.length(); i++) //were going through all the characters of the string
    {
        if(isValidNote(tune.substr(i,2)))
        {
            count++;
        }
    }
    return count;
}


bool tuneSimilarity(double tune1, double tune2)
{   
    int matchnote=0;
    int matchpitch=0;
    int diffnote=0;
    int diffpitch=0;
    double similarity= 
}

int main()
{
    
}