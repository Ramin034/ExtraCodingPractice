#ifndef GAME_H
#define GAME_H

#include "Trainer.h"
#include "Pokemon.h"

class Game
{
    public:
        Game();
        Game(Trainer[], int, Pokemon[], int, int);

        // getter
        int getNumPokemons();
        int getNumTrainers();
        int getLevel();
        Trainer getTrainerAt(int); // index, name
        Pokemon getPokemonAt(int);

        // setter
        void setNumPokemons(int);
        void setNumTrainers(int);
        void setLevel(int);
        bool setTrainerAt(Trainer, int);
        bool setPokemonAt(Pokemon, int);

        // other functions
        Pokemon battle(Pokemon, Pokemon);
        void printLeaderBoard();

        // temporary initialization function
        // equivalent to readMovies and readRatings
        void init();


    private:
        const static int _totalTrainers = 5;
        Trainer _trainers[_totalTrainers];
        const static int _totalPokemons = 140;
        Pokemon _wildPokemons[_totalPokemons];
        int _numPokemons;
        int _numTrainers;
        int _level;
};

#endif