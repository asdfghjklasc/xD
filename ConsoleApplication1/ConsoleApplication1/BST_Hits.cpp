#include "stdafx.h"
#include <string>
using namespace std;
#include "BinaryNodeHits.h"
#include "BST_Hits.h"
#include "country.h"
#include "BinaryNodeHits.h"
#include <iostream>

// default constructor
BST_Hits::BST_Hits()
{
	root = NULL; 
};

// add an item to the binary search tree
void BST_Hits::insert(itemType2 item)
{
	return insert(root, item);
}

void BST_Hits::insert(BinaryNodeHits* t, itemType2 item)
{
	if ((*(t->item)).getHit_count() > (*item).getHit_count())  // insert in the right sub-tree 
	{
		insert(t->right, item);
	}

	else  // insert in the left sub-tree 
	{
		insert(t->left, item);
	}	
}

// print the country inorder based on the no. of hits 
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

// display the country with the max no. of hits 
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

// check if the binary search tree is empty
bool BST_Hits::isempty()
{
		return (root == NULL);
}