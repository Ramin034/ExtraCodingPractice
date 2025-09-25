#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num=0;
    cout << "Please enter a positive number: " << endl;
    cin >> num;
    while (num <= 0) // validating user input
    {
        cout << "Invalid input"<< endl << "Please enter a POSITIVE number:";
        cin >> num;
    }

    cout << "Square root of " << num << "is " << sqrt(num) << endl;
    return 0;
}
