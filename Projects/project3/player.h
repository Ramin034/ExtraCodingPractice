// player.h

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 3



#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player
{
    private:
        string _name;
        int _hp;
        int _fuel;
        int _money;
        const static int SIZE=4;
        string _inventory[SIZE];
        int _defense;
        int _armorhp;
        int _weaponhp;
        int _attack;
        int _meds;
        string _armorName;
        string _weaponName;
        
        
    
    public:
        Player();
        Player(string name, int hp, int fuel, int money, string inventory[], int defense, int attack,
         int armorhp, int weaponhp, int meds, string armorName, string weaponName);
        string getName();
        int getHp();
        int getFuel();
        int getMoney();
        string getInventory();
        int getDefense();
        int getArmorhp();
        int getWeaponhp();
        int getAttack();
        string getArmorName();
        string getWeaponName();
        int getMeds();

        void setName(string name);
        void setHp(int hp);
        void setFuel(int fuel);
        void setMoney(int money);
        void setInventory(string inventory[]);
        void setDefense(int defense);
        void setAttack(int attack);
        void updateHp(int hp);
        void setWeaponhp(int weaponhp);
        void setArmorhp(int armorhp);
        void setArmorName(string armorName);
        void setWeaponName(string weaponName);
        void setMeds(int meds);

};
#endif