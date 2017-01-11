#include <string>
using namespace std;
#include "BinaryNodeHits.h"
#include "BST_Hits.h"
#include "country.h"

BST_Hits::BST_Hits() {};

void BST_Hits::insert(itemType2 item) {};
void BST_Hits::insert(BinaryNodeHits* t, itemType2 item);

BinaryNodeHits* BST_Hits::search(itemType2 target);
BinaryNodeHits* BST_Hits::search(BinaryNodeHits* t, itemType2 target);

void BST_Hits::remove(itemType2 target);
void BST_Hits::remove(BinaryNodeHits* t, itemType2 target);

void BST_Hits::printinorderofhits();
void BST_Hits::printinorderofhits(BinaryNodeHits* t);

int BST_Hits::displayMaxHits();
int BST_Hits::displayMaxHits(BinaryNodeHits* t);
};