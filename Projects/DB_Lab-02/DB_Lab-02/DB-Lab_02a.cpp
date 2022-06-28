// used template given in word document sans a few lines and comments
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

struct Student
{
	string name;
	string important[2]; // test scores stored as strings so conversion does not have to take place
	string tests[4];
	float grade;
};

// takes a student, calculates grades using data in struct
float calculateGrade(Student s);

// takes a float and converts it to a letter grade using a basic if else ladder
char numberToLetter(float grade);

int main()
{
	// declare all variables
	Student newStudent;
	Student students[24];
	char numStudents = 0;
	ifstream inFile;
	string temp;

	// opens the file and checks if said file could be opened, quits if not
	inFile.open("students.txt");
	if (!inFile.is_open()) {
		cout << "File could not be opened!" << endl;
		return -1;
	}

	// begins to read and input data
	while (getline(inFile, newStudent.name))
	{
		getline(inFile, temp);
		istringstream weird(temp); // using istringstreams to interpret lines. If operator>> were used to read data, getline would not change lines.
		weird >> newStudent.important[0] >> newStudent.important[1];
		getline(inFile, temp);
		weird.clear(); // clears the stream before adding the next set of data
		weird.str(temp);
		weird >> newStudent.tests[0] >> newStudent.tests[1] >> newStudent.tests[2] >> newStudent.tests[3];
		newStudent.grade = calculateGrade(newStudent); // calculates the student's data and enters it
		students[numStudents++] = newStudent; // adds a copy of the student into the storage array and iterates numStudents
	}
	// closes file since it will no longer be used
	inFile.close();

		// iterates over all students to display their name and grades
		for (int i = 0; i < numStudents; i++)
		{
			printf("%s's final grade is %g%% (grade: %c)\n", students[i].name.c_str(), students[i].grade, numberToLetter(students[i].grade));
		}
	return 0;
}

float calculateGrade(Student s)
{
	// calculate and return student’s final numeric score, write your code here
	float finalgrade = 0;
	finalgrade += stof(s.important[0]) * 0.25 + stof(s.important[1]) * 0.25; // inefficient but works well, should not run into many rounding errors with this data
	for (string s : s.tests)
		finalgrade += stof(s) * 0.5 * 0.25;
	return finalgrade;
}

char numberToLetter(float grade) 
{
	if (grade >= 90)
		return 'A';
	else if (grade >= 80)
		return 'B';
	else if (grade >= 70)
		return 'C';
	else if (grade >= 60)
		return 'D';
	else
		return 'F';
}
