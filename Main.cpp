#include"Student.h"
#include<iostream>
#include<fstream>
#include<string>

#include<vector>
#include<sstream>
#include<iterator>

using namespace std;
//------------------------------------------------------------------

void create()
{	
	string temp1, temp2, temp3, temp4;

	cin >> temp1 >> temp2 >> temp3 >> temp4;

	Student mytry(temp1, temp2, temp3, temp4);
	
	ofstream myfile;
	myfile.open("StudentGrade.db", ios::app);

	myfile << mytry;
	myfile.close();
	
	cout << "Record saved!" << endl;
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
		case 'c': create();  break;

		case 's': sequentialSearch(); break;

		}
	}
	
	return 0;
}
