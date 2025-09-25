#include "Pokemon.h"
#include "Trainer.h"
#include <iostream>
using namespace std;


Pokemon battle(Pokemon p1, Pokemon p2)
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

void printLeaderboard(Trainer t[], int numTrainers)
{
    cout << "LEADERBOARD!!!" << endl;
    for(int i = 0; i < numTrainers; i++)
    {
        cout << t[i].getName() << "    " << t[i].getPoints() << endl;
    }
}



int main()
{   
    const int totalTrainers = 4;
    Trainer trainers[totalTrainers];
    int numTrainers = 0;
    const int totalPokemons = 140;
    Pokemon wildPokemons[totalPokemons];
    int numPokemons = 0;
    // creating temporary pokemon objects and array
    Pokemon temp1, temp2;
    Pokemon p_array1[1];
    Pokemon p_array2[2];
    temp1 = Pokemon(0, "Charmander", 82, 80, 78, 91, 92, "fire", "none");

    p_array1[0] = temp1;;
    // adding one trainer
    // following won't work because the parameterized constructor in Trainer.cpp is not fully implemented
    Trainer brock("Brock", p_array1, "catcher", 92, 1);
    trainers[numTrainers] = brock; 
    numTrainers++;

    temp1 = Pokemon(1, "Pikachu", 20, 77, 78, 61, 90, "electric", "none");

    p_array1[0] = temp1;;
    // creating another trainer
    // following won't work because the parameterized constructor in Trainer.cpp is not fully implemented
    Trainer ash("Ash", p_array1, "catcher", 92, 1);
    trainers[numTrainers] = ash; 
    numTrainers++;

    temp1 = Pokemon(2, "Bulbasaur", 91, 82, 75, 81, 90, "grass", "poison");
    temp2 = Pokemon(3, "Squirtle", 88, 76, 81, 78, 89, "water", "none");
    // store these temp pokemons into array p
    p_array2[0] = temp1;
    p_array2[1] = temp2;
    // creating another trainer
    // following won't work because the parameterized constructor in Trainer.cpp is not fully implemented
    Trainer misty("Misty", p_array2, "catcher", 98, 2);
    trainers[numTrainers] = misty; // 0
    numTrainers++;


    printLeaderboard(trainers, numTrainers);
    
    Pokemon winner = battle(ash.getPokemon("Charmander"), misty.getPokemon("Squirtle"));
    winner.display();


    return 0;
}
