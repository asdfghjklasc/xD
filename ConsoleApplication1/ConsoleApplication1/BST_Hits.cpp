#include "stdafx.h"
#include <string>
using namespace std;
#include <iomanip>
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
void BST_Hits::insert1(itemType2 item)
{
	return insert1(root, item);
}

void BST_Hits::insert1(BinaryNodeHits* &t, itemType2 item)
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
			insert1(t->left, item);
		}

		else
		{
			insert1(t->right, item);
		}
	}
}

// delete an item in the binary search tree
void BST_Hits::remove(country target)
{
	{
		remove(root, target);
	}
}

void BST_Hits::remove(BinaryNodeHits *&t, country target)
{
	BinaryNodeHits* temp = t;
	BinaryNodeHits* parent = NULL;
	bool Left = false;
	bool found = false;
	while ((!found) && (temp != NULL))
	{
		if (target.getName() == (*(temp->item)).getName() && target.getHit_count() == (*(temp->item)).getHit_count())
		{
			found = true;
		}
		else
		{
			parent = temp;
			if (target.getHit_count() < (*(temp->item)).getHit_count())
			{
				temp = temp->left;
				Left = true;
			}
			else
			{
				temp = temp->right;
				Left = false;
			}
		}
	}
	if (found)
	{
		if (temp->left == NULL && temp->right == NULL)
		{
			if (temp == t)
			{
				t = NULL;
			}
			else
				if (Left)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
		}
		else
			if (temp->left == NULL)
			{
				if (Left)
				{
					parent->left = temp->right;
				}
				else
				{
					parent->right = temp->right;
				}
			}
			else
				if (temp->right == NULL)
				{
					if (Left)
					{
						parent->left = temp->left;
					}
					else
					{
						parent->right = temp->left;;
					}
				}
				else
				{
					BinaryNodeHits* successor = temp->left;
					while (successor->right != NULL)
					{
						successor = successor->right;
					}
					country target = (*(successor->item));
					itemType2 successoritem = successor->item;
					remove(t, target);
					temp->item = successoritem;
				}
	}
}

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
		printinorderofhits(t->right);
		cout << (*(t->item)).getName() << endl;
		printinorderofhits(t->left);
	}
}

// display the country with the max no. of hits 
int BST_Hits::maxhits()
{
	return maxhits(root);
}

int BST_Hits::maxhits(BinaryNodeHits * t)
{
	while (t != NULL)
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
}

void BST_Hits::displayMaxHits()
{
	displayMaxHits(root);
}

void BST_Hits::displayMaxHits(BinaryNodeHits* &t)
{
	cout << setw(16) << "Country" << setw(16) << "Hit Count" << setw(16) << endl;
	cout << setw(16) << "-------" << setw(16) << "---------" << setw(16) << endl;
	while (t->right != NULL)
	{
		t = t->right;
		if (t == NULL)
		{
			break;
		}

		else if ((*(t->item)).getHit_count() == maxhits())
		{
			cout << setw(16) << (*(t->item)).getName() << setw(16) << (*(t->item)).getHit_count() << setw(16) << endl;
		}
	}
}


// check if the binary search tree is empty
bool BST_Hits::isempty()
{
	if (root == NULL)
	{
		return true;
	}

	else
	{
		return false; 
	}
}

