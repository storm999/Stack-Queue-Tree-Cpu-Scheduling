#pragma once
#include "Node.h"
#include "Queue.h"
#include "BinarySearchTree.h"

class Scheduler : public Queue
{
private:
	//Main cpu queue that processes are held right before being processed
	Queue* cpuQueue = new Queue();

	//A BinarySearchTree that processes are held temporarily right before they are sent to queue. 
	//Binary Search Tree is selected because all of insertion, deletion, search operations are done within logN complexity time in average.
	//Therefore we can push our processes according to their priorities to BinarySearchTree, then send processes from high to low priority to cpu.
	BinarySearchTree* binarySearchTree = new BinarySearchTree();

public:
	Scheduler(void);
	~Scheduler(void);

	//Returns the node in the front of the queue and delete that node from the queue
	//Simply it will be called when cpu executes waiting process
	Node* NodeDequeue(void);

	//Takes the new process as argument, either sends it to diretly to cpuQueue or to binarySearchTree according to conditions.
	void Schedule(Node newProcess);

	//Pushes elements held in binarySearchTree to queue
	//It is called either when binarySearchTree has 15 elements or there is no waiting processes in the queue furthermore
	void pushBinarySearchTreeToQueue();


	//For Testing 
	Queue* getQueue()
	{
		return cpuQueue;
	}

	BinarySearchTree* getTree()
	{
		return binarySearchTree;
	}

};