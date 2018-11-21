#ifndef QUEUENODE_H
#define QUEUENODE_H
template<typename T>
struct QueueNode
{
	T data;
	QueueNode<T>* next;
	QueueNode() :data(T()),next(nullptr) {}
	QueueNode(T info) : data(info), next(nullptr) {}
	~QueueNode() { }
};

template<typename T>
class Queue
{
private:
	QueueNode<T>* first;
	QueueNode<T>* last;
public:
	Queue();
	~Queue();

	void pop();
	T getFront();
	void push_back(T content);
	bool empty();
	void print();
};




#endif