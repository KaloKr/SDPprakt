#include<iostream>
#include"LinkedList.h"
#include"StackNode.h"
#include"QueueNode.h"
#include "LinkedList.cpp"
#include "StackNode.cpp"
#include "QueueNode.cpp"

using namespace std;


void testForLinkedList()
{
	LinkedList<int> mylist;

	mylist.insertFirst(4);
	mylist.insertFirst(5);
	mylist.insertFirst(1);
	mylist.insertFirst(3);
	mylist.insertFirst(11);
	mylist.insertFirst(17);
	mylist.insertFirst(41);
	mylist.insertFirst(24);

	mylist.insertAt(0,333);

	mylist.insertEnd(76);
	mylist.removeEnd();
	mylist.removeEnd();

	mylist.print();
	cout << endl;
}


void testForStack()
{
	Stack<int> mystack;

	cout << mystack.isEmpty() << endl;

	mystack.push(3);
	mystack.push(5);
	mystack.push(8);
	mystack.push(11);
	mystack.push(33);
	mystack.push(47);
	mystack.push(100);

	cout << "Current Size of Stack: " << mystack.getSize() << endl;
	cout << "Top data: " << mystack.getTopData() << endl;

	cout << mystack.isEmpty() << endl;
	cout << "Popping: " << endl;
	mystack.pop();
	mystack.pop();
	mystack.pop();
	mystack.pop();
	mystack.pop();
	mystack.pop();
	mystack.pop();


	cout << mystack.isEmpty() << endl;
}

void testForQueue()
{
	Queue<int> myqueue;
	myqueue.push_back(3);
	myqueue.push_back(7);
	myqueue.push_back(-3);
	myqueue.push_back(11);
	myqueue.push_back(24);
	myqueue.push_back(79);

	myqueue.print();
	cout << endl;
	cout << "Is empty? : " << myqueue.empty() << endl;

	myqueue.pop();
	myqueue.print();

	myqueue.pop();
	myqueue.pop();
	myqueue.pop();
	myqueue.pop();
	myqueue.pop();

	myqueue.print();

}

int main()
{
	testForQueue();


	system("pause");
	return 0;
}
