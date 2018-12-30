#include"Student.h"
#include<iostream>
#include<fstream>
#include<string>

#include<vector>
#include<sstream>
#include<iterator>

#include"Index.h"
using namespace std;

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
			Student theone(stoi(tokens[0]), tokens[1], tokens[2],stoi(tokens[3]));

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
//Mergesort implementatin for a vector of Indexes
void mergeSort(vector<Index>&left, vector<Index>& right, vector<Index>& bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j].FNum < right[k].FNum) {
			bars[i] = left[j];
			j++;
		}
		else {
			bars[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		bars[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		bars[i] = right[k];
		k++; i++;
	}
}

void sort(vector<Index> & bar) {
	if (bar.size() <= 1) return;

	int mid = bar.size() / 2;
	vector<Index> left;
	vector<Index> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	sort(left);
	sort(right);
	mergeSort(left, right, bar);
}

//arr where we store the Indexes
vector<Index> arr;

void builtIndex()
{
	if (!arr.empty())
	{
		arr.clear();
	}

	string line1;

	ifstream reading;
	reading.open("StudentGrade.db", ios::in);
	int curr;

	int number_of_lines = 0;

	//This loop goes through the file StudentGrade and saves Index where for every FN is the offset from the begining of the file.
	while (reading)
	{

		curr = reading.tellg();

		getline(reading, line1);

		string currFN = line1.substr(0, line1.find(" "));

		Index latest(stoi(currFN), curr);
		//This if is so we don't have saves that don't exist in the file.
		if (curr != -1)
		{
			arr.push_back(latest);
			number_of_lines++;
		}

		reading >> ws;
		//this reads any whitespace (currently the newline) so the get pointer goes to the begining of the next line.

	}

	reading.close();

	//The next line does a mergesort for the array of Indexes.
	sort(arr);

	ofstream writing;

	writing.open("FacultyNumber.ids", ios::trunc);
	writing << number_of_lines << endl;
	//A loop to write all the data to the file "FacultyNumber.ids".
	for (int i = 0; i < arr.size(); i++)
	{
		writing << arr[i].FNum << " " << arr[i].offset << endl;
	}
	writing.close();
}


void buildIndex()
{
	builtIndex();

	cout << "Index is built!" << endl;
	
}

Index BinarySearch(vector<Index> vec,int left, int right, int searched)
{
	Index error(0, -1);
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid].FNum == searched)
		{
			return arr[mid];
		}
		if (arr[mid].FNum > searched)
		{
			return BinarySearch(arr, left, mid - 1, searched);
		}
		else
		{
			return BinarySearch(arr, mid + 1, right, searched);
		}
	}
	else
	{
		return error;
	}
}

void searching(int value)
{

	Index res = BinarySearch(arr, 0, arr.size() - 1, value);
	if (res.offset == -1)
	{
		cout << "Record not found!" << endl;
		
	}
	else
	{
		ifstream getfrom;
		getfrom.open("StudentGrade.db");
		getfrom.seekg(res.offset, ios::beg);

		string line;
		getline(getfrom, line);

		string str = line;
		istringstream buf(str);
		istream_iterator<string> beg(buf), end;
		vector<string> tokens(beg, end);
		Student theone(stoi(tokens[0]), tokens[1], tokens[2], stoi(tokens[3]));

		cout << theone;

		getfrom.close();

	}
}


void search()
{
	int latestfn;
	cin >> latestfn;
	
	if (!arr.empty())
	{		
		searching(latestfn);
	}
	//This case is to build the Index if it doesn't exist.(Current definition of nonexistant index is if the arr is empty.)
	else
	{
		builtIndex();
		searching(latestfn);
	}
	
}
//-----------------------------------------------------------------------

int main()
{

	char command[15];
	
	while (command[0] != 'e')
	{

		cin >> command;

		switch (command[3])
		{

		case 'u': sequentialSearch(); break;

		case 'r': search(); break;

		case 'l': buildIndex(); break;

		}
	}
	
	return 0;
}
