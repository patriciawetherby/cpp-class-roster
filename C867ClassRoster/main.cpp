#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

int main()
{
    //F1 Cout Course Information and Name

    cout << "Course Title: C867 Scripting and Programming Applications" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "WGU Student ID: #000768032" << endl;
    cout << "Name: Patricia Wetherby" << endl;

    //F2 Create an instance of the Roster class called classRoster

    cout << "Creating Class Roster..." << endl;

    //Making the Repository
    Roster* classRoster = new Roster(numStudents);


    //F3 Add each student to classRoster

    cout << "Adding students to the Class Roster..." << endl;
    for (int i = 0; i < numStudents; i++)
    {
        //Parses each line in Student Data Table, turns them into Student objects, and then adds to the Roster
        classRoster->add(studentData[i]);
    }

    cout << "Students added." << endl;


    //F4 Convert Pseudo Code

    cout << "Displaying all Students: " << endl;
    classRoster->printAll();

    cout << "Displaying all Invalid Emails: " << endl;
    classRoster->printInvalidEmails();

    //Loop through classRosterArray and for each element classRoster.printAverageDaysInCourse(Current object's student ID)

    classRoster->printAverageDaysInCourse("A5"); //Loops through in roster.cpp function!

    classRoster->printByDegreeProgram(SOFTWARE); //Loops through in roster.cpp function!

    //Remove A3

    cout << "Removing A3" << endl;

    if (classRoster->remove("A3"))
    {
        classRoster->printAll();
    }
    else
    {
        cout << "A student with this ID was not found." << endl;
    }

    //Reprinting classRoster to update without A3
    classRoster->printAll();

    //Second remove required

    cout << "Removing A3" << endl;

    if (classRoster->remove("A3"))
    {
        classRoster->printAll();
    }
    else
    {
        cout << "A student with this ID was not found." << endl;
    }

    cout << "Press Enter to exit..." << endl;
    system("pause"); //For Visual Studio, Press Enter to Exit

    return 0;
}



