#pragma once
#include <string>
#include "country.h"
using namespace std;
typedef country ItemType;

struct BinaryNode
{
	ItemType   item;	// data item
	BinaryNode *left;	// pointer pointing to left subtree
	BinaryNode *right;	// pointer pointing to right subtree
};