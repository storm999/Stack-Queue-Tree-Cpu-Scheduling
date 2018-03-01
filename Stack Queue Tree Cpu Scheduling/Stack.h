#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class Stack
{
private:
	// the node on the top of the stack
	Node* top;

public:
	Stack(void);
	~Stack(void);

	//Creates a new node, writes the given value to the node, and pushes node to the stack
	void Push(int value);

	//Returns int value that is held on top node, deletes the top node of stack, makes the previous node of top new top.
	int Pop(void);
	//Returns top node, deletes the top node of stack, makes the previous node of top new top.
	Node* NodePop(void);

	//Prints elements of stack, mainly for testing aim
	void Stack::printStack();

};
