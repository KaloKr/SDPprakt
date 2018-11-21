#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode() :data(T()), next(nullptr) {}
	
	ListNode(T info) :data(info), next(nullptr) {}
	ListNode(T info, ListNode<T>* fol) :data(info), next(fol) {}
	ListNode(ListNode<T>* copy) :data(copy->data), next(copy->next) {}
};

template<typename T>
class LinkedList
{
private:
	ListNode<T>* head;

public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList<T> &);

	void insertFirst(T);//OK
	void insertAt(int, T);//OK
	void insertEnd(T);//OK

	void pop();//OK
	void removeAt(int);//OK
	void removeEnd();

	ListNode<T>* getHead();//OK
	void print();//OK

};

#endif // ! LINKEDLIST_H

