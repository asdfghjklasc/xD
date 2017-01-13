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

void BST_Hits::insert(BinaryNodeHits* &t, itemType2 item)
{
	if (t == NULL)
	{
		BinaryNodeHits *NewNode = new BinaryNodeHits;
		NewNode->item = item;
		NewNode->right = NULL;
		NewNode->left = NULL;
		t = NewNode;
	}

	else
	{
		if ((*(t->item)).getHit_count() > (*(item)).getHit_count())
		{
			insert(t->right, item);
		}

		else
		{
			insert(t->left, item);
		}
	}
}

// delete an item in the binary search tree
void remove(itemType2 target) {};
void remove(BinaryNodeHits* t, itemType2 target) {};

// print the country inorder based on the no. of hits 
void BST_Hits::printinorderofhits()
{
	if (isempty())
	{
		cout << "Error: The country respository is empty" << endl;
	}
	else
	{
		printinorderofhits(root);
	}
}

void BST_Hits::printinorderofhits(BinaryNodeHits* t)
{
	if (t != NULL)
	{
		printinorderofhits((t->left));
		cout << (*(t->item)).getName() << (*(t->item)).getDescription() << (*(t->item)).getHit_count() << endl; 
		printinorderofhits((t->right));
	}
}

// display the country with the max no. of hits 
int BST_Hits::displayMaxHits()
{
	return displayMaxHits(root);
}

int BST_Hits::displayMaxHits(BinaryNodeHits* &t)
{
	if (t->right != NULL)
	{
		t = t->right;
	}
	else
	{
		return (*(t->item)).getHit_count();
	}
}

// check if the binary search tree is empty
bool BST_Hits::isempty()
{
		return (root == NULL);
}

