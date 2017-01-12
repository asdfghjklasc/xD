#include "stdafx.h"
#include <iostream>
#include "fstream"  // stream class to both read and write from/to files.
#include <sstream>
#include <string>
using namespace std; 
#include "country.h"
#include "BST.h"
#include "BinaryNode.h"
#include "BST_Hits.h"
#include "BinaryNodeHits.h"
BST tree;
BST_Hits hit_tree; 

// Miscellaneous features 
//
// 
// MENU 
// Basic Features of the application 
// 1. search for an item 
// 2. display the items in ascending order (of name) 
// 3. display the number of hits of an item.
// 4. count the number of countries in the world 
// 5. save data to a file 
// 6. load data from a file 

// Additional features 
// 1. Able to add 
// 2. Able to remove item
// 3. Able to display items in descending order of hit count
// 4. Algorithm optimisation
// 5. Graphical User Interface
// 6. User validation

// to print the menu of the application
void displayMenu() 
{
	cout << "MENU" << endl;
	cout << "=======================================================" << endl;
	cout << "1. Search for an item" << endl;
	cout << "2. Display the items in ascending order (of name)" << endl;
	cout << "3. Display the number of hits of an item." << endl; 
	cout << "4. Display the total number of countries in the world" << endl; 
	cout << "5. Save data to a file" << endl;
	cout << "6. Load data from a file" << endl;
	cout << "7. Add an item" << endl;
	cout << "8. Remove an item" << endl;
	cout << "9. Display items in descending order of hit count" << endl << endl;
}
int gethits(string Name)
{
	return(tree.searchforobj(Name)).getHit_count();
}

// option 1 of the menu 
void option1()
{
	string target;
	cout << "Enter the name of the country: ";
	cin >> target;
	tree.search(target);
}

// option 2 of the menu 
void option2()
{
	tree.inorder();
}

// option 3 of the menu 
void option3()
{
	string input;
	cout << "Enter the name of the country : ";
	cin >> input;
	cout << gethits(input) << endl;
}

// option 4 of the menu 
void option4()
{
	cout << tree.countCountry() << endl;
}

// option 5 of the menu 
void option5()
{
	tree.saveData();
}

// option 6 of the menu 
void option6()
{
	string line;
	ifstream myfile;
	string input;
	cout << "Enter the file name : ";
	cin >> input;
	myfile.open(input);
	while (getline(myfile, line))
	{
		stringstream linestream(line);
		string name;
		string description;
		string price;
		string hit_count;
		getline(linestream, name, ';');
		getline(linestream, description, ';');
		getline(linestream, price, ';');
		getline(linestream, hit_count, ';');
		country c1(name, description, stof(price), atoi(hit_count.c_str()));
		tree.insert(c1);
		hit_tree.insert(&c1);
	}
	myfile.close();
}

// option 7 of the menu 
void option7()
{
	string name;
	string description;
	double price;
	int hit_count;

	cout << "Enter the name of the country : ";
	cin >> name;
	cout << "Enter the description of the country : ";
	cin >> description;
	cout << "Enter the price to travel to the country : ";
	cin >> price;
	hit_count = 0;
	country c1(name, description, price, hit_count);
	tree.insert(c1);
	hit_tree.insert(&c1);
}

// option 8 of the menu 
void option8()
{
	string item;
	cout << "Enter the name of the country : ";
	cin >> item;
	tree.remove(item);
	// hit_tree.remove(&item); 
}

// option 9 of the menu 
void option9()
{
	cout << hit_tree.isempty();
}

// main program 
int main()
{
	cout << "Please load a file containing the list of countries" << endl; 
	int choice; 
	displayMenu();
	cout << "Please enter your choice : ";
	cin >> choice; 
	
	while (choice >= 1 && choice <= 9)
	{
		// search for an item 
		if (choice == 1)  
		{
			option1(); 
		}

		// display the items in ascending order (of name) 
		else if (choice == 2)  
		{
			option2();
		}

		// display the number of hits of an item.
		else if (choice == 3)
		{
			option3();
		}

		// count the number of countries in the world 
		else if (choice == 4)
		{
			option4();
		}

		else if (choice == 5)  // save data to a file  
		{
			option5();
		}

		else if (choice == 6)  // load data from a file 
		{
			option6();
		}

		else if (choice == 7)  // Able to add 
		{
			option7();
		}

		else if (choice == 8)  // Able to remove item
		{
			option8();
		}

		else if (choice == 9)  // Able to display items in descending order of hit count
		{
			option9();
		}

		cout << endl << endl << endl << endl;
		displayMenu();
		cout << "Please enter your choice : ";
		cin >> choice;
	}
	system("pause"); 
}


