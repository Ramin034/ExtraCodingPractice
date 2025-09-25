// foodRecipe.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 4 - Problem # 3

#include <iostream>
using namespace std;

int main()
{
    int num;    //variables for every piece of recipe
    int bacon;
    int tomato;
    int lettuce;
    double mayo;
    int mozzarella;
    int basil;
    double glaze;
    int red_union;
    int cucumber;
    double roasted_pep;
    double hummus;
    
    do  //used so the menu can reappear after conditions met
    {
        cout<<"Select a numerical option:"<<endl    // menu displayed
        <<"=== menu ===" << endl
        << "1. BLT sandwich"<<endl
        << "2. Caprese sandwich"<<endl
        << "3. Veggie sandwich"<<endl
        << "4. Quit"<<endl;
        cin>> num;  //user chooses options in the menu
        
        switch(num) //switch statement so user can get correct displays based on their choice
        {
        case 1:
            cout<< "How many bacon strips do you have?"<<endl;  //user types amount of ingredients they have
            cin>> bacon;
            cout<< "How many tomato slices do you have?"<<endl;
            cin>> tomato;
            cout<< "How many lettuce leaves do you have?"<<endl;
            cin>> lettuce;
            cout<< "How many ounces of mayonnaise do you have?"<<endl;
            cin>> mayo;
            if(bacon>=4 && tomato>=3 && lettuce>=2 && mayo>=.51)    //requirements for the sandwich
            {
                cout<< "You can make a BLT sandwich."<<endl;
            }
            else    //for user if they don't have enough ingredients
            {
                cout<< "You don't have enough for a BLT sandwich."<<endl; 
            }
            break;
        case 2:
            cout<<"How many mozzarella slices do you have?"<<endl;
            cin>> mozzarella;
            cout<< "How many tomato slices do you have?"<<endl;
            cin>> tomato;
            cout<<"How many basil leaves do you have?"<<endl;
            cin>> basil;
            cout<< "How many ounces of balsamic glaze do you have?"<<endl;
            cin>>glaze;
            if(mozzarella>=4 && tomato>=2 && basil>=9 && glaze>=.12)
            {
                cout<< "You can make a Caprese sandwich."<<endl;
            }
            else
            {
                cout<< "You don't have enough for a Caprese sandwich."<<endl;
            }
            break;
        case 3:
            cout<< "How many red onion rings do you have?"<<endl;
            cin>> red_union;
            cout<< "How many cucumber slices do you have?"<<endl;
            cin>> cucumber;
            cout<< "How many ounces of diced roasted pepper do you have?"<<endl;
            cin>> roasted_pep;
            cout<< "How many ounces of hummus do you have?"<<endl;
            cin>> hummus;
            if(red_union>=5 && cucumber>=7 && roasted_pep>=2.33 && hummus>=2.5)
            {
                cout<< "You can make a Veggie sandwich."<<endl;
            }
            else
            {
                cout<< "You don't have enough for a Veggie sandwich."<<endl;
            }
            break;
        case 4: //if user selects 4 they are prompted "goodbye!"
            {
                cout<<"Goodbye!"<<endl;
                break;
            }
        default:    //if user inputs anything that aren't in the menu they run this
            {
                cout<< "Invalid input."<<endl;
            }
        } 
    }
    while(num!=4);  //if user picks 4 the program ends
}