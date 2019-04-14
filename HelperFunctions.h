//------------------------------------------------------------------------------
//File Name:        HelperFunctions.h
//Associated file:  HelperFunctions.cpp
//Contains:
//      PrintDivider
//      PrintCenteredMessage
//		max
//		InitializeLCSLenTable
//------------------------------------------------------------------------------
#ifndef HelperFunctions_h
#define HelperFunctions_h

#include "Main.h"

//------------------------------------------------------------------------------
//PrintDivider: Outputs a divider line to a designated location
//--------------------------------------
//	fout:
//		Output file stream object that sends output to the opened output file
//	length:
//		Length that the divider will be printed as
//	character:
//		Character that the divider will be consisted of
//------------------------------------------------------------------------------
void PrintDivider(ofstream& fout, int length, char character);

//------------------------------------------------------------------------------
//PrintCenteredMessage: Outputs a centered message to a designated location
//--------------------------------------
//	fout:
//		Output file stream object that sends output to the opened output file
//	message:
//		String message that will be centered on the given width
//	centerWidth:
//		Width that the given message will be centered over
//------------------------------------------------------------------------------
void PrintCenteredMessage(ofstream& fout, string message, int centerWidth);

//------------------------------------------------------------------------------
//max: If a is greater than b then return a, else return b
//--------------------------------------
//	a:
//		First value that will be compared by
//	b:
//		Second value that will be compared to
//------------------------------------------------------------------------------
int max(int a, int b);

//------------------------------------------------------------------------------
//InitializeLCSLenTable: Initializes the first row and column to 0 in the
//	longest common subsequence length table
//--------------------------------------
//	lengthTable:
//		2-dimensional vector of integers that holds the lengths of longest
//		common subsequences between two sequences
//	rows:
//		The number of rows within lengthTable
//	columns:
//		The number of columns within lengthTable
//------------------------------------------------------------------------------
void InitializeLCSLenTable(vector<vector<int>>& lengthTable,
	int rows, int columns);

#endif // !HelperFunctions_h
