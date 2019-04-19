#include "Main.h"
#include "HelperFunctions.h"

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
void ParseBestFirstSearchInputLine(ifstream& fin, int& first, int& second);

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
void BestFirstSearchBrandBound(vector<Item>& items);