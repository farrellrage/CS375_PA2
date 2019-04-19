#include "ItemClass.h"

//Constructors------------------------------------------------------------------

//------------------------------------------------------------------------------
//Item: Default constructor
//------------------------------------------------------------------------------
Item::Item(void)
{
	weight = 0;
	profit = 0;
	ratio = 0;
} // !Item

//------------------------------------------------------------------------------
//Item: Value constructor
//--------------------------------------
//	newWeight:
//		Weight of the new Item
//	newProfit:
//		Value of the new Item
//------------------------------------------------------------------------------
Item::Item(const int& newWeight, const int& newProfit)
{
	weight = newWeight;
	profit = newProfit;
	SetRatio();
} // !Item

//Get Methods-------------------------------------------------------------------

//------------------------------------------------------------------------------
//GetWeight: Returns the Item's weight
//------------------------------------------------------------------------------
int Item::GetWeight(void) const
{
	return weight;
} // !GetWeight

//------------------------------------------------------------------------------
//GetProfit: Returns the Item's profit
//------------------------------------------------------------------------------
int Item::GetProfit(void) const
{
	return profit;
} // !GetProfit

//------------------------------------------------------------------------------
//GetRatio: Returns the Item's profit / weight ratio
//------------------------------------------------------------------------------
int Item::GetRatio(void) const
{
	return ratio;
} // !GetRatio

//Set Methods-------------------------------------------------------------------

//------------------------------------------------------------------------------
//SetWeight: Set the Item's weight
//--------------------------------------
//	newWeight:
//		Weight of the new Item
//------------------------------------------------------------------------------
void Item::SetWeight(const int& newWeight)
{
	weight = newWeight;
} // !SetWeight

//------------------------------------------------------------------------------
//SetWeight: Set the Item's value
//--------------------------------------
//	newProfit:
//		Value of the new Item
//------------------------------------------------------------------------------
void Item::SetProfit(const int& newProfit)
{
	profit = newProfit;
} // !SetProfit

//------------------------------------------------------------------------------
//SetRatio: Set the Item's profit / weight ratio based on the weight and profit
//	fields
//------------------------------------------------------------------------------
void Item::SetRatio(void)
{
	ratio = floor((double)profit / weight);
} // !SetRatio

//Print Methods-----------------------------------------------------------------

//------------------------------------------------------------------------------
//Print: Prints the Item's weight, profit, and ratio fields to standard output
//------------------------------------------------------------------------------
void Item::Print(void) const
{
	cout << "Weight: " << weight
		<< ", Profit: " << profit
		<< ", Ratio: " << ratio << endl;
} // !Print

//Other Methods-----------------------------------------------------------------

//------------------------------------------------------------------------------
//operator<: Determines whether this Item is less than the given Item
//--------------------------------------
//	other:
//		Item object to compare this Item's ratio to
//------------------------------------------------------------------------------
bool Item::operator<(const Item& other) const
{
	return ratio < other.GetRatio();
} // !operator<

//------------------------------------------------------------------------------
//operator>: Determines whether this Item is greater than the given Item
//--------------------------------------
//	other:
//		Item object to compare this Item's ratio to
//------------------------------------------------------------------------------
bool Item::operator>(const Item& other) const
{
	return ratio > other.GetRatio();
} // !operator>

//Friend Methods----------------------------------------------------------------

//------------------------------------------------------------------------------
//operator<<: Formats the data fields from the given Item object and sends them
//	to the output stream object
//--------------------------------------
//	out:
//		Output stream object to send output to
//	item:
//		Item object to output to the output stream object
//------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Item& item)
{
	out << "Weight: " << item.GetWeight()
		<< ", Profit: " << item.GetProfit()
		<< ", Ratio: " << item.GetRatio();
		
	return out;
} // !operator<<

//Destructor--------------------------------------------------------------------
Item::~Item(void)
{
	
} // !~Item