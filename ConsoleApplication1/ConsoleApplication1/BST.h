#pragma once
#include <string>
#include "BinaryNode.h"
#include "tourist_attraction.h"
typedef tourist_attraction itemType;

class BST
{
private: 
	BinaryNode* root;  // root of the binary search tree 

public: 
	BST();  // default constructor 
	BinaryNode* search(BinaryNode* t, itemType target);  // search an item in the binary search tree
	void insert(BinaryNode* &t, itemType item);  // add an item to the binary search tree
	void remove(BinaryNode* &t, itemType item);  // delete an item from the binary search tree
	bool isEmpty(BinaryNode* t);  // check if the binary search tree is empty
	bool isBalanced(BinaryNode* t);  // check if the binary search tree is balanced
};


