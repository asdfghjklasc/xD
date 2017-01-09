#pragma once
#include <string>
using namespace std;

class country 
{
private:
	string name;         // name of the tourist attraction 
	string description;  // description of the tourist attraction 
	double price;        // price to go to the tourist attraction 
	int hit_count;       // the hit count of the number of times people search for this particular place 

public:
	// default constructor 
	country(); 

	// parameterised constructor 
	country(string name, string description, double price, int hit_count); 

	// get the name of the tourist attraction 
	string getName();  

	// set the name of the tourist attraction
	void setName(string name);   

	// get the description of the tourist attraction 
	string getDescription();  

	// set the description of the tourist attraction 
	void setDescription(string description); 

	// get the price
	double getPrice();   

	// set the price
	void setPrice(double price);   

	// get the hit count
	int getHit_count();  

	// set the hit count 
	void setHit_count(int hit_count);  
}; 
