#include "Pokemon.h"
#include <iostream>
#include <iomanip>

using namespace std;

Pokemon::Pokemon()
{
    _name = "new pokemon";
    _HP = 100;
    _attack = 5;
    _defense = 5;
    _speed = 5;
    _max = 5;
    _type1 = "none"; //na
    _type2 = "none";
}

Pokemon::Pokemon(int num, string name, int hp, int attack, int defense, int speed, int max, string type1, string type2)
{
    _num = num;
    _name = name;
    _HP = hp;
    _attack = attack;
    _defense = defense;
    _speed = speed;
    _max = max;
    _type1 = type1;
    _type2 = type2;
}

// getters
int Pokemon::getNum()
{
    return _num;
}
string Pokemon::getName() // function is associated with class Pokemon
{
    return _name;
}

int Pokemon::getHP()
{
    return _HP;
}

int Pokemon::getAttack()
{
    return _attack;
}

int Pokemon::getDefense()
{
    return _defense;
}
int Pokemon::getSpeed()
{
    return _speed;
}
int Pokemon::getMax()
{
    return _max;
}
string Pokemon::getType1()
{
    return _type1;
}
string Pokemon::getType2()
{
    return _type2;
}
// setters
void Pokemon::setNum(int num)
{
    _num = num;
}
void Pokemon::setName(string n)
{
    _name = n;
}

void Pokemon::setHP(int hp)
{
    _HP = hp;
}

void Pokemon::setAttack(int attack)
{
    _attack = attack;
}
void Pokemon::setDefense(int defense)
{
    _defense = defense;
}
void Pokemon::setSpeed(int speed)
{
    _speed = speed;

}
void Pokemon::setMax(int max)
{
    _max = max;
}
void Pokemon::setType1(string type1)
{
    _type1 = type1;
}
void Pokemon::setType2(string type2)
{
    _type2 = type2;
}
// other functions
void Pokemon::updateHP(int hp)
{
    _HP = _HP + hp;
}

void Pokemon::display()
{
    cout << "==========================================================================" << endl;
    cout << "Info for " << _name << endl; // descriptive header so we know which pokemon's attributes are being displayed
    cout << setw(12) << "HP: " << _HP << endl; // don't forget iomanip
    cout << setw(12) << "Attack: " << _attack << endl;
    cout << setw(12) << "Defense: " << _defense << endl;
    cout << setw(12) << "Speed: " << _speed << endl;
    cout << setw(12) << "Max: " << _max << endl;
    cout << setw(12) << "Type 1: " << _type1 << endl;
    cout << setw(12) << "Type 2: " << _type2 << endl;
    cout << "==========================================================================" << endl;
}