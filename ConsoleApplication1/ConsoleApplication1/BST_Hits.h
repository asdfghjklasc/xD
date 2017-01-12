#pragma once
#include <string>
using namespace std;
#include "BinaryNodeHits.h"
#include "country.h"
typedef country* itemType2;

class BST_Hits
{
private: 
	BinaryNodeHits* root;

public: 
	// default constructor
	BST_Hits();

	// add an item to the binary search tree
	void insert(itemType2 item);
	void insert(BinaryNodeHits* t, itemType2 item);

	/*// search an item in the binary search tree
	BinaryNodeHits* search(itemType2 target);
	BinaryNodeHits* search(BinaryNodeHits* t, itemType2 target);

	// delete an item in the binary search tree
	void remove(itemType2 target);
	void remove(BinaryNodeHits* t, itemType2 target);*/

	// print the country inorder based on the no. of hits 
	void printinorderofhits();
	void printinorderofhits(BinaryNodeHits* t);

	// display the country with the max no. of hits 
	int displayMaxHits();
	int displayMaxHits(BinaryNodeHits*);

	// check if the binary search tree is empty
	bool isempty();
};