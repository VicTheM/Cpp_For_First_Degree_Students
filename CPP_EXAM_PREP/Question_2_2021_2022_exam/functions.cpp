#include "header.h"

void ReadStudentInfo(fstream &inFileObject, Student &student)
{
	string fullName, tmp;

	student.AvgScore = 0;
	if (inFileObject.is_open())
	{
		inFileObject >> fullName; // Get first name;
		inFileObject >> tmp; // Second name;
		fullName.append(" " + tmp);

		for (int i = 0; i < 4; i++){
			inFileObject >> student.scores[i];
			student.AvgScore += student.scores[i];
		}
		student.AvgScore /= 4;
	}
	else
	{
		cerr <<"Unable to read file";
	}
	strcpy(student.Name, fullName.c_str());
}

void WriteAvgScore(fstream &ofObject, Student &student)
{
	if (ofObject.is_open())
	{
		ofObject << left << setw(30) << student.Name;
		ofObject << setprecision(4) << student.AvgScore << "\n" << endl;
	}
}