#include "stdafx.h"
#include <iostream>
#include "fstream"  // stream class to both read and write from/to files.
#include <sstream>
#include <string>
using namespace std; 
#include "country.h"
#include "BST.h"
#include "BinaryNode.h"
#include "HashTable.h" 

BST tree;
HashTable hashtable; 

// Miscellaneous features 
// 1. to print the menu of the application 
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
/*int gethits(string Name)
{
	return(tree.searchforobj(Name)).getHit_count();
}*/

void choice1()  // search for an item
{
	try
	{
		if (tree.isEmpty())
		{
			cout << "Error : The country respository is empty." << endl;
		}

		else
		{
			char c; 
			string target;
			cout << "Enter the name of the country: ";
			cin >> target;

			for (int i = 0; i < target.length(); i++)  
			{
				c = target.at(i);
				if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z'))
				{
					throw 0;
				}
			}

			tree.search(target);
		}
	}

	catch(...)
	{
		cout << "invalid input" << endl;
	}
}
	

void choice2()  // display the items in ascending order (of name)
{
	tree.inorder();
}

void choice3()  // display the number of hits of a country 
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl; 
	}

	else
	{
		try
		{
			string input;
			cout << "Enter the name of the country : ";
			cin >> input;
			char c;  // for the try-catch 
			for (int i = 0; i < input.length(); i++)
			{
				c = input.at(i);
				if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z'))
				{
					throw 0;
				}
			}
			tree.searchforHit(input);
		}
		
		catch (...)
		{
			cout << "Error : Invalid input entered." << endl; 
		}
	}
}

void choice4()  // display the total number of countries in the world
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl;
	}

	else
	{
		cout << "There are" << " " << tree.countCountry() << " " << "countries in the world today." << endl;
	}
}

void choice5()  // save data to a file
{
	int option; 
	tree.saveData();
}

void choice6()  // load data to a file
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
		country country(name, description, stof(price), atoi(hit_count.c_str()));
		tree.insert(country);
		hashtable.addItem(country);
	}
	myfile.close();
}

void choice7()  // add an item
{
	try
	{
		string name;
		string description;
		string price;  // will be converted to double after it is validated 
		int hit_count = 0;

		cout << "Enter the name of the country : ";
		cin >> name;
		char c;  // for the try-catch 
		for (int i = 0; i < name.length(); i++)
		{
			c = name.at(i);
			if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z'))
			{
				throw 0;
			}
		}

		cout << "Enter the description of the country : ";
		cin >> description;

		cout << "Enter the price to travel to the country : ";
		cin >> price;
		char c1;  // for the try-catch 
		for (int i = 0; i < price.length(); i++)
		{
			c1 = price.at(i);
			if (!(c1 >= '1' &&  c1 <= '9'))
			{
				throw 0;
			}
		}
	
		country country(name, description, stof(price), hit_count);
		tree.insert(country);
	}
	
	catch (...)
	{
		cout << "Error : Invalid input entered." << endl; 
	}
}

void choice8()  // remove an item
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl;
	}

	else
	{
		try
		{
			string item;
			cout << "Enter the name of the country : ";
			cin >> item;

			char c;  // for the try-catch 
			for (int i = 0; i < item.length(); i++)
			{
				c = item.at(i);
				if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z'))
				{
					throw 0;
				}
			}

			tree.remove(item);
			// hit_tree.remove(&item);
		}

		catch (...)
		{
			cout << "Error : Invalid input entered. " << endl;
		}
	}
}

void choice9()  // display items in descending order of hit count
{
	// hashtable.printTable(); 
	//hashtable.printItemsInIndex(66);
	hashtable.sortAndPrintByName();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main program 
int main()
{
	try 
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
				choice1();
			}

			// display the items in ascending order (of name) 
			else if (choice == 2)
			{
				choice2();
			}

			// display the number of hits of an item.
			else if (choice == 3)
			{
				choice3();
			}

			// count the number of countries in the world 
			else if (choice == 4)
			{
				choice4();
			}

			else if (choice == 5)  // save data to a file  
			{
				choice5();
			}

			else if (choice == 6)  // load data from a file 
			{
				choice6();
			}

			else if (choice == 7)  // Able to add 
			{
				choice7();
			}

			else if (choice == 8)  // Able to remove item
			{
				choice8();
			}

			else if (choice == 9)  // Able to display items in descending order of hit count
			{
				choice9();
			}

			cout << endl << endl << endl << endl;
			displayMenu();
			cout << "Please enter your choice : ";
			cin >> choice;
		}
		throw 0; 
	}

	catch(int e)
	{
		cout << "Error : Invalid option entered. The program has been terminated." << endl;
	}
	system("pause");
}


