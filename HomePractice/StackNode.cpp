#include"StackNode.h"
using namespace std;

template<typename T>
Stack<T>::Stack()
{
	top = nullptr;
	size = 0;
}

template<typename T>
Stack<T>::~Stack()
{
	if (top) {
		StackNode<T>* curr = top;
		while (curr)
		{
			StackNode<T>* next = curr->next;
			delete curr;
			curr = next;
		}

	}
}
template<typename T>
void Stack<T>::pop()
{
	if (top) {
		auto toDel = top;
		top = top->next;
		delete toDel;
		size--;
	}
}
template<typename T>
T Stack<T>::getTopData()
{
	if (top)
	{
		return top->content;
	}
}
template<typename T>
void Stack<T>::push(T info)
{
	StackNode<T>* latest = new StackNode<T>(info, top);
	top = latest;
	++size;
}

template<typename T>
int Stack<T>::getSize()
{
	return size;
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return top==nullptr;
}
