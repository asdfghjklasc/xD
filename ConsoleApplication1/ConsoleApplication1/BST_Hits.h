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
	void insert1(itemType2 item);
	void insert1(BinaryNodeHits* &t, itemType2 item);

	/*// search an item in the binary search tree
	BinaryNodeHits* search(itemType2 target);
	BinaryNodeHits* search(BinaryNodeHits* t, itemType2 target);*/

	// delete an item in the binary search tree
	void remove(country target);
	void remove(BinaryNodeHits* &t, country target);

	// print the country inorder based on the no. of hits 
	void printinorderofhits();
	void printinorderofhits(BinaryNodeHits* t);

	// display the country with the max no. of hits 
	void displayMaxHits();;
	void displayMaxHits(BinaryNodeHits* &t);

	int maxhits();
	int maxhits(BinaryNodeHits * t);

	// check if the binary search tree is empty
	bool isempty();
};