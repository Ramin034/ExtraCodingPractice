#include <iostream>
#include <vector>
#include <fstream>
#include "schedule.h"
#include "course.h"
using namespace std;

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

bool caseinsensitive(string upperuser, string loweruser)
{
    char up;
    char upper;
    if(upperuser.length()!=loweruser.length())
    {
        return false;
    }
    for(int i=0; i<upperuser.length(); i++)
    {
        up=upperuser.at(i);
        upper=loweruser.at(i);
        if(loweruser.at(i)>=97 && loweruser.at(i)<=122)
        {
            upper=loweruser.at(i)-32;
        }
        if(upperuser.at(i)>=97 && upperuser.at(i<=122))
        {
            up=upperuser.at(i)-32;
        }
        if(up!=upper)
        {
           return false;
        }
    }
    return true;
}



Schedule::Schedule(string _studentName)
{
  studentName = _studentName;
  enrolledHours= 0;
}

string Schedule::getStudentName()
{
  return studentName;
}

int Schedule::getEnrolledHours()
{
  return enrolledHours;
}

bool Schedule::loadCourses(string filename)
{
  ifstream fin;

  fin.open(filename);

  if(fin.is_open())
  {
    string line;
    string arr[2];
    int value=0;
    

    while(getline(fin,line))
      {
      //  cout << line << endl;

        
        split(line, ',', arr, 2);
        value=stoi(arr[1]);
        string name=arr[0];

       // cout << name << " " << value << endl;
         
        if(line!=""){
            Course c1;
            c1.number = name;
            c1.hours = value;
            available.push_back(c1);
          }
        /*
        for(int i=0; i<sizeof(arr); i++)
          {
            if(line=="")
            {
              continue;
            }
            else
            {
              Course c1;
              c1.number = name;
              c1.hours = value;
              available.push_back(c1);
            }
          }
        */
        
        
      }
       return true;
  }
  else
  {
    return false;
  }
}

void Schedule::displayAvailableCourses()
{
  if(available.size()==0)
  {
    cout<< "There are no available courses."<<endl;
  }
  else
  {
    cout<< "Courses available for registration:"<<endl;

    for(int i=0; i<available.size(); i++)
    {
      cout << available.at(i).number << "," << available.at(i).hours << endl;
    }
  }
}

int Schedule::addCourse(string num)
{
  for(int i=0; i<available.size(); i++){
    if(caseinsensitive(available.at(i).number,num)){

      //checks if the course is less than 15 hours
     if( available.at(i).hours <= 15){
       //add class to enrolled
      enrolled.push_back( available.at(i) );
       //decrease current enrolled hours
      enrolledHours -= available.at(i).hours;
       //removes classes from available
      available.erase( available.begin() + i );
      return 1; //class added
      }
      else{
        return 0; //indicate class is there but more than 15
      }//check hours
    } //check case

    }//close for loop

  return -1; //class  does not exist
}

