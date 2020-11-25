#include <iostream>
#include <iomanip>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

//Defining empty constructor
//The empty constructor sets to default values
Roster::Roster()
{
    this->capacity = 0;
    this->lastIndex = -1; //Empty; 0 is a valid index in an array
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) //Sets a max capacity for the repository
{
    this->capacity = capacity;
    this->lastIndex = -1; //Empty; 0 is a valid index in an array
    this->classRosterArray = new Student * [capacity];
}

void Roster::add(string row) //Add students to studentDataTable

{
    if (lastIndex < capacity) //Goes through the roster and looks for degreeprogram
    {
        lastIndex++;
        int numDays[Student::numDaysSize]; //A temp array to hold degree program for each Student

         //Find DegreeProgram! 

        if (row.substr(row.length() - 8, 8) == "SECURITY")
        {
            this->classRosterArray[lastIndex] = new Student();
            classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
        }
        else if (row.substr(row.length() - 7, 7) == "NETWORK")
        {
            this->classRosterArray[lastIndex] = new Student();
            classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
        }
        else if (row.substr(row.length() - 8, 8) == "SOFTWARE")
        {
            this->classRosterArray[lastIndex] = new Student();
            classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
        }

        else {
            cerr << "Invalid Book Type! Exiting Now!" << endl;
            exit(-1);
        }

        //Parse through the student roster, delimiting on the comma
        //We will then extract each substring and set each field

        //rhs : right hand side
        //lhs : left hand side

        //Get Student ID
        int rhs = row.find(",");
        //cout << studentData[lastIndex].substr(0, rhs) << ' ';
        classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

        //Get Student First Name
        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

        //Get Student Last Name
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

        //Get Email Address
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

        //Read Age changes to int so use stoi
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs))); //modified to not use parray since its just an int

        //Read each DaysInCourse in so use stoi
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        numDays[0] = stoi(row.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        numDays[1] = stoi(row.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        numDays[2] = stoi(row.substr(lhs, rhs - lhs));

        classRosterArray[lastIndex]->setNumDays(numDays);

    }
    else
    {
        cerr << "Error! List has exceeded maximum capacity!" << endl << "Exiting now!";
        exit(-1);
    }

    //End of add()!!!
}

//Roll through the array of students and call print method for each one
void Roster::printAll()
{
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
  
}

bool Roster::remove(string studentID)

{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        //Compares current Student ID to the parameter at index[i]
        if (this->classRosterArray[i]->getStudentID() == studentID) //Student Found
        {
            found = true;
            //If A3 = A3 then delete it! A3 will be passed in
            delete this->classRosterArray[i];
            //Replaces the hole with the last value's Student
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--; //Roster is one element smaller (since we removed A3)
        }
    }
    return found;
}

void Roster::printAverageDaysInCourse(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == studentID) //Student Found
            {
            found = true;
            int* daysInCourse = classRosterArray[i]->getNumDays(); //temp int named daysInCourse
            cout << "Student's average number of days: " << (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3 << endl; //daysInCourse/3 = average
            }
    }
    if (!found)
    {
        cout << "Student not found." << endl;
    }
}

void Roster::printInvalidEmails()
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        string emailAddress = classRosterArray[i]->getEmailAddress();
        if (emailAddress.find("@") == string::npos || emailAddress.find(" ") != string::npos || emailAddress.find(".") == string::npos)
        {
            cout << "The email for " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << "is invalid." << endl;
            cout << "Invalid Email: " << classRosterArray[i]->getEmailAddress() << endl;
        }
        //Nothing for valid emails :)
    }
}

void Roster::printByDegreeProgram(DegreeProgram d)
{
    cout << "Printing students in Degree Program " << degreeProgramStrings[d] << endl;

    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getDegreeProgram() == d) this->classRosterArray[i]->print();
    }
}

//Destroys all Students
Roster::~Roster()
{
    for (int i = 0; i < numStudents; i++)
    {
        delete this->classRosterArray[i];
    }
    delete this;
}
