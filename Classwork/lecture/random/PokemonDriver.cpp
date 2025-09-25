#include "Pokemon.h"
#include <iostream>

using namespace std;

int main()
{
    // creating object using the default constructor
    Pokemon pikachu; // an instance of a class
    pikachu.setName("Pikachu");
    pikachu.setHP(82);
    pikachu.setDefense(61);
    pikachu.setAttack(76);
    pikachu.setSpeed(90);
    pikachu.setMax(100);
    pikachu.setType1("Electric");
    cout << "printing Pikachu's attributes" << endl;
    pikachu.display();

    //  creating object using the parameterized constructor
    Pokemon charmander(0, "Charmander", 20, 37, 19, 27, 100, "fire", "none");
    cout << "printing Charmander's attributes" << endl;
    charmander.display();

    // we can also assign an object to another object of the same class through the assignment operator (=)
    // Pokemon temp = pikachu;


    // creating an array of 5 pokemon objects. each element in this array is an object of type Pokemon
    Pokemon myPokemons[5];
    // you can also initialize an array of objects using the assignment operator at the time of declaration
    // Pokemon myPokemons[5] = {pikachu, charmander, Pokemon(), Pokemon()}; Pokemon() calls the default constructor

    for(int i = 0; i <5; i++)
    {
        // print the object stored at location i
        myPokemons[i].display();
    }

    // initializing the objects in an array
    // approach 1
    myPokemons[0] = pikachu; // and copy the contents of existing object pikachu to the object at location 0

    // approach 2 - parameterized constructor - order matters!!!
    myPokemons[1] = Pokemon(0, "Charmander", 20, 37, 19, 27, 100, "fire", "none"); 
    // approach 3 - calling setters for each data member in the Class
    myPokemons[2].setName("Bulbosaur");
    myPokemons[2].setAttack(100);
    myPokemons[2].setDefense(28);
    myPokemons[2].setHP(78);
    myPokemons[2].setMax(100);
    myPokemons[2].setNum(10);
    myPokemons[2].setType1("Grass");
    for(int i = 0; i <5; i++)
    {
        // print the object stored at location i
        myPokemons[i].display();
    }
    
    return 0;
}