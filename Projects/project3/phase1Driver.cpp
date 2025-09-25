// phase1.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 3


#include <iostream>
#include "time.h"
#include "planet.h"
#include "player.h"
#include "shop.h"
#include <vector>
using namespace std;

int main()
{
    Player player;
    int num=0;
    int cost=0;
    string input;
    string username;
    int total=0;
    int num2=0;
    string input2;
    int meds=0;

    cout << "Please enter your name" << endl;
    getline(cin,username);

    if(username.length()>=0)
    {
        player.setName(username);
        player.setHp(100);
        player.setFuel(200000);
        player.setMoney(100000);
        player.setDefense(30);
        player.setArmorhp(100);
        player.setAttack(50);
        player.setWeaponhp(100);
        player.setArmorName("Space Suit Grade 1");
        
    }
    
    do
    {
        cout<<"Which item do you wish to buy?\n"
            "1. Weapon\n"
            "2. Translator\n"
            "3. Space suit\n"
            "4. Medical kits\n"
            "5. Fuel\n"
            "6. Purchase and leave"<<endl;
        getline(cin,input);
        num=stoi(input);
        switch(num)
        {
        case 1:
            cout<< "The different weapons are:\n"
                "1. Light Saber: $1,000\n"
                "2. Blaster: $2,000\n"
                "3. Beam Gun: $5,000\n"
                "4. Go back to menu"<<endl;
            getline(cin,input);
            num2=stoi(input);

            switch(num2)
            {
            case 1:
                cout<< "How many Light Sabers would you like ($1,000 each)?"<<endl;
                getline(cin,input2);
                num2=stoi(input2);
                if(num2>=0 && num2<=2)
                {
                    cost = num2*1000;
                    total = player.getMoney();
                    if(total<cost)
                    {
                        cout<< "You do not have enough money for that. "<<endl;
                    }
                    else
                    {
                        total = total-cost;
                        player.setMoney(total);
                        cout << "You have $" << total << " left." <<endl;
                    }   
                }
                else
                {
                    cout<< "You cannot have more than two weapons at the same time, re-enter a valid quantity."<<endl;
                }
                break;
            case 2:
                cout<< "How many Blasters would you like ($2,000 each)?"<<endl;
                getline(cin,input2);
                num2=stoi(input2);
                if(num2>=0 && num2<=2)
                {
                    cost = num2*2000;
                    total = player.getMoney();
                    if(total<cost)
                    {
                        cout<< "You do not have enough money for that. "<<endl;
                    }
                    else
                    {
                        total = total-cost;
                        player.setMoney(total);
                        cout << "You have $" << total << " left."<<endl;
                    }   
                }
                else
                {
                    cout<< "You cannot have more than two weapons at the same time, re-enter a valid quantity."<<endl;
                }
                break;
            case 3:
                cout<< "How many Beam Guns would you like ($5,000 each)?"<<endl;
                getline(cin,input2);
                num2=stoi(input2);
                if(num2>=0 && num2<=2)
                {
                    cost = num2*5000;
                    total = player.getMoney();
                    if(total<cost)
                    {
                        cout<< "You do not have enough money for that. "<<endl;
                    }
                    else
                    {
                        total = total-cost;
                        player.setMoney(total);
                        cout << "You have $" << total << " left." <<endl;
                    }   
                }
                else
                {
                    cout<< "You cannot have more than two weapons at the same time, re-enter a valid quantity."<<endl;
                }
                break;
            case 4: 
                break;
            }//close of while
            break;
        case 2:
            cout<< "Would you like to purchase a translator device ($5,000)? 1 for yes, 0 for no."<<endl;
            getline(cin,input2);
            num2=stoi(input2);
            
            switch(num2)
            {
            case 1:
                cost=5000;
                total=player.getMoney();
                if(total<cost)
                {
                    cout<< "You do not have enough money for that"<<endl;
                }
                else
                {
                    total=total-cost;
                    player.setMoney(total);
                    cout<< "you have $"<< total << " left."<<endl;
                }
                break;
            case 2:
                break;
            }
            break;
        case 3:
            cout<< "Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%.\n"
                "1. Space suit grade 2 is $5,000\n"
                "2. Space suit grade 3 is $10,000\n"
                "3. Space suit grade 4 is $15,000\n"
                "4. Space suit grade 5 is $20,000"<<endl;
            getline(cin,input2);
            num2=stoi(input2);

            switch(num2)
            {
            case 1:
                cost=5000;
                total=player.getMoney();
    
                if(total<cost)
                {
                    cout<< "You do not have enough money for that"<<endl;
                }
                else
                {
                    total=total-cost;
                    player.setMoney(total);
                    player.setArmorhp(100);
                    player.setArmorName("Space Suit Grade 2");
                    player.setDefense(60);
                    cout<< "Your space suit is now a grade 2"<<endl;
                    cout<< "You have $"<<total<<" left."<<endl;
                }
                break;
            case 2:
                cost=10000;
                total=player.getMoney();

                if(total<cost)
                {
                    cout<< "You do not have enough money for that"<<endl;
                }
                else
                {
                    total=total-cost;
                    player.setMoney(total);
                    player.setArmorhp(100);
                    player.setDefense(90);
                    player.setArmorName("Space Suit Grade 3");
                    cout<< "Your space suit is now a grade 3"<<endl;
                    cout<< "You have $"<<total<<" left."<<endl;
                }
                break;
            case 3:
                cost=15000;
                total=player.getMoney();

                if(total<cost)
                {
                    cout<< "You do not have enough money for that"<<endl;
                }
                else
                {
                    total=total-cost;
                    player.setMoney(total);
                    player.setArmorhp(100);
                    player.setDefense(120);
                    player.setArmorName("Space Suit Grade 4");
                    cout<< "Your space suit is now a grade 4"<<endl;
                    cout<< "You have $"<<total<<" left."<<endl;
                }
                break;
            case 4:
                cost=20000;
                total=player.getMoney();

                if(total<cost)
                {
                    cout<< "You do not have enough money for that"<<endl;
                }
                else
                {
                    total=total-cost;
                    player.setMoney(total);
                    player.setArmorhp(100);
                    player.setDefense(150);
                    player.setArmorName("Space Suit Grade 5");
                    cout<< "Your space suit is now a grade 5"<<endl;
                    cout<< "You have $"<<total<<" left."<<endl;
                }
                break;
            default:
                cout<<"enter valid input"<<endl;
            }
            break;
        case 4:
            cout<<"How many medical kits would you like to purchase ($2,000 each)? You currently have 0, and can at most have 5."<<endl;
            getline(cin,input2);
            num2=stoi(input2);

            cost=num2*2000;
            total=player.getMoney();
            meds=player.getMeds();

            if(meds>=5 || num2>5)
            {
                cout<< "You cannot have more than 5 kits. Re-enter a valid quantity."<<endl;
            }
            else
            {
                total=total-cost;
                player.setMoney(total);
                player.setMeds(num2);
                cout<< "You have $"<<total<<" left."<<endl;
            }
            break;
        case 5:
            
            break;
        }  
        
    }while(num!=6);
}