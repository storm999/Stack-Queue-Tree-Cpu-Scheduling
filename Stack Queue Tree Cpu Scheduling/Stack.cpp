#include "Stack.h"


Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::Push(int value)
{
	if (top == nullptr)				// If stack is empty
	{
		top = new Node(value, nullptr, nullptr, 0);
	}
	else if (top != nullptr)		//If stack contains at least one element
	{
		Node* newNode = new Node(value, nullptr, top, 0);	//creation of new node to be pushed on the top of stack
		top->setNext(newNode);
		newNode->setPrev(top);
		top = newNode;
	}
}

Node* Stack::NodePop(void)
{
	if (top == nullptr)						// If stack is empty
	{
		return NULL;
	}
	else if (top->getPrev() == nullptr)		//If stack contains 1 element
	{
		Node* ret = top;
		top = nullptr;
		return ret;
	}
	else									//If stack contains at least 2 elements
	{
		Node* ret = top;
		top->getPrev()->setNext(nullptr);
		top = top->getPrev();
		return ret;
	}
}

int Stack::Pop(void)
{
	if (top == nullptr)						// If stack is empty
	{
		return NULL;
	}
	else if (top->getPrev() == nullptr)		//If stack contains 1 element
	{
		int ret = top->getVal();
		top = nullptr;
		return ret;
	}
	else									//If stack contains at least 2 elements
	{
		int ret = top->getVal();
		top->getPrev()->setNext(nullptr);
		top = top->getPrev();
		return ret;
	}
}

void Stack::printStack()					// Prints the stack to the screen
{
	Node* currentNode = top;
	int index = 1;

	if (currentNode == nullptr)				//If stack is empty
		cout << "Stack is empty" << endl;
	else									//If stack is not empty
	{
		while (currentNode != nullptr)		//iterates all stack elements by doing nullptr check
		{
			cout << "index " << index << ":  " << "value " << currentNode->getVal() << endl;
			currentNode = currentNode->getPrev();
			index++;
		}
	}
}