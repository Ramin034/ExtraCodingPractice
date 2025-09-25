#include "Game.h"
#include "Trainer.h"
#include "Pokemon.h"

Game::Game()
{
    _numPokemons = 0;
    _numTrainers = 0;
    _level = 0;
}
Game::Game(Trainer trainers[], int numTrainers, Pokemon wildPokemons[], int numPokemons, int level)
{
    _numPokemons = numPokemons;
    _numTrainers = numTrainers;
    _level = level;
    // copy contents from trainers array into data member _trainers array
    // copy contents from wildPokemons array into data member _wildPokemons array
}

// getter
int Game::getNumPokemons()
{
    return _numPokemons;
}
int Game::getNumTrainers()
{
    return _numTrainers;
}
int Game::getLevel()
{
    return _level;
}
// return the trainer object at index in _trainers
Trainer Game::getTrainerAt(int index)
{
    // implementation similar to getRatingAt(int) in User class 
}
// return the pokemon object at index in _wildPokemons
Pokemon Game::getPokemonAt(int index)
{
    // implementation similar to getRatingAt(int) in User class
}

// setter
void Game::setNumPokemons(int numPokemons)
{
    _numPokemons = numPokemons;
}
void Game::setNumTrainers(int numTrainers)
{
    _numTrainers = numTrainers;
}
void Game::setLevel(int level)
{
    _level = level;
}
// copy trainer temp into _trainers[index] if there is space in the _trainers array
bool Game::setTrainerAt(Trainer temp, int index)
{
    // implementation similar to setRatingAt(int, int) in User class
}
// copy pokemon temp into _wildPokemons[index] if there is space in the _wildPokemons array
bool Game::setPokemonAt(Pokemon temp, int index)
{
    // implementation similar to setRatingAt(int, int) in User class
}

// other functions
Pokemon Game::battle(Pokemon p1, Pokemon p2)
{
    if(p1.getAttack() > p2. getDefense())
    {
        return p1;
    }
    else 
    {
        return p2;
    }
}

void Game::printLeaderBoard()
{
    cout << "LEADERBOARD!!!" << endl;
    for(int i = 0; i < _numTrainers; i++)
    {
        cout << _trainers[i].getName() << "    " << _trainers[i].getPoints() << endl;
    }
}

void Game::init()
{
    Pokemon temp1, temp2;
    Pokemon p_array1[1];
    Pokemon p_array2[2];
    temp1 = Pokemon(0, "Charmander", 82, 80, 78, 91, 92, "fire", "none");

    p_array1[0] = temp1;;
    // adding one trainer
    // following won't work because the parameterized constructor in Trainer.cpp is not fully implemented
    Trainer brock("Brock", p_array1, "catcher", 92, 1);
    _trainers[_numTrainers] = brock; 
    _numTrainers++;

    temp1 = Pokemon(1, "Pikachu", 20, 77, 78, 61, 90, "electric", "none");

    p_array1[0] = temp1;;
    // creating another trainer
    // following won't work because the parameterized constructor in Trainer.cpp is not fully implemented
    Trainer ash("Ash", p_array1, "catcher", 92, 1);
    _trainers[_numTrainers] = ash; 
    _numTrainers++;

    temp1 = Pokemon(2, "Bulbasaur", 91, 82, 75, 81, 90, "grass", "poison");
    temp2 = Pokemon(3, "Squirtle", 88, 76, 81, 78, 89, "water", "none");
    // store these temp pokemons into array p
    p_array2[0] = temp1;
    p_array2[1] = temp2;
    // creating another trainer
    // following won't work because the parameterized constructor in Trainer.cpp is not fully implemented
    Trainer misty("Misty", p_array2, "catcher", 98, 2);
    _trainers[_numTrainers] = misty; // 0
    _numTrainers++;
}