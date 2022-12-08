#include <string>
#include "roster.h"

//parses student data
void Roster::parse(string studentdata)
{
    int rSide = studentdata.find(',');
    string studentID = studentdata.substr(0, rSide);

    int lSide = rSide + 1;
    rSide = studentdata.find(',', lSide);
    string firstName = studentdata.substr(lSide, rSide - lSide);

    lSide = rSide + 1;//continue
    rSide = studentdata.find(',', lSide);
    string lastName = studentdata.substr(lSide, rSide - lSide);

    lSide = rSide + 1; //continue
    rSide = studentdata.find(",", lSide);
    string emailAddress = studentdata.substr(lSide, rSide - lSide);

    lSide = rSide + 1; //continue
    rSide = studentdata.find(",", lSide);
    int age = stoi(studentdata.substr(lSide, rSide - lSide));

    lSide = rSide + 1; //continue
    rSide = studentdata.find(",", lSide);
    int daysInCourse1 = stod(studentdata.substr(lSide, rSide - lSide));

    lSide = rSide + 1; //continue
    rSide = studentdata.find(",", lSide);
    int daysInCourse2 = stod(studentdata.substr(lSide, rSide - lSide));

    lSide = rSide + 1; //continue
    rSide = studentdata.find(",", lSide);
    int daysInCourse3 = stod(studentdata.substr(lSide, rSide - lSide));

    lSide = rSide + 1;
    rSide = studentdata.find(",", lSide);

    DegreeProgram degreeProgram = SECURITY;

    if (studentdata.at(lSide) == 'S' && studentdata.at(lSide + 1) == 'E') degreeProgram = SECURITY;
    else if (studentdata.at(lSide) == 'S' && studentdata.at(lSide + 1) == 'O') degreeProgram = SOFTWARE;
    else if (studentdata.at(lSide) == 'N') degreeProgram = NETWORK;

    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

//add student
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int tempArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++classIndex] = new Student(studentID, firstName, lastName, emailAddress, age, tempArray, degreeProgram);
}

//outputs to console
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::classIndex; ++i) Roster::classRosterArray[i]->printStudent();
}

//finds invalid emails
void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::classIndex; i++)
    {
        string emailAddress = (classRosterArray[i]->getEmailAddress());

        if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos))
        {
            any = true;
            cout << emailAddress << "\n";
        }
    }
}


//calculates the students average number of days
void Roster::printAvgDaysInCourses(string studentID)
{
    for (int i = 0; i <= Roster::classIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDaysInCourses()[0] +
                classRosterArray[i]->getDaysInCourses()[1] +
                classRosterArray[i]->getDaysInCourses()[2]) / 3 << "\n";
        }
    }
}

//allows search by major
void Roster::printByProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::classIndex; i++) {
        if (Roster::classRosterArray[i]->getProgram() == degreeProgram) classRosterArray[i]->printStudent();
    }
    cout << "\n";
}

//removes student from roster by id, also output messages confirming removal and showing student not found error
bool Roster::removeStudent(string studentID)
{
    bool studentRemove = false;
    for (int i = 0; i <= Roster::classIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            studentRemove = true;
            if (i < amtStudents - 1)
            {
                Student* rplcArray = classRosterArray[i];
                classRosterArray[i] = classRosterArray[amtStudents - 1];
                classRosterArray[amtStudents - 1] = rplcArray;
            }
            Roster::classIndex--;
        }
    }
    if (studentRemove)
    {
        cout << " Student with ID number: " << studentID <<  " successfully removed from roster.\n";
        this->printAll();
    }
    else cout << "Student with ID number: " << studentID << " not found in roster. \n" ;
    return 0;
}

//destructor
Roster::~Roster()
{
    cout << "Destructor Activated! \n";
    for (int i = 0; i < amtStudents; i++)
    {
        cout << "Removing student file: " << i + 1 << "\n";
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
};
