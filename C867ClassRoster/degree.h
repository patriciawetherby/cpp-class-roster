#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

//C1 Define an enumerated data type DegreeProgram for the degree programs
//containing the data type values SECURITY, NETWORK, AND SOFTWARE
// the 3 types of Degrees
enum DegreeProgram { UNDECIDED, SECURITY, NETWORK, SOFTWARE }; //Adding undecided at index 0 to match with video

// allows program type to be converted to string for output
static const string degreeProgramStrings[] = { "UNDECIDED", "SECURITY", "NETWORK", "SOFTWARE" };
