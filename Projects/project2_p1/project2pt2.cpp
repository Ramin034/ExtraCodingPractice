// project2pt2.cpp

// CSCI 1300 Spring 2022
// Author: Ramin Akbari
// Recitation: 102 – Nikhith Sannidhi
// Project 2 Part 2 - Problem # 0


#include "Movie.h"
#include "User.h"
#include "Blockbustr.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num=0;
    Blockbustr myBlockbustr;
    string filename;
    string year;
    string username;
    string title;
    string input;
    int value=0;
    int numMovies=0;
    int numUsers=0;
    double average=0;
    int rating=0;

    do
    {
        
        cout<<"======Main Menu=====\n"
            "1. Read movies\n"
            "2. Read ratings\n"
            "3. Print movies by year\n"
            "4. Get rating\n"
            "5. Find number of movies user rated\n"
            "6. Get average rating\n"
            "7. Add a user\n"
            "8. Rent a movie\n"
            "9. Quit"<<endl;
        getline(cin,input);
        num=stoi(input);    //turns string into int
        switch(num)
        {
        case 1: 
            cout<< "Enter a movie file name:"<<endl;
            getline(cin,filename);
            numMovies=myBlockbustr.readMovies(filename); // calls read movie function and stores it
            if(numMovies==-1)
            {
                cout<<"No movies saved to the database."<<endl; //goes through if statemnts based on return value
            }
            else if(numMovies==-2)
            {
                cout<< "Database is already full. No movies were added."<<endl;
            }
            else if(numMovies==50)
            {
                cout<<"Database is full. Some movies may have not been added."<<endl;
            }
            else
            {
                cout<<"Total movies in the database: "<<numMovies<<endl;
            }
            break;
        case 2:
            cout<<"Enter a user file name:"<<endl;
            getline(cin,filename);
            numUsers=myBlockbustr.readRatings(filename);    //calls read ratings function and stores return value into numUsers
            if(numUsers==-1)
            {
                cout<<"No users saved to the database."<<endl;  //based on return value go through if statements
            }
            else if(numUsers==-2)
            {
                cout<<"Database is already full. No users were added."<<endl;
            }
            else if(numUsers==myBlockbustr.getSizeUser())   //checks if database is full
            {
                cout<<"Database is full. Some users may have not been added."<<endl;
            }
            else
            {
                cout<<"Total users in the database: "<< numUsers<<endl;
            }
            break;
        case 3:
            
             if(numMovies==0 || numUsers==0)    //if number of movies or users are found go through this if
            {
                cout<< "Database has not been fully initialized."<<endl;
            }
            else
            {
                cout<< "Enter release year of movie:"<<endl;
                getline(cin,year);
                if(numMovies>0 || numUsers>0)
                {
                    myBlockbustr.printMoviesByYear(year);
                }
            }
            break;
        case 4:

            if(numMovies==0 || numUsers==0)
            {
               cout<< "Database has not been fully initialized."<<endl;
            }
            else
            {

                cout<< "Enter a user name" <<endl;
                getline(cin,username);
                cout<< "Enter a movie title"<<endl;
                getline(cin,title);

                if(numMovies>0 || numUsers>0)
                {
                    value=myBlockbustr.getRating(username, title);  //saves return value of getRating into value
                    if(value==0)
                    {
                        cout<< username<< " has not rated "<< title<<endl;
                    }
                    else if(value==-3)
                    {
                        cout<< username<< " or "<< title << " does not exist."<<endl;
                    }
                    else
                    {
                        cout<<username<< " rated "<<title<< " with "<< value<<endl;
                    }
                }
            }
            break;
        case 5:


            if(numMovies==0 || numUsers==0)
            {
               cout<< "Database has not been fully initialized."<<endl;
            }
            else
            {
                cout<< "Enter a user name:"<<endl;
                getline(cin,username);
                
                if(numMovies>0 || numUsers>0)
                {
                    value=myBlockbustr.getCountWatchedMovies(username); //saves return value into value
                    if(value==0) 
                    {
                        cout<<username<< " has not rated any movies."<<endl;
                    }
                    else if(value==-3)
                    {
                        cout<< username << "  does not exist."<<endl;
                    }
                    else
                    {
                        cout<< username<< " rated "<< value<< " movies."<<endl;
                    }
                
                }
            }
            break;
        case 6:

            if(numMovies==0 || numUsers==0)
            {
                cout<< "Database has not been fully initialized."<<endl;
            }
            else
            {
                cout<< "Enter a movie title:"<<endl;
                getline(cin, title);
                

                if(numMovies>0 || numUsers>0)
                {
                    average=myBlockbustr.calcAvgRating(title);  //finds the average rating for a movie
                    if(average==-3)
                    {
                        cout<< title<< " does not exist."<<endl;
                    }
                    else
                    {
                        cout<< "The average rating for " << title<<  " is " << average<< endl;
                    }
                }
            }
            break;
        case 7:

            cout<< "Enter a user name:"<<endl;
            getline(cin,username);
            value= myBlockbustr.addUser(username);
            if(value==1)
            {
                cout<< "Welcome to Blockbustr "<< username<< endl;
            }
            if(value==0)
            {
                cout<< username<<" already exists in the database."<<endl;
            }
            if(value==-2)
            {
                cout<<"Database is already full. " <<username<< " was not added."<<endl;
            }
            break;
        case 8:
            if(numMovies==0 || numUsers==0)
            {
                cout<< "Database has not been fully initialized."<<endl;
            }
            else
            {
                cout<< "Enter a user name:"<<endl;
                getline(cin,username);
                cout<<"Enter a movie title:"<<endl;
                getline(cin,title);
                cout<< "Enter a new rating"<< endl;
                getline(cin,input);
                rating=stoi(input);
                
                if(numMovies>0 || numUsers>0)
                {
                    value= myBlockbustr.rentMovie(username, title, rating);
                    if(value==1)
                    {
                        cout<< "We hope you enjoyed your movie. The rating has been updated."<<endl;
                    }
                    if(value==-4)
                    {
                        cout<< rating << " is not valid."<<endl;
                    }
                    if(value==-3)
                    {
                        cout<< username<< " or "<< title<< " does not exist."<<endl;
                    }
                }
            }
            
            break;
        case 9:
            {
            cout<< "Good bye!"<<endl;
            break;
            }
           
        default:    //if user inputs anything that aren't in the menu they run this
            {
                cout<< "Invalid input."<<endl;
                break;
            }
            
            

        }
    } while (num!=9);
    
}