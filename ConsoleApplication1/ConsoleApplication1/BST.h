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

	// search an item in the binary search tree
	void search(string item);
	void search(BinaryNode* t, string item); 

	// delete an item in the binary search tree 
	void remove(string item);
	void remove(BinaryNode* &t, string item);

	// check if the binary search tree is empty
	bool isEmpty();

	// traverse the tree in an inorder manner 
	void inorder(); 
	void inorder(BinaryNode* t);

	// save data to a file 
	void saveData();
	void saveData(BinaryNode* t, ofstream& fileName);

	// count the number of countries in the world 
	int countCountry();
	int countCountry(BinaryNode* t);

	// display the number of hits of an item
	void searchforHit(string target);
	void searchforHit(BinaryNode* t, string target);
};



