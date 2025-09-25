// planet.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 3



#include <iostream>
#include "planet.h"
#include "player.h"
#include "time.h"
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

Planet::Planet()
{

   string allNumberLetters = "0123456789abcdefghijklmnopqrstuvwxyz";

  for(int i = 1; i <= 5; i++){

    string pN = "";

    for(int i = 1; i <= 4; i++){
      int r = round( rand() * allNumberLetters.length() );
      pN = pN + allNumberLetters.at(r);
    }
    
    _planetName.push_back(pN);

    
    ifstream fin;

    fin.open("four_letter_words.txt");

    string line;
    int count=0;

    while(getline(fin,line))
      {
        count++;
      }
    fin.close();
    
     int rt = round( rand() * count );

    ifstream fin2;
    fin2.open("four_letter_words.txt");
    string line2;
    int count2=0;

    while(getline(fin2,line2))
      {
        count2++;
        if( count2 == rt ){
          _randomlet.push_back(line2);
          break;
        }
          
      }
    fin2.close();
     
   double carry;
    int max=8*2;
    int min=1*2;
    double psizeR = round( rand() * (max-min) + min ) * 0.5;

    carry= psizeR * 615;
    
  }
  
    _oxygen=0;
    _water=0;
    _soil=0;
    _toxgas=0;
    _atmosphere=0;
    _temp=0;
}

Planet::Planet(vector<string>planetName, vector<string>randomlet, vector<int>planetSize, int fuelforplanet, int oxygen, int water, int soil, int toxgas, int atmosphere, int temp)
{
     
  
  string allNumberLetters = "0123456789abcdefghijklmnopqrstuvwxyz";

  for(int i = 1; i <= 5; i++){

    string pN = "";

    for(int i = 1; i <= 4; i++){
      int r = round( rand() * allNumberLetters.length() );
      pN = pN + allNumberLetters.at(r);
    }
    
    _planetName.push_back(pN);

    
    ifstream fin;

    fin.open("four_letter_words.txt");

    string line;
    int count=0;

    while(getline(fin,line))
      {
        count++;
      }
    fin.close();
    
     int rt = round( rand() * count );

    ifstream fin2;
    fin2.open("four_letter_words.txt");
    string line2;
    int count2=0;

    while(getline(fin2,line2))
      {
        count2++;
        if( count2 == rt ){
          _randomlet.push_back(line2);
          break;
        }
          
      }
    fin2.close();

    
    double carry;
    int max=8*2;
    int min=1*2;
    double psizeR = round( rand() * (max-min) + min ) * 0.5;

    carry= psizeR * 615;
    
  }

  

  


  
  
    _oxygen=oxygen;
    _water=water;
    _soil=soil;
    _toxgas=toxgas;
    _atmosphere=atmosphere;
    _temp=temp;
}


string Planet::getPlanetName()
{

  string allPlanetstr = "";
  
  for(int i=0; i<_planetName.size(); i++)
    {
      allPlanetstr+= _planetName.at(i);
    }

  return allPlanetstr;
}

string Planet::getRandomlet()
{
  string allrandstr = "";

  for(int i=0; i<_randomlet.size(); i++)
    {
      allrandstr+= _randomlet.at(i);
    }
  return allrandstr;
}



int Planet::getOxygen()
{
    return _oxygen;
}

int Planet::getWater()
{
    return _water;
}

int Planet::getSoil()
{
    return _soil;
}

int Planet::getToxgas()
{
    return _toxgas;
}

int Planet::getatmosphere()
{
    return _atmosphere;
}

int Planet::getTemp()
{
    return _temp;
}


void Planet::setOxygen(int oxygen)
{
    _oxygen=oxygen;
}

void Planet::setWater(int water)
{
    _water=water;
}

void Planet::setSoil(int soil)
{
    _soil=soil;
}

void Planet::setToxgas(int toxgas)
{
    _toxgas=toxgas;
}

void Planet::setAtmosphere(int atmosphere)
{
    _atmosphere=atmosphere;
}

void Planet::setTemp(int temp)
{
    _temp=temp;
}