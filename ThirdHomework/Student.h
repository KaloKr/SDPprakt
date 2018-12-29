#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student{
private:
	int FN;
	std::string firstName;
	std::string lastName;
	int grade;

public:

	friend std::ostream& operator<<(std::ostream& os, const Student& st);

	Student(int, std::string, std::string, int);
	Student();
	~Student();

};

#endif
