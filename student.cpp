#include <iostream>
#include "student.h"
#include "degree.h"


Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < numCourses; i++) this->daysInCourses[i] = 0;//
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourses[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < numCourses; i++) this->daysInCourses[i] = daysInCourses[i];
    this->degreeProgram = degreeProgram;
}

Student::~Student() {}


string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourses() { return this->daysInCourses; }
DegreeProgram Student::getProgram() { return this->degreeProgram; }

void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourses(int daysInCourses[])
{
    for (int i = 0; i < numCourses; i++) this->daysInCourses[i] = daysInCourses[i];
}
void Student::setProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//header that keeps roster data organized 
void Student::printHeader()
{
    cout << "ID:" << "\t" << "First:" << "\t" << "Last:" << "\t\t" << "Email Address:" << "\t\t\t" << "Age:" << "\t" << "Days in Courses:" << "\t" << "Degree Program:" << "\n";
}
//print student function, determines how the roster information is displayed on console(formatting)
void Student::printStudent()
{
    cout << this->getStudentID() <<"\t";
    cout << this->getFirstName() << "\t";
    cout << this->getLastName() << setw(5) << "\t";
    cout << this->getEmailAddress() << setw(7) << "\t";
    cout << this->getAge() << setw(4) << "\t";
    cout << this->getDaysInCourses()[0] << ',';
    cout << this->getDaysInCourses()[1] << ',';
    cout << this->getDaysInCourses()[2] << setw(8) << "\t\t";
    cout << programStrings[this->getProgram()] << '\n';
}
