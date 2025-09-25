// shop.h

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 3



#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include "player.h"
#include "planet.h"
using namespace std;

class Shop
{
    private:
        string _armor[4];
        string _weapons[3];
        int _cost;
    public:
        Shop();
        Shop(string armor[], string weapons[], int cost);

        int getCost();

        void setArmor(string armor[]);
        void setWeapons(string weapons[]);
        void setCost(int cost);
};

#endif