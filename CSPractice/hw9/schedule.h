#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <vector>
#include "course.h"
using namespace std;

class Schedule
{
  private:
    string studentName;
    int enrolledHours;
    vector<Course> available;
    vector<Course> enrolled;

  public:
    Schedule(string _studentName);

    string getStudentName();
    int getEnrolledHours();

    bool loadCourses(string filename);
    void displayAvailableCourses();
    int addCourse(string num);
    bool dropCourse(string num);
    bool writeSchedule(string filename);
  
};

#endif