#ifndef TREE_H
#define TREE_H
#include"Student.h"
#include<vector>
struct Node
{
	Student student;
	Node* left;
	Node* right;

	Node(Student val)
	{
		this->student = val;
		left = nullptr;
		right = nullptr;
	}

	Node(Student stud, Node* leftt, Node* rightt)
	{
		student = stud;
		left = leftt;
		right = rightt;
	}
	
};

Node* findMin(Node*);

class Tree
{
private:
	Node* root;
	void insertHelper(Node* , Student );
	Node* deleteHelp(Node*, int);
	void findHelp(Node*, int);
	void traverseHelp(Node*);
	bool existing(Node*, int);
	std::vector<Student> traversalHelp(Node*);
public:
	void insert(Student);
	void deleteSave(int);
	void find(int);
	void traverseInorder();
	Tree();
	~Tree();
	
};



#endif