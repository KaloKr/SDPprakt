#pragma once
#ifndef STACKNODE_H
#define STACKNODE_H

template<typename T>
struct StackNode
{
	T content;
	StackNode<T>* next;

	StackNode() :content(T()), next(nullptr) {}
	StackNode(T info) : content(info), next(nullptr) {}
	~StackNode() { delete next; }
};

template<typename T>
class Stack
{
private:
	StackNode<T>* top;
public:
	Stack();
	Stack(const Stack<T>&);
	~Stack();

	void pop();
	T getTopData();
	void push(T info);

};




#endif