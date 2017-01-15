#include "stdafx.h"
#include "iostream"
#include "algorithm"
#include <string>
#include "HashTable.h"
#include "BST.h" 
#include "country.h"
using namespace std; 

// intialise the hash table array
HashTable::HashTable()  
{
	for (int i = 0; i < tableSize; i++)  // to run through every index in the hash table 
	{
		table[i] = new hItem;
		table[i]->name = "empty"; 
		table[i]->description = "empty"; 
		table[i]->price = 0;
		table[i]->hit_count = 0;
		table[i]->next = NULL;
	}
}

// hash algorithm 
int HashTable::hash(string key)  
{
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % tableSize; 
	return index; 
}

// insert an item into the hash table 
void HashTable::addItem(itemType2 item)  
{
	int index = hash(item.getName());  // hold the location in the hash table to store this info
	if (table[index]->name == "empty")  // if the hash table bucket/index is empty 
	{
		table[index]->name = item.getName();
		table[index]->description = item.getDescription();
		table[index]->price = item.getPrice();
		table[index]->hit_count = item.getHit_count();
	}

	else
	{
		hItem* ptr = table[index];  // point to the first index in the hash table
		hItem* newPtr = new hItem;  // point to the new item 
		newPtr->name = item.getName();
		newPtr->description = item.getDescription();
		newPtr->price = item.getPrice(); 
		newPtr->hit_count = item.getHit_count(); 
		newPtr->next = NULL;

		while (ptr->next != NULL)  
		{
			ptr = ptr->next;
		}
		ptr->next = newPtr; 
	}
}

// remove an item from the hash table 
void HashTable::removeItem(string item)
{
	int index = hash(item);  // to obtain the bucket where the item is stored in the hash table 

	// the bucket is empty 
	if (table[index]->name == "empty")
	{
		cout << "Error : No such country exist. " << endl;
	}

	// Bucket only contains one item and it matches the item to be deleted 
	else if (table[index]->name == item && table[index]->next == NULL)
	{
		table[index]->name = "empty";
		table[index]->description = "empty";
		table[index]->price = 0;
		table[index]->hit_count = 0;
	}

	// Bucket contains more than one item and the item to be deleted matches the first item in the bucket 
	else if (table[index]->name == item && table[index]->next != NULL)
	{
		hItem* temp = table[index];  // the pointer that points to the bucket item (used as a delete pointer) 
		table[index] = table[index]->next;
		delete temp;
	}

	// Bucket contains more than one item but the first item is not a match 
	else
	{
		hItem* p1 = table[index]->next;
		hItem* p2 = table[index];

		// no match
		if (p1 == NULL)
		{
			cout << "Error." << endl; 
		}

		// match 
		else
		{
			hItem* delPtr = p1;
			p1 = p1->next;
			p2->next = p1;
			delete delPtr;
		}
	}
}

// count the number of items in a hash bucket/index (FOR TESTING PURPOSES IGNORE) 
int HashTable::numberOfItemsInIndex(int index) 
{
	int count = 0;
	if (table[index]->name == "empty")
	{
		return 0;
	}

	else
	{
		count++;
		hItem* ptr = table[index];
		while (ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return count; 
}

// for testing purposes (IGNORE) 
void HashTable::printTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = numberOfItemsInIndex(i);
		cout << "------------" << endl; 
		cout << "index = " << i << endl;
		cout << "Name : " << table[i]->name << endl;
		cout << "Hit_count : " << table[i]->hit_count << endl; 
		cout << "No. of items = " << number << endl;
		cout << "------------" << endl;
	}
}

// for testing purposes (IGNORE) 
void HashTable::printItemsInIndex(int index)
{
	hItem* ptr = table[index]; 
	if (ptr->name == "empty")
	{
		cout << "index = " << " " << index << "is empty" << endl; 
	}

	else
	{
		cout << "index = " << " " << index << " " << "contains the following items" << endl;
		while (ptr != NULL)
		{
			cout << "------------" << endl;
			cout << ptr->name << endl;
			cout << ptr->hit_count << endl;
			cout << "------------" << endl;
			ptr = ptr->next;
		}
	}
}

// display the items in ascending order (of name)
void HashTable::sortAndPrintByName(int arraySize)
{ 
	string* countryArray; 
	countryArray = new string[arraySize];  // dynamic array to store the names of the countries 
	int a = 0;  // counter for the array 

	for (int i = 0; i < tableSize; i++)  // obtaining the values from the hash table and storing them in a dynamic array 
	{
		if (table[i]->name != "empty")
		{
			countryArray[a] = table[i]->name;
			a++;
			if (table[i]->next != NULL)
			{
				hItem* ptr = table[i]; 
				ptr = ptr->next; 
				while (ptr != NULL)
				{
					countryArray[a] = ptr->name;
					a++;
					ptr = ptr->next; 
				}
			}
		}
	}

	for (int i = 0; i < arraySize; i++)  // sorting algorithm 
	{
		for (int f = 0; f < arraySize; f++)
		{
			if (countryArray[i] < countryArray[f])
			{
				string swap = countryArray[i];
				string swap2 = countryArray[f];
				countryArray[i] = swap2; 
				countryArray[f] = swap;
			}
		}
	}

	for (int i = 0; i < arraySize; i++)  // printing the contents of the array 
	{
		cout << countryArray[i] << endl; 
	}
}



	


