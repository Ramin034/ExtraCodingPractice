// player.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 3



#include <iostream>
#include <string>
#include "player.h"
#include "planet.h"
using namespace std;

Player::Player(){
  _name = "";
  _hp = 0;
  _fuel = 0;
  _money = 0;
  for(int i=0; i<SIZE; i++)
    {
      _inventory[i]="";
    }
  _defense = 0;
  _attack=0;
  _weaponhp=0;
  _armorhp=0;
  _meds=0;
}
  

Player::Player(string name, int hp, int fuel, int money, string inventory[], int defense, int armorhp, 
int attack, int weaponhp, int meds,  string armorName, string weaponName)
{
  _name=name;
  _hp=hp;
  _fuel=fuel;
  _money=money;
  for(int i=0; i<SIZE; i++)
    {
      _inventory[i]=inventory[i];
    }
  _defense=defense;
  _attack=attack;
  _weaponhp=weaponhp;
  _armorhp=armorhp;
  _meds=meds;
  
}

string Player::getName()
{
  return _name;
}

int Player::getHp()
{
  return _hp;
}

int Player::getFuel()
{
  return _fuel;
}

int Player::getMoney()
{
  return _money;
}

string Player::getInventory()
{

  string allinventory = "";

  for(int i=0; i<SIZE; i++)
    {
      allinventory += _inventory[i] + " ";
    }
  
  return allinventory;
}

int Player::getDefense()
{
  return _defense;
}

int Player::getArmorhp()
{
  return _armorhp;
}

string Player::getArmorName()
{
  return _armorName;
}

string Player::getWeaponName()
{
  return _weaponName;
}

int Player::getMeds()
{
  return _meds;
}


void Player::setName(string name)
{
  _name=name;
}

void Player::setHp(int hp)
{
  _hp=hp;
}

void Player::setFuel(int fuel)
{
  _fuel=fuel;
}

void Player::setMoney(int money)
{
  _money=money;
}

void Player::setInventory(string inventory[])
{
  for(int i=0; i<SIZE; i++)
    {
      _inventory[i]=inventory[i];
    }
}

void Player::setAttack(int attack)
{
    _attack = attack;
}

void Player::updateHp(int enemyHits)
{
  _hp -= enemyHits;
}

void Player::setDefense(int defense)
{
  _defense = defense;
}

void Player::setWeaponhp(int weaponhp)
{
    _weaponhp=weaponhp;
}

void Player::setArmorhp(int armorhp)
{
  _armorhp=armorhp;
}

void Player::setArmorName(string armorName)
{
  _armorName=armorName;
}

void Player::setWeaponName(string weaponName)
{
  _weaponName=weaponName;
}

void Player::setMeds(int meds)
{
  _meds=meds;
}