#pragma once
#include "student.h"
#include <stdio.h>
//creates rooster class and contains class declarations
class Roster
{
public:
    int classIndex = -1;
    const static int amtStudents = 5;
    Student* classRosterArray[amtStudents]; 

public:
    void parse(string row);
    void add(string studentID,string firstName,string lastName,string studentEmail,
        int age,int daysInCourse1,int daysInCourse2,int daysInCourse3,DegreeProgram degreeProgram);
    void printAll();
    void printByProgram(DegreeProgram degreeProgram);
    void printInvalidEmails();
    void printAvgDaysInCourses(string studentID);
    bool removeStudent(string studentID);
    ~Roster();
};
