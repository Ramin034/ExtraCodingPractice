// planet.h

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 3


#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include "player.h"
#include "time.h"
#include <vector>
using namespace std;

class Planet
{
  private:
    vector<string>_planetName;
    vector<string>_randomlet;
    vector<int>_planetSize;
    int _fuelforplanet;
    int _oxygen;
    int _water;
    int _soil;
    int _toxgas;
    int _atmosphere;
    int _temp;
    

  public:
    Planet();
    Planet(vector<string>planetName, vector<string>randomlet, vector<int>planetSize, int fuelforplanet, int oxygen, int water, int soil, int toxgas, int atmosphere, int temp);
    string getPlanetName();
    string getRandomlet();
    int getPlanetSize();
    int getOxygen();
    int getWater();
    int getSoil();
    int getToxgas();
    int getatmosphere();
    int getTemp();

    void setPlanetName(vector<string>planets);
    void setRandomlet(vector<string>randomlet);
    void setPlanetSize(vector<int>planetSize);
    void setOxygen(int oxygen);
    void setWater(int water);
    void setSoil(int soil);
    void setToxgas(int toxgas);
    void setAtmosphere(int atmosphere);
    void setTemp(int temp);

    
};

#endif