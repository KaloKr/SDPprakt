#ifndef STACKNODE_H
#define STACKNODE_H

template<typename T>
struct StackNode
{
	T content;
	StackNode<T>* next;

	StackNode() :content(T()), next(nullptr) {}
	StackNode(T info) : content(info), next(nullptr) {}
	StackNode(T info, StackNode<T>* newtop) : content(info), next(newtop) {}
	~StackNode() {}

};

template<typename T>
class Stack
{
private:
	StackNode<T>* top;
	int size;
public:
	Stack();
	~Stack();

	void pop();//OK
	T getTopData();//OK
	void push(T );//OK
	int getSize();//OK
	bool isEmpty();//OK

};




#endif