#include "Pokemon.h"
#include "Trainer.h"
#include <iostream>
using namespace std;

// int arr[10]; - garbage or 0
// string arr1[10]; - ""
// Pokemon p[10]; - default constructor

Trainer::Trainer()
{
    _name = "----";
    _type = "";
    _points = 0;
    // array - explicitly initialize the elements
    // _myPokemons[SIZE] = {0};
    for(int i =0; i< SIZE; i++)
    {
        _myPokemons[i] = Pokemon();
    }

}
Trainer::Trainer(string name, Pokemon p[], string type, double points, int numPokemons) // project 3
{
    _name = name;
    _type = type;
    _points = points;
    _numPokemons = numPokemons;
    // 1 - copy all pokemons in p into _myPokemons //
    // 2 - initialize the remaining elements in _myPokemons to 0/empty

}

// getters
string Trainer::getName()
{
    return _name;
}
string Trainer::getType()
{
     return _type;
}
double Trainer::getPoints()
{
    return _points;
}
Pokemon Trainer::getPokemon(string name) 
{
    int flag = true; // found, check
    int index = 0;
    for(int i =0; i< _numPokemons; i++)
    {
        cout << name << "   " << _myPokemons[i].getName() << endl;
        if(name == _myPokemons[i].getName())
        {
            index = i;
            flag = false; // updating the status
            break;
        }
    }
    if(!flag)
    {
        return _myPokemons[index];
    }
    else //  what do you return if you can't find the pokemon
    {
        return Pokemon();
    } 
}


// setters
void Trainer::setName(string name)
{
    _name = name;
}
void Trainer::setType(string type)
{
    _type = type;
}
void Trainer::setPoints(double points)
{
    _points = points;
}
void Trainer::setPokemon(Pokemon p)
{
    // check if there is space to store an extra object
    _myPokemons[_numPokemons] = p;
    // increment _numPokemons to reflect teh correct number of pokemons stored in _myPokemons
    _numPokemons++;
}

// other function
void Trainer::updatePoints(double val)
{
    _points = _points + val;
}