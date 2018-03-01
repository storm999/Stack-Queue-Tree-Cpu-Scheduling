#pragma once
#include <iostream>
#include <iomanip>	//For formatted output, setw() function is used in printQueue(Node creationOrder[]) function, just called in test code
#include "Node.h"

using namespace std;

class Queue
{

public:
	Queue(void);
	~Queue(void);

	//Creates a new node, assignes given value and priority to the new node and adds new node to the back of the queue
	void Enqueue(int priority, int processID);
	//Returns the value of the node in the front of the queue and delete that node from the queue
	int Dequeue(void);

	//Prints elements of queue, mainly for testing aim
	void printQueue(void);
	void Queue::printQueue(Node creationOrder[]);

	//Returns the element inserted to queue firstly. 
	//Similar to Denqueue function but it doesnt delete and it returns the node, not the value held in node
	Node* getFrontNode();

protected:

	// the node at the back of the queue
	Node* back;
	// the node in the front of the queue
	Node* front;

private:

	//Returns the node in the front of the queue and delete that node from the queue
	virtual Node* NodeDequeue(void)
	{
		return nullptr;
	}
};