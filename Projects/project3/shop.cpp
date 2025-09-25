// shop.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 3



#include <iostream>
#include "shop.h"
#include "planet.h"
#include "player.h"
using namespace std;

Shop::Shop()
{
    for(int i=0; i<=4; i++)
    {
        _armor[i]="";
    }
    for(int i=0; i<=3; i++)
    {
        _weapons[i]="";
    }
    _cost=0;
}

Shop::Shop(string armor[], string weapons[], int cost)
{
    for(int i=0; i<=4; i++)
    {
        _armor[i]=armor[i];
    }

    for(int i=0; i<=3; i++)
    {
        _weapons[i]=weapons[i];
    }

    _cost=cost;
}


int Shop::getCost()
{
    return _cost;
}

void Shop::setArmor(string armor[])
{
    for(int i=0; i<=4; i++)
    {
        _armor[i]=armor[i];
    }
}

void Shop::setWeapons(string weapons[])
{
    for(int i=0; i<=3; i++)
    {
        _weapons[i]=weapons[i];
    }
}

void Shop::setCost(int cost)
{
    _cost=cost;
}