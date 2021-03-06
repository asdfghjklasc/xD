// this tree is mainly used for storing the class objects and used for primarily for (display the items in ascending order (of name))
#include "stdafx.h"
#include "iostream"
#include "fstream"  // stream class to both read and write from/to files.
#include "libxl.h"
using namespace libxl;
using namespace std; 
#include "BinaryNode.h"
#include "country.h"
#include "BST.h"
#include "BinaryNodeHits.h"
#include "BST_Hits.h"

// default constructor 
BST::BST()  
{
	root = NULL; 
}

// add an item to the binary search tree
void BST::insert(itemType item, BST_Hits &HitsTree)
{
	insert(root, item, HitsTree);
}

void BST::insert(BinaryNode* &t, itemType item, BST_Hits &HitsTree)
{
	if (t == NULL)  // check if the tree is empty
	{
		BinaryNode* newNode = new BinaryNode;
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;
		HitsTree.insert1(&(t->item));
	}
	else
	{
		if (item.getName() < t->item.getName())  // insert in the right sub-tree 
		{
			insert(t->left, item, HitsTree);
		}

		else                                     // insert in the left sub-tree 
		{
			insert(t->right, item, HitsTree);
		}
	}
}

// delete an item from the binary search tree
void BST::remove(string item)
{
	if (isEmpty())
	{
		cout << "Error: The country respository is empty. " << endl; 
	}
	
	else
	{
		remove(root, item); 
	}
}

void BST::remove(BinaryNode* &t, string item)
{
	BinaryNode* temp = t;
	BinaryNode* parent = NULL;
	bool Left = false;
	bool found = false;
	while ((!found) && (temp != NULL))
	{
		if (item == (temp->item).getName())
		{
			found = true;
		}

		else
		{
			parent = temp;
			if (item < (temp->item).getName())
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
				t = NULL;
			else
				if (Left)
					parent->left = NULL;
				else
					parent->right = NULL;
		}
		else
			if (temp->left == NULL)
			{
				if (Left)
					parent->left = temp->right;
				else
					parent->right = temp->right;;
			}
			else
				if (temp->right == NULL)
				{
					if (Left)
						parent->left = temp->left;
					else
						parent->right = temp->left;;
				}
				else
				{
					BinaryNode* successor = temp->left;
					while (successor->right != NULL)
						successor = successor->right;
					string item = (successor->item).getName();
					ItemType successoritem = successor->item;
					remove(t, item);
					temp->item = successoritem;
				}
	}
}

// check if the binary search tree is empty
bool BST::isEmpty() 
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

// inorder traversal 
void BST::inorder()
{
	if (isEmpty())
	{
		cout << "Error: The country respository is empty. " << endl;
	}
		
	else
	{
		inorder(root);
	}
}

void BST::inorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		cout << t->item.getName() << endl;
		inorder(t->right);
	}
}

// save data to a file (.txt)
void BST::saveData()
{
	if (isEmpty())
	{
		cout << "Error: The country respository is empty. " << endl;
	}

	else
	{
		string fileName;
		cout << "Enter the file name : ";
		cin >> fileName;

		ofstream myfile;
		myfile.open(fileName);
		saveData(root, myfile);
	}
}

void BST::saveData(BinaryNode* t, ofstream& fileName)
{
	if (t != NULL)
	{
		saveData(t->left, fileName);
		fileName << t->item.getName() << ";" << t->item.getDescription() << ";" << t->item.getPrice() << endl; 
		saveData(t->right, fileName);
	}
}

// save data to a file (.xls)
/*void BST::saveExcelData()
{
	if (isEmpty())
	{
		cout << "Error: The country respository is empty. " << endl;
	}

	else
	{
		string input;
		cout << "Enter new Excel file name:" << endl;
		cin >> input;

		Book* book = xlCreateBook();
		if (book)
		{
			Sheet* sheet = book->addSheet("CountrySheet");
			saveExcelData(root, 0);
		}

		if (book->save(input))
		{
			cout << "File has been created." << endl;
		}
	}
}

void BST::saveExcelData(BinaryNode* t, int row)
{
	if (t != NULL)
	{
		//write string value
		sheet->writeStr(row, 0, t->item.getName());
		sheet->writeStr(row + 1, 0, t->item.getDescription());

		//write numeric value
		sheet->writeNum(row + 2, 0, t->item.getPrice());
		sheet->writeNum(row + 3, 0, t->item.getHit_count());

		saveExcelData(t->left, row + 4);
		saveExcelData(t->right, row + 8);
	}
}*/

// count the number of countries in the world 
int BST::countCountry()
{
	return countCountry(root);
}

int BST::countCountry(BinaryNode* t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + countCountry(t->left) + countCountry(t->right);
	}
}

// display the number of hits of an item
ItemType BST::displayHits(string target)
{
	return displayHits(root, target);
}

ItemType BST::displayHits(BinaryNode* t, string target)
{
	if (t == NULL)
	{
		cout << "Error : Country not found. " << endl; 
		throw exception();
	}

	else
	{
		if ((t->item).getName() == target)
		{
			return t->item;
		}

		else if (target > (t->item).getName())
		{
			return displayHits(t->right, target);
		}

		else
		{
			return displayHits(t->left, target);
		}
	}
}
