#ifndef STUDENT_CPP
#define STUDENT_CPP

#include"Student.h"

using namespace std;

Student::Student()
{
	FirstName = "No";
	LastName = "Named";
	FN = 0;
}

void Student::setFN(int newfn)
{
	FN = newfn;
}
void Student::setFirstName(string newFirst)
{
	FirstName = newFirst;
}
void Student::setLastName(string newLast)
{
	LastName = newLast;
}

Student::Student(int currFN, string currFirst, string currLast):
	FN(currFN),FirstName(currFirst),LastName(currLast){}

Student::~Student() {}

Student Student::operator= (const Student& other)
{
	if (this != &other)
	{
		FN = other.FN;
		FirstName = other.FirstName;
		LastName = other.LastName;
	}

	return *this;
}

ostream& operator<<(ostream & os, const Student & st)
{
	os << st.FN << " " << st.FirstName << " " << st.LastName;
	return os;
}

istream& operator>>(istream& is, Student& st)
{
	int newFn;
	string newLast, newFirst;
	is >> newFn>>  newFirst >> newLast;
	st.setFN(newFn);
	st.setFirstName(newFirst);
	st.setLastName(newLast);
	
	return is;
}

int Student::getFN()
{
	return FN;
}
#endif