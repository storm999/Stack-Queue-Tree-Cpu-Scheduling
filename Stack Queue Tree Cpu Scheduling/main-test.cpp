#include <iostream>
#include <time.h> 	//For generating processes randomly in test code
#include "Queue.h"
#include "Stack.h"
#include "BinarySearchTree.h"
#include "Scheduler.h"
#include "Node.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////
// TEST CODE
////////////////////////////////////////////////////////////////////////////////////////////////////////

void test_queue()
{
	cout << "Test Queue is being called:" << endl;
	cout << "---------------------------" << endl;

	Queue q1;
	q1.printQueue();

	q1.Enqueue(1, 0);
	cout << endl << "1 equeue" << endl;
	q1.printQueue();

	q1.Dequeue();
	cout << endl << "1 dequeue" << endl;
	q1.printQueue();

	q1.Enqueue(7, 0);
	q1.Enqueue(8, 0);
	cout << endl << "2 equeue" << endl;
	q1.printQueue();

	q1.Dequeue();
	q1.Dequeue();
	q1.Dequeue();
	q1.Dequeue();
	cout << endl << "4 dequeue" << endl;
	q1.printQueue();

	q1.Enqueue(4, 0);
	q1.Enqueue(5, 0);
	q1.Enqueue(6, 0);
	cout << endl << "3 equeue" << endl;
	q1.printQueue();

	q1.Dequeue();
	q1.Dequeue();
	cout << endl << "2 dequeue" << endl;
	q1.printQueue();

	q1.Enqueue(7, 0);
	cout << endl << "1 equeue" << endl;
	q1.printQueue();

	q1.Dequeue();
	q1.Dequeue();
	q1.Dequeue();
	cout << endl << "3 dequeue" << endl;
	q1.printQueue();

	q1.Enqueue(1, 0);
	q1.Enqueue(2, 0);
	q1.Enqueue(4, 0);
	q1.Enqueue(7, 0);
	cout << endl << "4 equeue" << endl;
	q1.printQueue();

	q1.Dequeue();
	q1.Dequeue();
	cout << endl << "2 dequeue" << endl;
	q1.printQueue();

	q1.Enqueue(5, 0);
	q1.Enqueue(6, 0);
	cout << endl << "2 equeue" << endl;
	q1.printQueue();

	q1.Dequeue();
	q1.Dequeue();
	q1.Dequeue();
	cout << endl << "3 dequeue" << endl;
	q1.printQueue();
	cout << endl << "==================================================" << endl;
}

void test_stack()
{
	cout << "Test Stack is being called:" << endl;
	cout << "---------------------------" << endl;
	Stack s1;
	s1.Pop();
	s1.printStack();

	cout << endl << "1 push" << endl;
	s1.Push(1);
	s1.printStack();

	cout << endl << "1 pop" << endl;
	s1.Pop();
	s1.printStack();


	cout << endl << "2 push" << endl;
	s1.Push(2);
	s1.Push(3);
	s1.printStack();

	cout << endl << "3 pop" << endl;
	s1.Pop();
	s1.Pop();
	s1.Pop();
	s1.printStack();

	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	cout << endl << "3 push" << endl;
	s1.printStack();

	s1.Pop();
	cout << endl << "1 pop" << endl;

	s1.printStack();
	s1.Push(4);
	cout << endl << "1 push" << endl;
	s1.printStack();

	s1.Pop();
	s1.Pop();
	cout << endl << "2 pop" << endl;
	s1.printStack();

	s1.Push(5);
	s1.Push(6);
	cout << endl << "2 push" << endl;
	s1.printStack();

	s1.Pop();
	cout << endl << "1 pop" << endl;
	s1.printStack();
	cout << endl << "==================================================" << endl;
}

void test_tree()
{
	cout << "Test Tree is being called:" << endl;
	cout << "--------------------------" << endl;
	BinarySearchTree t1;

	t1.insert(10, 2);
	t1.insert(15, 7);
	t1.insert(18, 2);
	t1.insert(13, 6);
	t1.insert(19, 9);
	t1.insert(17, 8);
	t1.insert(14, 6);
	t1.insert(12, 3);
	t1.insert(5, 4);
	t1.insert(7, 1);
	t1.insert(8, 3);
	t1.insert(6, 4);
	t1.insert(3, 1);
	t1.insert(4, 4);
	t1.insert(2, 1);

	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "------------------------------------------------" << endl;

	t1.deleteMax();
	cout << endl << endl << endl;
	t1.printTree(t1.getRoot());
	cout << endl << "==================================================" << endl;
}

Node randomNodeProducer()	//Process Producer
{
	int processID = rand() % 9999 + 1;
	int priority = rand() % 30 + 1;
	return Node(processID, nullptr, nullptr, priority);
}

void test_scheduler()
{
	cout << "Test Schedular is being called:" << endl;
	cout << "-------------------------------" << endl;
	srand(time(NULL));
	Scheduler sc1;
	Node n19 = Node(999, nullptr, nullptr, 30);
	sc1.Schedule(n19); // since its first process it will be enqueued first.
	Node creationOrder[33];
	creationOrder[0] = n19;

	for (int i = 1; i < 33; i++)
	{
		Node temp = randomNodeProducer();
		sc1.Schedule(temp);
		creationOrder[i] = temp;
	}

	sc1.getQueue()->printQueue(creationOrder);
}

int main()
{
	test_queue();

	test_stack();

	test_tree();

	test_scheduler();

	cout << endl << "end";
	getchar();
	return 0;
}