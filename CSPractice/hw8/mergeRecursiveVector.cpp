#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

bool caseinsensitive(string upperuser, string loweruser)
{
    char up;
    char upper;
    if(upperuser.length()!=loweruser.length())
    {
        return false;
    }
    for(int i=0; i<upperuser.length(); i++)
    {
        up=upperuser.at(i);
        upper=loweruser.at(i);
        if(loweruser.at(i)>=97 && loweruser.at(i)<=122)
        {
            upper=loweruser.at(i)-32;
        }
        if(upperuser.at(i)>=97 && upperuser.at(i<=122))
        {
            up=upperuser.at(i)-32;
        }
        if(up!=upper)
        {
           return false;
        }
    }
    return true;
    
}


string vectorMerge(vector<string>vect)
{
    if(vect.size()==0)
    {
        return "0"; // if string is empty return "0"
    }
    string str=vect[0]; //saves the first string in the vector
    
    for(int i=1; i<vect.size(); i++)
    {
        if(vect[i]=="") // if vector has empty space continue
        {
            continue;
        }
        if(caseinsensitive(vect[i],"STOP")) // when the keyword is ever present return the string
        {
            return str;
        }
        else
        {
            str= str + " " + vect[i];  // merges all the string until keyword
        }
    }
    return str;
}



string mergeVectorRecursive(vector<string>vect)
{
    int index=1;
    string str;
    if(vect.size()==0)
    {
        return "";
    }
    else
    {
        return str = mergeVectorRecursive();
    }
    return str;
}

int main()
{
    vector<string> vec1{"I", "love", "CSCI 1300"};
    cout << mergeVectorRecursive(vec1) << endl;

}