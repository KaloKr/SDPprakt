#include"StackNode.h"

template<typename T>
Stack<T>::Stack()
{
	top = new StackNode<T>(T());
}
template<typename T>
Stack<T>::Stack(const Stack<T>& sta)
{

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
	}
}
template<typename T>
T Stack<T>::getTopData()
{
	return top->content;
}
template<typename T>
void Stack<T>::push(T info)
{
	StackNode<T>* latest = new StackNode<T>(info, top);
	top = latest;
}

