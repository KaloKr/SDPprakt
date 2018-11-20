#include"LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList():head(nullptr){}

template<typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* temp = head;
	while (temp)
	{
		ListNode<T>* next = temp->next;
		delete temp;
		temp = next;
	}
}
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> & list)
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
	ListNode<T>* top = new ListNode<T>(info, head);
	head = top;
}
template<typename T>
void LinkedList<T>::insertAt(int pos, T info)
{
	if (pos < 0)
	{
		cout << "Negative possitions not supported!" << endl;
		return;
	}
	ListNode<T>* iter = head;
	int counter = 0;
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
	while (temp)
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
		iter = iter->next;
	}

}
template<typename T>
void LinkedList<T>::removeEnd()
{
	ListNode<T>* temp = head;
	while (temp)
	{
		if (!temp->next)
		{
			delete temp;
		}
		temp = temp->next;
	}

}
template<typename T>
ListNode<T>* LinkedList<T>::getHead() 
{
	return head;
}