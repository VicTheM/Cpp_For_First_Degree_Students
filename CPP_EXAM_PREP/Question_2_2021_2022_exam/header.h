#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <string>

using namespace std;

// STRUCTURE DEFINITIONS
struct Student
{
	char Name[50];
	int scores[4];
	float AvgScore;
};


// FUNCTION PROTOTYPES
void ReadStudentInfo(fstream &, Student &);
void WriteAvgScore(fstream &, Student &);

#endif // _HEADER_H_