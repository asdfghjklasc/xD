#pragma once
#include <string>
#include "BinaryNode.h"
#include "country.h"
typedef country itemType;

class BST
{
private: 
	BinaryNode* root;  // root of the binary search tree 

public: 
	// default constructor
	BST();  

	// add an item to the binary search tree
	void insert(itemType item); 
	void insert(BinaryNode* &t, itemType item); 

	//// search an item in the binary search tree
	//BinaryNode* search(BinaryNode* t, itemType target);

	// delete an item from the binary search tree
	//void remove(BinaryNode* &t, itemType item); 

	// check if the binary search tree is empty
	bool isEmpty();

	// check if the binary search tree is balanced
	//bool isBalanced(BinaryNode* t); 

	void inorder(); 
	void inorder(BinaryNode* t);

};


