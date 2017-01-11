#pragma once
#include <string>
#include "country.h"
using namespace std;
typedef country* itemType2; 

struct BinaryNodeHits
{
	itemType2 item;
	BinaryNodeHits* left;
	BinaryNodeHits* right; 
};