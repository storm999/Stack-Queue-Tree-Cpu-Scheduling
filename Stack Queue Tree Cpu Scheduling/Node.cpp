#include "Node.h"

Node::Node()
{
}

Node::Node(int newValue, Node* nextptr, Node* prevptr, int currentpriority)
{
	next = nullptr;
	prev = nullptr;
	priority = currentpriority;
	value = newValue;
}

int Node::getVal(void)
{
	return value;
}

void Node::setVal(int newValue)
{
	value = newValue;
}

int Node::getPriority(void)
{
	return priority;
}

void Node::setPriority(int newPriority)
{
	priority = newPriority;
}

Node* Node::getNext(void)
{
	return next;
}

void Node::setNext(Node* nextptr)
{
	next = nextptr;
}

Node* Node::getPrev(void)
{
	return prev;
}

void Node::setPrev(Node* prevptr)
{
	prev = prevptr;
}