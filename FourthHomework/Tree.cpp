#ifndef TREE_CPP
#define TREE_CPP

#include"Tree.h"
#include"Student.h"
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void Tree::insertHelper(Node* root, Student latest)
{
	if (root->student.getFN() == latest.getFN())
	{
		root->student = latest;
	}
	else
	{
		if (root->student.getFN() > latest.getFN())
		{
			if (!root->left)
			{
				root->left = new Node(latest);
			}
			else
			{
				insertHelper(root->left, latest);
			}
		}
		else
		{
			if (!root->right)
			{
				root->right = new Node(latest);
			}
			else
			{
				insertHelper(root->right, latest);
			}
		}
	}
}

void Tree::insert(Student arrived)
{
	if (root)
	{
		insertHelper(root, arrived);
	}
	else
	{
		root = new Node(arrived);
	}
	
	cout << "Record inserted!" << endl;
}

void Tree::deleteSave(int curr)
{
	if (existing(root, curr))
	{
		root = deleteHelp(root, curr);
		cout << "Record deleted!" << endl;
	}
	else
	{
		cout << "Record not found!" << endl;
	}
}

Node* Tree::deleteHelp(Node* root, int chosen)
{
	if (!root)
	{
		return root;
	}
	
	if (chosen < root->student.getFN())
	{
		root->left = deleteHelp(root->left, chosen);
	}
	else
	{
		if (root->student.getFN() < chosen)
		{
			root->right = deleteHelp(root->right, chosen);
		}
		//the case where we actually delete smth
		else
		{
			//case1:
			if (!root->left && !root->right)
			{
				delete root;
				root = nullptr;
			}
			//case2:
			else
			{
				//case 2.1
				if (!root->left)
				{
					Node* temp = root;
					root = root->right;
					delete temp;
						
				}
				else
				{
					//case2.2
					if (!root->right)
					{
						Node* temp = root;
						root = root->left;
						delete temp;

					}
					//case 3
					else
					{
						Node* temp = findMin(root->right);
						root->student = temp->student;
						root->right = deleteHelp(root->right, temp->student.getFN());
					}
				}
			}	
		}
	}
	
	return root;
}

//Function to find min member of certain tree.
Node* findMin(Node* root)
{
	if (!root)
	{
		return nullptr;
	}
	Node* temp = root;
	while (temp->left)
	{
		temp = temp->left;
	}

	return temp;
}

void Tree::find(int fn)
{
	findHelp(root, fn);
}

void Tree::findHelp(Node* root, int fn)
{
	if (!root)
	{
		cout << "Record not found!" << endl;
	}
	else
	{
		if (root->student.getFN() < fn)
		{
			findHelp(root->right, fn);
		}
		else
		{
			if (root->student.getFN() > fn)
			{
				findHelp(root->left, fn);
			}
			else
			{
				cout << root->student << endl;
			}
		}
	}
}

vector<Student> Tree::traversalHelp(Node* root)
{
	vector<Student> r;
	if (!root) {
		return r;
	}
	stack<Node*> st;
	Node* p = root;
	while (p || !st.empty()) {
		while (p) {
			st.push(p);
			p = p->left;
		}
		p = st.top();
		st.pop();
		r.push_back(p->student);

		p = p->right;
		

	}
	return r;
}

void Tree::traverseInorder()
{
	vector<Student> state = traversalHelp(root);
	for (int i = 0; i < state.size(); i++)
	{
		if (i == state.size() - 1)
		{
			cout << state[i].getFN();
		}
		else
		{
			cout << state[i].getFN() << ',';
			//Тук имах колебания дали да е само ',' или ", ", но заради условието го оставих само ','.
		}
	}
	cout << endl;
}

Tree::Tree()
{
	root = nullptr;
}

void deleteTree(Node* root)
{
	if (root)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}

}

Tree::~Tree()
{
	deleteTree(root);
}

//Дали стойността е в дървото.
bool Tree::existing(Node* root, int val)
{
	if (!root)
	{
		return false;
	}
	if (root->student.getFN() == val)
	{
		return true;
	}
	if (root->student.getFN() > val)
	{
		return existing(root->left, val);
	}
	else
	{
		return existing(root->right, val);
	}
}

#endif // !TREE_CPP
