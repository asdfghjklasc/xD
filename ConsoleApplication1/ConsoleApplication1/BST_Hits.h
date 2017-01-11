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
	BST_Hits();

	void insert(itemType2 item);
	void insert(BinaryNodeHits* t, itemType2 item);

	BinaryNodeHits* search(itemType2 target);
	BinaryNodeHits* search(BinaryNodeHits* t, itemType2 target);

	void remove(itemType2 target);
	void remove(BinaryNodeHits* t, itemType2 target);

	void printinorderofhits();
	void printinorderofhits(BinaryNodeHits* t);

	int displayMaxHits();
	int displayMaxHits(BinaryNodeHits*);
};