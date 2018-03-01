#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class BinarySearchTree
{
	Node *root;			  //The node on the top of tree
	Node* parentOfMax;	  //Parent of max element. Used for setting child of this node which is max to nullptr when max is wanted to be deleted.
	int numberOfElements; //Number of elements that tree contain

public:
	BinarySearchTree();
	~BinarySearchTree();

	//Inserts a new node to tree, assigns given priority and processID to this node
	void insert(int priority, int processID);

	//Returns root node of tree
	Node* getRoot();
	// Returns number of elements that tree contains
	int getNumberOfElements();

	//Deletes the node that has highest priority in the tree and returns that node.
	Node* deleteMax();

	//When we want to delete max element, since it is child of its parent,
	//We have to delete child node of its parent, thats why we need parent of max.
	Node* findParentOfMax(Node* node);

	void printTree(Node *temp, int level = 1);
};