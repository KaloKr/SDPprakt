#include"LinkedList.h"
#include<iostream>

using namespace std;

template<typename T>
LinkedList<T>::LinkedList():head(nullptr){}

template<typename T>
LinkedList<T>::~LinkedList()
{
	
	ListNode<T>* temp = head;
	while (head)
	{
		head = head->next;
		delete temp;
		temp = head;
	
	}
}
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & list):head(nullptr)
{
	if (!list.head)
	{
		head = nullptr;
	}
	else {
		head = new LinkedList(list.head->data);
		ListNode<T>* curr = head;
		ListNode<T>* listHead = list.head;
		ListNode<T>* currHead = listHead;

		while (currHead->next)
		{
			curr->next = new ListNode<T>(currHead->next->data);
			currHead = currHead->next;
			curr = curr->next;
		}
	}
}
template<typename T>
void LinkedList<T>::insertFirst(T info)
{
	ListNode<T>* temp = new ListNode<T>(info);
	temp->next = head;
	head = temp;
}
template<typename T>
void LinkedList<T>::insertAt(int pos, T info)
{
	if (pos < 0)
	{
		cout << "Negative possitions not supported!" << endl;
		return;
	}
	if (pos == 0)
	{
		insertFirst(info);
	}
	ListNode<T>* iter = head;
	int counter = 1;
	while (iter)
	{

		if (counter == pos)
		{
			ListNode<T>* following = iter->next;
			iter->next = new ListNode<T>(info, following);
			return;
		}

		++counter;

		iter = iter->next;
	}

}
template<typename T>
void LinkedList<T>::insertEnd(T info)
{
	ListNode<T>* temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new ListNode<T>(info);
}
template<typename T>
void LinkedList<T>::pop()
{
	if (head)
	{
		ListNode<T>* temp = head;
		head = head->next;
		delete temp;
	}
}
template<typename T>
void LinkedList<T>::removeAt(int pos)
{
	if (pos < 0)
	{
		cout << "Negative possitions not supported!" << endl;
		return;
	}
	if (pos == 0)
	{
		pop();
	}
	else
	{
		ListNode<T>* prev = head;
		ListNode<T>* iter = prev->next;

		int counter = 1;
		while (iter)
		{
			if (counter == pos)
			{
				ListNode<T>* temp = iter;
				iter = iter->next;
				prev->next = iter;
				delete temp;
				return;
			}
			prev = iter;
			iter = iter->next;
			counter++;
		}
	}
}
template<typename T>
void LinkedList<T>::removeEnd()
{

	if (!head)
	{
		return;
	}
	if (!head->next)
	{
		delete head;
		head = nullptr;
		return;
	}
	
	ListNode<T>* temp = head;

	while (temp->next && temp->next->next)
	{
		temp = temp->next;
	}
	
	delete temp->next;
	temp->next = nullptr;
}
template<typename T>
ListNode<T>* LinkedList<T>::getHead() 
{
	return head;
}

template<typename T>
void LinkedList<T>::print()
{
	ListNode<T>* crr = head;
	while (crr)
	{
		cout << crr->data << " ";
		crr = crr->next;
	}
}