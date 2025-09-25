//  songStreamStats.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Homework 6 - Problem # 1


#include <iostream>
#include <fstream>
using namespace std;

/**
  * algorithm: takes a string, splits it at every occurrence of a delimiter
  * 1. Accept inputString, separator, arr, size which then passes through the function
  * 2. if the string has a length bigger than 0 pass through loop
  * 3. find when the inputString has the separators and split it
  * 4. save the inputString into the array 
  * 5. everytime inputString has a separator in is count it.
  * 6. if count is bigger than or equal too size then return -1
  * 7. if their is nothing in the array return 0
  * Parameter: inputString(string), separator(char), arr(string), size(int)
  * Returns: return the number of pieces the string split into, if a delimiter isn't found return 1,
    if the string is empty return 0
*/


int split(string inputString, char separator, string arr[], int size)
{
    int savepoint=0;    //a savepoint and count is initialized.
    int count=0;
    for(int i=0; i<inputString.length(); i++)
    {
        if(inputString[i]==separator)
        {
            arr[count]=inputString.substr(savepoint, i-savepoint);  //each part of the string is saved into the array
            savepoint=i+1;
        }

        if(inputString[i]==separator)   //whenever a character in the string is the separator the count adds 1
        {
            count++; 
        }

        if(count>=size)
        {
            return -1;
        }
    }

     arr[count]=inputString.substr(savepoint);

    if(inputString.length()==0)
    {
        return 0;
    }

    return count+1;

}

/*
 * algorithm: Finds the most and least streamed song
 * 1. Accepts filename which then passes through function
 * 2. if filename opens check for largest value and for smallest value
 * 3. if the line is empty continue
 * 4. if line is read add 1 to count
 * 5. if file could not open print error message
 * Parameters: filename(string)
 * Returns: nothing(void)
*/

void songStreamStats(string filename)
{
    ifstream fin;
    fin.open(filename);

    if(fin.is_open())
    {
       string line; //initialized variables 
       int largest=0;
       int count=0;
       int smallest=0x7fffffff; // largest possible int
       string arr[2];
       string pop_song;
       string unpop_song;
       while(getline(fin,line))
        {
            split(line, ',', arr, 2);   //splits the string whenever there is a ','
            int value=stoi(arr[1]); //converts the arr[1] into ints.
            string name= arr[0];
            if(line=="")
            {
                continue;
            }
            if(value>=largest)
            {
                pop_song= name; // saves the song with the most streams into pop_song
                largest=value;  // saves the value into largest
            }
            if(value<=smallest)
            {
                unpop_song=name;    // saves the song with the least streams into unpop_song
                smallest= value;    // saves the value into smallest
            }
            count++;
        }
        cout<< "Number of lines read: "<< count<<"."<< endl;
        cout<< "Most streamed song: " <<pop_song <<" with "<< largest<<" streams."<< endl;
        cout<< "Least streamed song: "<< unpop_song<<" with "<< smallest<< " streams."<<endl;

    }
    else
    {
        cout<< "Could not open file."<<endl;
    }

    fin.close();
    
}

int main()
{
    string arr[2];
    string filename = "song_samples.txt";
    songStreamStats(filename);
}