#include <iostream>
#include <iomanip>
using namespace std;



int main(){
    double Tc;
    double Th;
    double n=1.00;
    cout<< "please enter cold temperature"<<endl;
    cin>> Tc;
    double Kelvin_cold= (Tc-32)*5/9+273.15;
    cout<< "please enter hot temperature"<<endl;
    cin>>Th;
    double Kelvin_hot= (Th-32)*5/9+273.15;
    cout<<fixed<<setprecision(4);
    cout<< "The temperature is "<< n-Kelvin_cold/Kelvin_hot<<endl;
        return 0;
     
}