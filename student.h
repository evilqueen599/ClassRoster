#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "degree.h"
using namespace std;

//student class contains all student declaration and functions
class Student
{
public:
    const static int numCourses = 3;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourses[numCourses];
    DegreeProgram degreeProgram;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourses[], DegreeProgram degreeProgram);
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourses();
    DegreeProgram getProgram();

    void setID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourses(int daysInCourses[]);
    void setProgram(DegreeProgram degreeProgram);;

    static void printHeader(); 
    void printStudent();
   
    ~Student();
};
