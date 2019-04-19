#include "BestFirstSearch.h"

//------------------------------------------------------------------------------
//ParseBestFirstSearchInputLine: Extracts the next line from the input file and
//	parses it to obtain the two separate values separated by a comma.
//	The input file is assumed to be formatted according to the Best First Search
//	problem where the first two values on the first line represent the problem
//	size and total weight capacity, and each subsequent line represents an item
//	with its weight and profit.
//--------------------------------------
//	fin:
//		Input file stream object to take input from
//	first:
//		First value taken from the input file
//		Returned to the caller
//	second:
//		Second value taken from the input file
//		Returned to the caller
//------------------------------------------------------------------------------
void ParseBestFirstSearchInputLine(ifstream& fin, int& first, int& second)
{
	//Index for the input string
	unsigned int index;
	
	//Length of the first value
	int firstLength;
	
	//Input string taken from the input file
	string input = "";
	
	//Holds the string representation of each value parsed from the input file
	string data = "";
	
	//Get the next line from the input file
	fin >> input;
	
	//For each digit in the first number up to the ',' character
	for (index = 0; ((index < input.length()) && (input.at(index) != ',')); index++)
	{
		//Add the next digit to the data string
		data += input.at(index);
	} // !for
	
	//Save the first value
	first = atoi(data.c_str());
	firstLength = data.length();
	
	//Increment the string index to point to the next character in the input
	//string
	index++;
	
	//Get the rest of the input string to save in the second value
	second = atoi(input
				.substr(index, (input.length() - (input.length() - firstLength) + 1))
				.c_str());
} // !ParseBestFirstSearchInputLine

//------------------------------------------------------------------------------
//BestFirstSearchBrandBound: 
//--------------------------------------
//	fin:
//		Input file stream object to take input from
//	first:
//		First value taken from the input file
//		Returned to the caller
//	second:
//		Second value taken from the input file
//		Returned to the caller
//------------------------------------------------------------------------------
void BestFirstSearchBrandBound(vector<Item>& items)
{
	//Init max profit
	
	//Create empty queue
	
	
} // !BestFirstSearchBrandBound


