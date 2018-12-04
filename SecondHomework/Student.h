#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student{
private:
	string FN;
	string firstName;
	string lastName;
	string grade;

public:

	friend ostream& operator<<(ostream& os, const Student& st);

	Student(string, string, string, string);
	Student();
	~Student();

};

#endif
