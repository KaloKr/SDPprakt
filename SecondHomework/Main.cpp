#include"Student.h"
#include<iostream>
#include<fstream>
#include<string>

#include<vector>
#include<sstream>
#include<iterator>

using namespace std;

//-------------------------------------------------------------------
void update()
{
	string tofind, newGrade, line;
	cin >> tofind>>newGrade;

	bool flag = false;

	ifstream myfile;
	ofstream temp;

	myfile.open("StudentGrade.db", ios::in);
	temp.open("temp.db");

	while (getline(myfile, line))
	{
		string currFN = line.substr(0, line.find(" "));
		if (currFN != tofind)
		{
			temp << line << endl;
		}
		else
		{
			string str = line;
			istringstream buf(str);
			istream_iterator<string> beg(buf), end;
			vector<string> tokens(beg, end);

			Student updated(tokens[0], tokens[1], tokens[2], newGrade);
			temp << updated;
			flag = true;
		}
	}
	myfile.close();
	temp.close();
	remove("StudentGrade.db");
	rename("temp.db", "StudentGrade.db");
	if (!flag)
	{
		cout << "Record not found!" << endl;
	}
	else
	{
		cout << "Record saved!" << endl;
	}

}
//-------------------------------------------------------------------
void deleteStudent()
{
	string todel, line;
	cin >> todel;

	bool flag = false;

	ifstream myfile;
	ofstream temp;

	myfile.open("StudentGrade.db", ios::in);
	temp.open("temp.db");

	while (getline(myfile, line))
	{
		string currFN = line.substr(0, line.find(" "));
		if (currFN != todel)
		{
			temp << line << endl;
		}
		else
		{
			flag = true;
		}
	}
	myfile.close();
	temp.close();
	remove("StudentGrade.db");
	rename("temp.db", "StudentGrade.db");
	if (!flag)
	{
		cout << "Record not found!" << endl;
	}
	else
	{
		cout << "Record deleted!" << endl;
	}
	
}
//-------------------------------------------------------------------
void sequentialSearch()
{
	string search;
	cin >> search;

	ifstream myfile;
	myfile.open("StudentGrade.db", ios::in);

	bool flag = false;

	string line;

	while (getline(myfile,line))
	{
		string currFN = line.substr(0, line.find(" "));
		//Getting just the first part of the line so it can compare it with "search"
		if (search.compare(currFN) == 0)
		{
			//Seperate the line where we found the FN into components and then making them into a Student. 
			string str = line;
			istringstream buf(str);
			istream_iterator<string> beg(buf), end;
			vector<string> tokens(beg, end);
			Student theone(tokens[0], tokens[1], tokens[2], tokens[3]);

			cout << theone;


			flag = true;
			break;

		}
	}
	if (!flag)
	{
		cout << "Record not found!" << endl;
	}
	myfile.close();

}
//----------------------------------------------------------------------


int main()
{

	char command[15];
	
	while (command[0] != 'e')
	{

		cin >> command;

		switch (command[0])
		{

		case 's': sequentialSearch(); break;

		case 'u': update(); break;

		case 'd': deleteStudent(); break;

		}
	}
	
	system("pause");
	
	return 0;
}
