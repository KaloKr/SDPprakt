#include "QueueNode.h"

template<typename T>
Queue<T>::Queue() 
{
	last = nullptr;
	first = last;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& que)
{
	first = que.first;

}

template<typename T>
Queue<T>::~Queue()
{
	QueueNode<T>* temp = first;
	while (temp!= last)
	{
		QueueNode<T>* next = temp->next;
		delete temp;
		temp = next;
		
	}
	delete last;
}

template<typename T>
void Queue<T>::pop()
{
	if (first)
	{
		QueueNode<T>* temp = first;
		first = first->next;
		delete temp;
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
	if (!last)
	{
		head = new QueueNode<T>*(content);
		last = head;
	}
	else
	{
		last->next = new QueueNode<T>*(content);
		last = last->next;
	}
	
}
