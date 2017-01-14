#pragma once
#ifndef HashTable_h
#define HashTable_h
#include "BST.h"
typedef country itemType2;

class HashTable
{
private:
	static const int tableSize = 10;  // determine the size of the hash table 

	struct hItem  // what items consist of that will be stored in the hash table 
	{
		string name;  // name of the country 
		string description;  // description of the country 
		double price;  // price to travel to the country 
		int hit_count;  // hit_count of the country 
		hItem* next;  // pointer to point to the next item 
	};

	hItem* table[tableSize];  // to create the hash table. The hash table is just going to contain a bunch of pointers and
							 // those pointers have the ability to point to item objects 
							 // The hash table which is an array which have a tableSize no. of buckets and each of those buckets contain a pointer that 
							 // is able to point to another item.
public:
	HashTable();  // default constructor 
	int hash(string key);  // hash algorithm 
	void addItem(itemType2 item);  // insert an item into the hash table 
	int numberOfItemsInIndex(int index);  // count the number of items in a hash bucket/index 
	void printTable();
	void printItemsInIndex(int index);
	void sortAndPrintByName(); 
};
#endif

