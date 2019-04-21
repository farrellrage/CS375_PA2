//------------------------------------------------------------------------------
Best-First-Search Branch and Bound
//------------------------------------------------------------------------------
This guide assumes the user has a terminal open in the program directory.
All programs use "makefile" for compilation.
//------------------------------------------------------------------------------
> To compile the program, run the command "make".
> The program reads data from "input.txt" by default; open this file to change
	the input.
> NOTE: This program assumes that each line of the input file contains two
	numbers separated by a comma with no space characters.
	Line 1 of the input file represents the number of items in the file and the
	maximum capacity of the knapsack.
	Every other line is treated as an item, with the numbers representing 
	weight and profit respectively
> To run the program, execute the command "make test".
> This program sends output to "output.txt".
	Line 1 holds the problem size, the optimal value, and the number of items
	in the optimal solution.
	Line 2 holds the total number of nodes visited and the total number of leaf
	nodes visited.
	Every other line lists each item in the solution as a weight and profit.
> Alternatively the program can be run by executing the command
	"./BestFirstSearch INPUTFILE OUTPUTFILE", where INPUTFILE is some other file
	that follows the input file format listed above, and OUTPUTFILE is any text
	file that can be written to.
//------------------------------------------------------------------------------
Component Files:
Source Files:
	Main.cpp
	BestFirstSearch.cpp
	ItemClass.cpp
	HelperFunctions.cpp
Header Files:
	Main.h
	BestFirstSearch.h
	ItemClass.h
	HelperFunctions.h
//------------------------------------------------------------------------------

Important Functions:

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
//Bound: Finds the possible profit of a given node.
//--------------------------------------
//	root:
//		Node to start searching the subtree at
//	capacity:
//		Maximum capacity of the problem
//	items:
//		Vector containing the items
//	length:
//		Length of the items vector
//------------------------------------------------------------------------------
//BestFirstSearchBrandBound: Finds the optimal solution to the best-first-search
//	bound and branch problem based on the items in the items vector.
//--------------------------------------
//	items:
//		Vector containing the items
//	problemSize:
//		First value taken from the input file
//		Returned to the caller
//	capacity:
//		Maximum capacity of the problem
//	fout:
//		Output file stream object to send all output to
//------------------------------------------------------------------------------