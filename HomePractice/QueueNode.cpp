#include "QueueNode.h"
#include<iostream>

using namespace std;

template<typename T>
Queue<T>::Queue() 
{
	first = nullptr;
	last = first;
}

template<typename T>
Queue<T>::~Queue()
{
	if (first!= nullptr && last!= nullptr)
	{
		QueueNode<T>* temp = first;
		while (temp != last)
		{
			QueueNode<T>* next = temp->next;
			delete temp;
			temp = next;

		}
		delete last;
	}
}

template<typename T>
void Queue<T>::pop()
{
	if (first)
	{
		if (first == last)
		{
			delete first;
			first = nullptr;
			last = nullptr;
		}
		else
		{
			QueueNode<T>* temp = first;
			first = first->next;
			delete temp;
		}
	}
	else
	{
		cout << "Already popped them all !" << endl;
	}
}

template<typename T>
T Queue<T>::getFront()
{
	return first->data;
}

template<typename T>
void Queue<T>::push_back(T content)
{
	if (!first)
	{
		first = new QueueNode<T>(content);
		last = first;
		first->next = nullptr;
		last->next = nullptr;
	}
	else
	{
		if (!first->next)
		{
			first->next = new QueueNode<T>(content);
			last = first->next;
		}
		else
		{
			last->next = new QueueNode<T>(content);
			last = last->next;
		}
	}
	
}

template<typename T>
bool Queue<T>::empty()
{
	return first == nullptr;
}

template<typename T>
void Queue<T>::print()
{
	if (!first)
	{
		cout << "Empty queue!" << endl;
	}
	else
	{
		QueueNode<T>* crr = first;
		while (crr != last)
		{
			cout << crr->data << " ";
			crr = crr->next;
		}
		cout << crr->data << " ";
	}
}

