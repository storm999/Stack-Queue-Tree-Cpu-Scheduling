#include "Queue.h"


Queue::Queue()
{
}

Queue::~Queue()
{
}

Node* Queue::getFrontNode()
{
	return front;
}

void Queue::Enqueue(int priority, int processID)
{
	if (front == nullptr)										// If queue is empty
	{
		Node* newNode = new Node(processID, nullptr, nullptr, priority);
		front = newNode;
	}
	else if (front != nullptr && back == nullptr)				// If queue contains only one element
	{
		Node* newNode = new Node(processID, front, nullptr, priority);
		back = newNode;
		front->setPrev(back);
	}
	else if (front != nullptr && back != nullptr)				// If queue contains at least 2 elements
	{
		Node* newNode = new Node(processID, back, nullptr, priority);
		back->setPrev(newNode);
		back = newNode;
	}
}

int Queue::Dequeue(void)
{
	if (front == nullptr)								// If queue is empty
	{
		return NULL;
	}
	else if (front != nullptr && back == nullptr)		// If queue contains only one element
	{
		int ret = front->getVal();
		front = nullptr;
		return ret;
	}
	else if (front->getPrev()->getPrev() == nullptr)	// If queue contains 2 elements
	{
		int ret = front->getVal();
		front->getPrev()->setNext(nullptr);
		front = front->getPrev();
		back = nullptr;
		return ret;
	}
	else												// If queue contains at least 3 elements
	{
		int ret = front->getVal();
		front->getPrev()->getPrev()->setNext(front->getPrev());
		front->getPrev()->setNext(nullptr);
		front = front->getPrev();
		return ret;
	}
}

void Queue::printQueue(void)			// Prints the queue to the screen
{
	Node* currentNode = front;
	int index = 1;
	if (currentNode == nullptr)
		cout << "Queue is empty" << endl;
	else
	{
		while (currentNode != nullptr)
		{
			cout << "Queue index " << index << ":  " << "Priority:" << currentNode->getPriority() << "     Process ID " << currentNode->getVal() << endl;
			currentNode = currentNode->getPrev();
			index++;
		}
	}
}

void Queue::printQueue(Node creationOrder[])			// Prints the queue to the screen
{
	cout << "Queue Index:  Queue Elements        |  Creation Order" << endl;
	Node* currentNode = front;
	int index = 0;
	if (currentNode == nullptr)
		cout << "Queue is empty" << endl;
	else
	{
		while (currentNode != nullptr)
		{
			cout << "Q_index " << setw(3) << index + 1 << ":  " << "ID:  " << setw(4) << currentNode->getVal() << "  Pri:  " << setw(3) << currentNode->getPriority()
				<< "  |  " << setw(3) << "Pri: " << setw(3) << creationOrder[index].getPriority() << "  ID: " << setw(4) << creationOrder[index].getVal() << endl;
			currentNode = currentNode->getPrev();
			index++;
		}
	}
}
