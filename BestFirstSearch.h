#ifndef BestFirstSearch_h
#define BestFirstSearch_h

#include "Main.h"
#include "HelperFunctions.h"
#include "ItemClass.h"

struct Node
{
	//Level of node in decision tree
	int level;
	
	//Weight of all nodes on the path from the root to this node
	int weight;
	
	//Profit from all nodes on the path from the root to this node
	int profit;
	
	//Upper bound of the max profit in the subtree of this node
	int bound;
	
	//Vector holding predecessor nodes
	vector<int> prev;
	
	//Custom operator for priority queue use
	bool operator<(const Node& other) const
	{
		return (bound < other.bound);
	}
}; // !Node

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
int Bound(Node root, int capacity, vector<Item>& items, int length);

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
void BestFirstSearchBrandBound(vector<Item>& items, int problemSize,
	int capacity, ofstream& fout);

#endif // !BestFirstSearch_h
