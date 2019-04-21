#ifndef ItemClass_h
#define ItemClass_h

#include "Main.h"

class Item
{
private:
	int weight;
	int profit;
	int ratio;
	
public:
	//Constructors--------------------------------------------------------------
	
	//Default constructor
	Item(void);
	
	//Value constructor
	Item(const int& newWeight, const int& newProfit);
	
	//Get Methods---------------------------------------------------------------
	
	//Returns the Item's weight
	int GetWeight(void) const;
	
	//Returns the Item's profit
	int GetProfit(void) const;
	
	//Returns the Item's profit / weight ratio
	int GetRatio(void) const;
	
	//Set Methods---------------------------------------------------------------
	
	//Set the Item's weight
	void SetWeight(const int& newWeight);
	
	//Set the Item's value
	void SetProfit(const int& newProfit);
	
	//Set the Item's profit / weight ratio
	void SetRatio(void);
	
	//Print Methods-------------------------------------------------------------
	
	//Prints the Item's weight, profit, and ratio fields to standard output
	void Print(void) const;
	
	//Other Methods-------------------------------------------------------------
	
	//Determines whether this Item is less than the given Item
	bool operator<(const Item& other) const;
	
	//Determines whether this Item is greater than the given Item
	bool operator>(const Item& other) const;
	
	//Friend Methods------------------------------------------------------------
	
	//Formats the data fields from the given Item object and sends them
	//to the output stream object
	friend ostream& operator<<(ostream& out, const Item& item);
	
	//Destructor----------------------------------------------------------------
	~Item(void);
	
}; // !Item
#endif // !ItemClass_h