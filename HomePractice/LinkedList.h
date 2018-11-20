#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
struct ListNode
{
	T data;
	ListNode* next;
	ListNode() :data(T()), next(nullptr) {}
	
	~ListNode()
	{
		delete next;
	}
	ListNode(T info) :data(info), next(nullptr) {}
	ListNode(T info, ListNode<T>* fol) :data(info), next(fol) {}
	ListNode(ListNode<T>* copy) :data(copy->data), next(copy->next) {}
};

template<typename T>
class LinkedList
{
private:
	ListNode* head;

public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList &);

	void insertFirst(T);
	void insertAt(int, T);
	void insertEnd(T);

	void pop();
	void removeAt(int);
	void removeEnd();

	ListNode<T>* getHead();

};

#endif // ! LINKEDLIST_H

