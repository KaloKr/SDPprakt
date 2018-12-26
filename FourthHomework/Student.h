#ifndef STUDENT_H
#define STUDENT_H

#include<string>

class Student
{
private:
	int FN;
	std::string FirstName;
	std::string LastName;

public:
	void setFN(int);
	void setFirstName(std::string);
	void setLastName(std::string);
	Student();
	Student(int, std::string, std::string);
	~Student();
	Student operator = (const Student&);
	int getFN();
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
};

#endif
