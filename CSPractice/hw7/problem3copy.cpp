#include <iostream>
#include <vector>

using namespace std;


void printVector(vector<int>vect)
{
    for(int i=0; i<vect.size(); i++)
    {
        cout<< vect[i]<< " ";
    }
    cout<<endl;
}


int main()
{
    int num=0;
    int min=0x7fffffff;
    int max=0;
    vector<int>vect;
    do
    {
        
        cout<< "Please enter a number:"<<endl;
        cin>>num;

        if(num<-1 || num==0)
        {
            cout<<"The number should be a positive integer or -1."<<endl;
            continue;
        }
        if(num%3!=0 && num%5!=0 && num!=-1)
        {
            
            vect.push_back(num);
            
        }
        if(vect.size()>0)
        {
            
            if(num%5==0)
            {
            
                vect.erase(vect.begin());
                
            }
            if (num%3==0)
            {
                
                vect.pop_back();
                
            }
            
        }
        
        if (num==-1)
            {
                if(vect.size()==0)
                {
                    cout<<"The vector is empty."<<endl;
                    return 0;
                }
                for(int i=0; i<vect.size(); i++)
                {
                    if(vect[i]<min)
                    {
                        min=vect[i];
                    }
                    if(vect[i]>max)
                    {
                        max=vect[i];
                    }
                }
                cout<<"The elements in the vector are: ";
                printVector(vect);
                cout<< "Min = "<<min<<endl;
                cout<< "Max = "<<max<<endl;
            }  
        
        

    }
    while(num!=-1);
    return 0;
}