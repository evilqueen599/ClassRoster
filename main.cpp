#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

int main()
{
    cout << " C867 Scripting and Programming Applications--Student Roster Project \n";
    cout << " Coded in C++\n";
    cout << " Student ID: 001433910\n";
    cout << " Student Name: Tricia Smith\n";
    cout << "\n\n";

    //student data table
    const string studentData[] =
    { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Tricia,Smith,smithtricia91@gmail.com@gmail.com, 29,3,6,12,SOFTWARE"
    };

    const int amtStudents = 5;
    Roster roster;
    
    //prints student roster
    for (int i = 0; i < amtStudents; i++) roster.parse(studentData[i]);
    cout << "List of current students in roster:\n";
    roster.printAll();
    cout << "\n";
    
    //prints all invalid emails in roster
    cout << "List of invalid emails in roster: \n";
    roster.printInvalidEmails();
    cout << "\n";
    
    //prints only students with a softwarwe major
    cout << "All students with declared SOFTWARE major: \n";
    roster.printByProgram(SOFTWARE);
    cout << "\n";
    
    //prints the students average number of days in courses
    cout << "Average number of days per courses: \n";
    for (int i = 0; i < amtStudents; i++)
    {
        roster.printAvgDaysInCourses(roster.classRosterArray[i]->getStudentID());
    }
    cout << "\n";
    
    //removes student by id whilst confirming removal
    cout << "...Removing student ID 'A3'... \n";
    roster.removeStudent("A3");
    cout << "\n";
    
    //repeat of removal process to out error that student is not found
    cout << "...Verifying removal of student ID 'A3'...\n";
    roster.removeStudent("A3");
    cout << "\n\n";
  

}
