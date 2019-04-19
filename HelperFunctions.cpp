//------------------------------------------------------------------------------
//File Name:        HelperFunctions.cpp
//Associated file:  HelperFunctions.h
//Functions:
//      PrintDivider
//      PrintCenteredMessage
//		max
//		InitializeLCSLenTable
//		ParseBestFirstSearchInputLine
//------------------------------------------------------------------------------

#include "HelperFunctions.h"

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
void PrintDivider(ofstream& fout, int length, char character)
{
	// Output a divider line to the specified destination
	fout << setw(length) << setfill(character) << character << setfill(' ') << endl;
} // !PrintDivider

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
void PrintCenteredMessage(ofstream& fout, string message, int centerWidth)
{
	//Holds the value that will center the given message on the given width
	int centerOfScreen;

	// Calculate the center of the screen for the message
	centerOfScreen = static_cast<int>((centerWidth + message.length()) / 2);

	// Output the centered message to the specified destination
	fout << right << setw(centerOfScreen) << message << endl;
} // !PrintCenteredMessage

//------------------------------------------------------------------------------
//max: If a is greater than b then return a, else return b
//--------------------------------------
//	a:
//		First value that will be compared by
//	b:
//		Second value that will be compared to
//------------------------------------------------------------------------------
int max(int a, int b)
{
	return (a > b) ? a : b;
} // !max

//------------------------------------------------------------------------------
//InitializeLCSLenTable: Initializes the first row and column to 0 in the
//	longest common subsequence length table
//--------------------------------------
//	lengthTable:
//		2-dimensional vector of integers that holds the lengths of longest
//		common subsequences between two sequences
//	rows:
//		Integer number of rows within lengthTable
//	columns:
//		Integer number of columns within lengthTable
//------------------------------------------------------------------------------
void InitializeLCSLenTable(vector<vector<int>>& lengthTable,
	int rows, int columns)
{
	//Index for the FOR loops that zero out the first row and column
	int i;

	//Zero out the first row in the length table
	for (i = 0; i <= columns; i++)
	{
	lengthTable[0][i] = 0;
	} // !for
	
	//Zero out the first column in the length table
	for (i = 0; i <= rows; i++)
	{
	lengthTable[i][0] = 0;
	} // !for
} // !InitializeLCSLenTable