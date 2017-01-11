#include "stdafx.h"
#include <string>
using namespace std;
#include "BinaryNodeHits.h"
#include "BST_Hits.h"
#include "country.h"
#include "BinaryNodeHits.h"
#include <iostream>
BST_Hits::BST_Hits() {};

void BST_Hits::insert(itemType2 item) {}

void BST_Hits::printinorderofhits()
{
	if (isempty())
	{
		cout << "tree is empty" << endl;
	}
	else
	{
		printinorderofhits(root);
	}
}

void BST_Hits::printinorderofhits(BinaryNodeHits* t)
{
	printinorderofhits(t->right);
	cout << (*(t->item)).getHit_count() << endl;
	printinorderofhits(t->left);
}

int BST_Hits::displayMaxHits()
{
	return displayMaxHits(root);
}
int BST_Hits::displayMaxHits(BinaryNodeHits* t)
{
	if (t->right == NULL)
	{
		return (*(t->item)).getHit_count();
	}
}
bool BST_Hits::isempty()
{
		return (root == NULL);
}