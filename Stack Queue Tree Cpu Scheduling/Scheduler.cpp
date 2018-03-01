#include "Scheduler.h"

Scheduler::Scheduler()
{
}

Scheduler::~Scheduler()
{
}

void Scheduler::Schedule(Node newProcess)
{
	// If cpuQueue and binarySearchTree are empty, newProcess is directly sent to cpu queue
	if (cpuQueue->getFrontNode() == nullptr)
	{
		cpuQueue->Enqueue(newProcess.getPriority(), newProcess.getVal());
		// If cpuQueue is empty but binarySearchTree isnt, then all processes held in binarySearchTree will be pushed to cpu queue
		if (binarySearchTree->getRoot() != nullptr)
		{
			pushBinarySearchTreeToQueue();
		}
	}

	//If cpuQueue and binarySearchTree arent empty and number of processes in binarySearchTree less than 16
	//new process will be inserted to binarySearchTree
	else if (cpuQueue->getFrontNode() != nullptr && binarySearchTree->getNumberOfElements() < 15)
	{
		binarySearchTree->insert(newProcess.getPriority(), newProcess.getVal());
	}
	//if binarySearchTree reaches 16 elements then these 16 elements
	//are going to be pushed into cpuQueue then new processes will be continued to being written to binarySearchTree
	//until again they are going to be 16.
	//Pushing proccesses held in tree to queue when they become 16, simply guarantees that low priority processes are going to be executed.
	//They wont wait high priority processes infinitively. They will just wait max 16 processes.
	else if (cpuQueue->getFrontNode() != nullptr && binarySearchTree->getNumberOfElements() > 14)
	{
		binarySearchTree->insert(newProcess.getPriority(), newProcess.getVal());
		pushBinarySearchTreeToQueue();
	}
}

void Scheduler::pushBinarySearchTreeToQueue()
{

#ifdef _DEBUG 
	getTree()->printTree(getTree()->getRoot());
	cout << endl << "------------------------------------------------" << endl;
#endif

	do
	{
		Node* toBeDeleted = binarySearchTree->deleteMax();
		cpuQueue->Enqueue(toBeDeleted->getPriority(), toBeDeleted->getVal());
	} while (binarySearchTree->getRoot() != nullptr);
}

Node* Scheduler::NodeDequeue(void)
{
	if (front == nullptr)								// If queue is empty
	{
		return NULL;
	}
	else if (front != nullptr && back == nullptr)		// If queue contains only one element
	{
		Node* ret = front;
		front = nullptr;
		return ret;
	}
	else if (front->getPrev()->getPrev() == nullptr)	// If queue contains 2 elements
	{
		Node* ret = front;
		front->getPrev()->setNext(nullptr);
		front = front->getPrev();
		back = nullptr;
		return ret;
	}
	else												// If queue contains at least 3 elements
	{
		Node* ret = front;
		front->getPrev()->getPrev()->setNext(front->getPrev());
		front->getPrev()->setNext(nullptr);
		front = front->getPrev();
		return ret;
	}
}