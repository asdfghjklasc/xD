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
#include "libxl.h"
using namespace libxl;
#include <conio.h>

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
	cout << " 1. Search for an item" << endl;
	cout << " 2. Display the items in ascending order (of name)" << endl;
	cout << " 3. Display items in descending order of hit count" << endl;
	cout << " 4. Display the number of hits of an country." << endl; 
	cout << " 5. Display the most searched country." << endl;  // incomplete
	cout << " 6. Display the total number of countries in the world" << endl; 
	cout << " 7. Save data to a file" << endl;
	cout << " 8. Load data from a file" << endl;
	cout << " 9. Add a new country" << endl;
	cout << "10. Remove an existing country" << endl;
	cout << " 11. Load data from an Excel file" << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// search for an item
void choice1()  
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
				if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z' || c == '_'))
				{
					throw 0;
				}
			}

			tree.search(target);
		}
	}

	catch(...)
	{
		cout << "Invalid input" << endl;
	}
}
	
// display the items in ascending order (of name)
void choice2()  
{
	if (tree.isEmpty())
	{
		cout << "Error : The country respository is empty." << endl;
	}

	else
	{
		int arraySize = tree.countCountry();
		hashtable.sortAndPrintByName(arraySize);
	}
}

// display items in descending order of hit count
void choice3()  
{
	tree.inorder(); 
}

// display the number of hits of an country
void choice4() 
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
				if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z' || c == '_'))
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

// display the most searched country
void choice5()  
{
	//tree.searchforHit(); 
}

// display the total number of countries in the world
void choice6()  
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

// save data to a file
void choice7() 
{
	int option;
	tree.saveData();
}

// load data from a file
void choice8()  
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

// add a new country
void choice9()  
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
		hashtable.addItem(country);
	}

	catch (...)
	{
		cout << "Error : Invalid input entered." << endl;
	}
}

// remove an existing country
void choice10()  
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
				if (!(c >= 'a' &&  c <= 'z' || c >= 'A' && c <= 'Z' || c == '_'))
				{
					throw 0;
				}
			}

			tree.remove(item);
			hashtable.removeItem(item); 
		}

		catch (...)
		{
			cout << "Error : Invalid input entered. " << endl;
		}
	}
}

//load data from excel file
void choice11()
{
	Book* book = xlCreateBook();
	if (book)
	{
		int row = 0;
		string name;
		string description;
		double price;
		int hit_count;
		if (book->load(L"example.xls"))
		{
			Sheet* sheet = book->getSheet(0);
			while (price != NULL)
			{
				if (sheet)
				{
					//read string value
					name = sheet->readStr(row, 0);
					description = sheet->readStr(row + 1, 0);

					//read numeric value
					price = sheet->readNum(row + 2, 0);
					hit_count = sheet->readNum(row + 3, 0);

					country country(name, description, price, hit_count);
					tree.insert(country);
					row = row + 1;
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main program 
int main()
{
	try 
	{
		cout << "**Please load a file containing the list of countries**" << endl;
		int choice;
		displayMenu();
		cout << "Please enter your choice : ";
		cin >> choice;

		while (choice >= 1 && choice <= 10)
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

			// display items in descending order of hit count
			else if (choice == 3)
			{
				choice3();
			}

			// display the number of hits of an country
			else if (choice == 4)
			{
				choice4();
			}

			// display the most searched country
			else if (choice == 5)  
			{
				choice5();
			}

			// display the total number of countries in the world
			else if (choice == 6)  
			{
				choice6();
			}

			// save data to a file
			else if (choice == 7)  
			{
				choice7();
			}

			// load data from a file"
			else if (choice == 8)  
			{
				choice8();
			}

			// add a new country
			else if (choice == 9)  
			{
				choice9();
			}

			// remove an existing country
			else if (choice == 10)
			{
				choice10(); 
			}

			// load data from excel (.xls)
			else if (choice == 11)
			{
				choice11();
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


