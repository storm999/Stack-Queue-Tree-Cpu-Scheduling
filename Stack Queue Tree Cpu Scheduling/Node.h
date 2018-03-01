#pragma once
class Node
{
private:
	// points to the next node of itself
	Node* next;
	// points to the previous node of itself
	Node* prev;

	//priority of the processes waiting in cpu queue to be processed
	int priority;
	// integer value that represents process ID
	int value;

public:
	Node();
	Node(int value, Node* nextptr = nullptr, Node* prevptr = nullptr, int currentpriority = 0);

	int getVal(void);
	void setVal(int value);

	int getPriority(void);
	void setPriority(int priority);

	Node* getNext(void);
	void setNext(Node* nextptr);

	Node* getPrev(void);
	void setPrev(Node* prevptr);
};
