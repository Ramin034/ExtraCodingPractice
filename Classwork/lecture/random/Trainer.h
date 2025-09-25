#ifndef TRAINER_H
#define TRAINER_H

#include "Pokemon.h"
#include <iostream>
using namespace std;

class Trainer
{
    public:
        Trainer(); // default
        Trainer(string, Pokemon[], string, double, int);

        // getters
        string getName();
        string getType();
        double getPoints();
        Pokemon getPokemon(string); // index, name, type


        // setters
        void setName(string);
        void setType(string);
        void setPoints(double);
        void setPokemon(Pokemon); // file

        // other function
        void updatePoints(double val);

    private:
        string _name;
        const static int SIZE = 6;
        Pokemon _myPokemons[SIZE];
        int _numPokemons;
        string _type;
        double _points;

};

#endif

