#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
	numberOfElements = 0;
}

BinarySearchTree::~BinarySearchTree()
{
}

Node* BinarySearchTree::getRoot()
{
	return root;
}
int BinarySearchTree::getNumberOfElements()
{
	return numberOfElements;
}

void BinarySearchTree::insert(int priority, int processID)
{
	Node *newNode = new Node(processID, nullptr, nullptr, priority);

	if (root == nullptr)	// If tree is empty
	{
		root = newNode;
	}
	else
	{
		Node *index = root;
		while (true)
		{
			if (index->getPriority() > priority)	//If new value is smaller than the compared node
			{
				if (index->getPrev() == nullptr)	//If left child of index is null, insert new node to here
				{
					index->setPrev(newNode);
					break;
				}
				else  // If index has left child then make this next child new index
				{
					index = index->getPrev();
				}
			}
			else   //If new value isnt smaller than the compared node
			{
				if (index->getNext() == nullptr)	//If right child of index is null, insert new node to here
				{
					index->setNext(newNode);
					break;
				}
				else     // If index has right child then make this next child new index
				{
					index = index->getNext();
				}
			}
		}
	}
	numberOfElements++;
}

void BinarySearchTree::printTree(Node *temp, int level)
{
	if (root == nullptr)
	{
		cout << "Tree is empty" << endl;
	}
	else if (temp != nullptr)
	{
		printTree(temp->getNext(), level + 1);
		cout << endl;
		if (temp == root)
		{
			cout << "Root->:  ";
		}
		else
		{
			for (int i = 0; i < level; i++)
			{
				cout << "       ";
			}
		}
		cout << temp->getPriority();
		printTree(temp->getPrev(), level + 1);
	}
}

Node* BinarySearchTree::deleteMax()
{
	if (root == nullptr)
	{
		return NULL;	//Nothing to delete
	}
	Node* index = new Node();
	index = root;

	numberOfElements--;

	if (root->getNext() == nullptr)
	{
		//If only root is remaining, it is set to null. 
		if (root->getPrev() == nullptr)
		{
			root = nullptr;
			return index;
		}
		// If right branch of tree is empty, root element is deleted, left child is made new root.
		root = index->getPrev();
		return index;
	}

	//To delete max element, we need to find its parent.
	//Because its parent is holding it as child node, so we will set it to null
	index = findParentOfMax(index);

	//We always delete most right element in the tree
	if (index->getNext()->getNext() == nullptr)
	{
		Node* ret = new Node();
		ret = index->getNext();
		index->setNext(index->getNext()->getPrev()); // left child (either value or nullptr) of parent of most right child is assigned as right child of parent of most right child
		return ret;
	}
}

Node* BinarySearchTree::findParentOfMax(Node* node)
{
	if (node->getNext() != nullptr)  //Root must have a right child (bigger than itself)
	{
		if (node->getNext()->getNext() == nullptr) // when grand child of index is null it means we found the parent of max.
		{
			parentOfMax = node;
			return parentOfMax;
		}
		else if (node->getNext()->getNext() != nullptr) // if grand right child is not null, move index to right child and call the function again
		{
			parentOfMax = node->getNext();
			findParentOfMax(parentOfMax);
		}
	}
	return parentOfMax;
}