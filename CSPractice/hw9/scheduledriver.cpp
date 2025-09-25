#include <iostream>
#include <vector>
#include <cassert>
#include "schedule.h"
#include "course.h"
using namespace std;

int main()
{
  /*
  Schedule m1("John");

  cout << m1.loadCourses("courses.txt") << endl;

  cout << m1.loadCourses("fake.txt") << endl;

   m1.displayAvailableCourses();

  cout << m1.addCourse("CSCI 1300") << endl;
*/

  //create schedule object
Schedule mySched("Good Student");

//load courses
mySched.loadCourses("courses.txt");

//try registering for a course that doesn't exist
cout << mySched.addCourse("not a real course") << endl;

//register for a course that does exist
cout << mySched.addCourse("csci 1300") << endl;

//register for two more courses for a total of 12 enrolled hours
mySched.addCourse("cSci 3575");
mySched.addCourse("CSCI 3104");

//try registering for more than 15 hours
cout << mySched.addCourse("csci 2270") << endl;
}