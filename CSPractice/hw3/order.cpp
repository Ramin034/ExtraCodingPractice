//order.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 3 - Problem # 5

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int choice;
    double total;
    cout<< "What would you like? 1.Drink 2.Meal 3.Dessert"<<endl;
    cin>> choice;
    if(choice==1)
    {
        cout<< "Select one: 1.Boba 2.Soda"<<endl;
        cin>> choice;
        if(choice==1)
        {
            cout<< "Select one: 1.Tapioca 2.Popping 3.Crystal"<<endl;
            cin>> choice;
            if(choice==1)
            {
                total=5.00;
            }
            else if(choice==2 || choice==3)
            {
                total=6.50;
            }
            else
            {
                cout<<"Please enter a valid input."<<endl;
                return 0;
            }
        }
        else if(choice==2)
        {
            cout<<"Select one: 1.Sprite 2.Coke"<<endl;
            cin>>choice;
            if(choice==1 || choice==2)
            {
                total=3.00;
            }
            else
            {
                cout<<"Please enter a valid input."<<endl;
                return 0;
            }
        }
        else
        {
            cout<<"Please enter a valid input."<<endl;
            return 0;
        }
    }
    else if(choice==2)
    {
        cout<< "Select one: 1.Tacos 2.Burger"<<endl;
        cin>> choice;
        if(choice==1)
        {
            cout<< "Select one: 1.Pork 2.Chicken"<<endl;
            cin>> choice;
            if(choice==1 || choice==2)
            {
                total=10.00;
            }
            else
            {
                cout<<"Please enter a valid input."<<endl;
                return 0;
            }
        }
        else if(choice==2)
        {
            cout<< "Select one: 1.Cheeseburger 2.Veggie Burger"<<endl;
            cin>>choice;
            if(choice==1)
            {
                total=12.50;
            }
            else if(choice==2)
            {
                total=14.50;
            }
            else
            {
                cout<<"Please enter a valid input."<<endl;
                return 0;
            }
        }
        else
        {
            cout<<"Please enter a valid input."<<endl;
            return 0;
        }
    }
    else if(choice==3)
    {
        cout<<"Select one: 1.Ice cream 2.Cookies 3.Cake"<<endl;
        cin>> choice;
        if(choice==1)
        {
            cout<<"Select one: 1.Rocky road 2.Vanilla"
                <<endl;
            cin>>choice;
            if(choice==1)
            {
                total=7.00;
            }
            else if(choice==2)
            {
                total=6.50;
            }
            else
            {
                cout<<"Please enter valid input."<<endl;
                return 0;
            }
        }
        else if(choice==2)
        {
            cout<<"Select one: 1.Chocolate Chip 2.Snickerdoodle"<<endl;
            cin>>choice;
            if(choice==1 || choice==2)
            {
                total=6.50;
            }
            else
            {
                cout<<"Please enter a valid input."<<endl;
                return 0;
            }
        }
        else if(choice==3)
        {
            cout<<"Select one: 1.Tiramisu 2.Cheesecake"<<endl;
            cin>>choice;
            if(choice==1)
            {
                total=9.50;
            }
            else if(choice==2)
            {
                total=8.50;
            }
            else
            {
                cout<<"Please enter a valid input."<<endl;
                return 0;
            }
        }
        else
        {
            cout<<"Please enter a valid input."<<endl;
            return 0;
        }
    }
    else
    {
        cout<<"Please enter a valid input."<<endl;
        return 0;
    }
    cout<<fixed<<setprecision(2);
    cout<< "Order total is $"<< total<<endl;
}