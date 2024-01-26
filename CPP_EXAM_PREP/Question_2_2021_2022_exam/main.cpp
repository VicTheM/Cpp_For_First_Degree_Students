#include "header.h"

int main(void)
{
	const int size = 3;
	Student students[size];

	fstream inputFile("StudentInfo.txt", ios::in);
	fstream outputFile("AvgScoreFile.txt", ios::out | ios::app);

	if(!inputFile.is_open() || !outputFile.is_open())
		cerr <<"Error occured while opening/creating files.\n";

	for (int c = 0; c < size; c++)
	{
		ReadStudentInfo(inputFile, students[c]);
		WriteAvgScore(outputFile, students[c]);
	}
	system("pause");

	inputFile.close();
	outputFile.close();
	return (0);
}