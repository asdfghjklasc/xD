#pragma once
#include <string>
#include "BinaryNode.h"
#include "country.h"
#include "BST_Hits.h" 
typedef country itemType;

class BST
{
private: 
	BinaryNode* root;  // root of the binary search tree 

public: 
	// default constructor
	BST();  

	// add an item to the binary search tree
	void insert(itemType item, BST_Hits &tree);
	void insert(BinaryNode* &t, itemType item, BST_Hits &tree);

	// delete an item in the binary search tree 
	void remove(string item);
	void remove(BinaryNode* &t, string item);

	// check if the binary search tree is empty
	bool isEmpty();

	// traverse the tree in an inorder manner 
	void inorder(); 
	void inorder(BinaryNode* t);

	// save data to a file (.txt)
	void saveData();
	void saveData(BinaryNode* t, ofstream& fileName);

	// save data to a file (.xls)
	void saveExcelData();
	void saveExcelData(BinaryNode* t, int row);

	// count the number of countries in the world 
	int countCountry();
	int countCountry(BinaryNode* t);

	// display the number of hits of an item
	ItemType displayHits(string target);
	ItemType displayHits(BinaryNode* t, string target);
};



