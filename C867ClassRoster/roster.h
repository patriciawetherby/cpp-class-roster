#pragma once
#include <string>
#include <iostream>
#include "student.h"

//5 Students in the current table
const int numStudents = 5;

const string studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,30,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Patricia,Wetherby,pcampo2@wgu.edu,22,40,30,20,SOFTWARE"

    //NOTE A1 has a space, A2 is missing a dot, and A3 is missing @ symbol. Only A3 will be removed in main()
};

//Roster contains a contains studentDataTable information
class Roster {

public:

    int lastIndex; //index of last book in roster
    int capacity; //the maximum size of the roster
    Student** classRosterArray; //E1: Create an array of pointers classRosterArray (requires **)
    Roster(); //Empty constructor creates Roster and initializes all fields to default values
    Roster(int capacity); //This constructor does the same as above but sets max size
    void add(string row);
    void printAll();
    bool remove(string studentID);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram d);

    ~Roster(); //Destructor destroys the repository, releasing any resources it requested

};
