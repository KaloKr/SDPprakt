﻿#include <string>
#include"Student.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

Student::Student() {}
Student::~Student() {}
Student::Student(int newfn, string newfirstn, string newlastn, int newgr):
	FN(newfn),firstName(newfirstn),lastName(newlastn),grade(newgr) {}


ostream & operator<<(ostream & os, const Student & st)
{
	os << st.FN <<" "<< st.firstName << " " << st.lastName << " " << st.grade << endl;
	return os;
}



