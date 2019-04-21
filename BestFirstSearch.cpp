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
int Bound(Node root, int capacity, vector<Item>& items, int length)
{
	//The bound for the possible profit from this subtree
	int profitBound;
	
	//Levels of the subtree to explore, starting with the next level after
	//the root's level
	int subLevel;
	
	//Total weight from including nodes from this subtree
	int totalWeight;
	
	//Determine whether the weight of the node exceeds the capacity
	if (root.weight >= capacity)
	{
		//This item cannot be added to the knapsack
		//Return 0 profit
		return 0;
	} // !if
	else
	{
		//Bound on the root's value
		profitBound = root.profit;
		
		//Get the next tree level
		subLevel = root.level;
		
		//Initialize the total weight with the weight of the root node
		totalWeight = root.weight;
		
		//While the end of the subtree has not been reached and the total weight of
		//including items has not exceeded the capacity
		while ((subLevel < length) &&
			((totalWeight + items[subLevel].GetWeight()) <= capacity))
		{
			//Accumulate the total weight by adding the current item
			totalWeight += items[subLevel].GetWeight();
			
			//Accumulate the profit bound by adding the current item
			profitBound += items[subLevel].GetProfit();
			
			//Increment the tree level to go to the next item
			subLevel++;
		} //!while
		
		//If there is still an unadded item, include it partially to the bound
		if (subLevel < length)
		{
			profitBound += ((capacity - totalWeight) *
				(items[subLevel].GetProfit() / items[subLevel].GetWeight()));
		} // !if
		
		return profitBound;
	} // !else
} // !Bound

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
	int capacity, ofstream& fout)
{
	
	int solutionSize = 0;	//Size of the optimal solution
	int visited = 1;	//Number of nodes visited in the algorithm
	int leaves = 0;		//Number of leaf nodes visited in the algorithm
	int maxProfit = 0;	//Holds the max profit possible
	
	priority_queue<Node> Q;		//Holds the nodes to process
	
	vector<int> solution;	//Holds the items in the optimal solution
	
	Node current;	//Node that gets popped off the queue
	Node next;		//Node that gets pushed onto the queue
	
	//Initialize the first node to be put on the queue
	current.level = 0;
	current.profit = 0;
	current.weight = 0;
	current.prev.resize(problemSize + 1, 0);
	next.prev.resize(problemSize + 1, 0);
	current.bound = Bound(current, capacity, items, problemSize);
	
	//Push the first node onto the queue
	Q.push(current);
	
	//While the queue is not empty
	while (!Q.empty())
	{
		//Pop the next node off the queue
		current = Q.top();
		Q.pop();
		
		//Determine whether the current node's profit bound is greater than the
		//current maximum possible profit
		if (current.bound > maxProfit)
		{
			//Accumulate the number of visited nodes, one for the current and
			//next node
			visited += 2;
			
			//Set the next node's level
			next.level = current.level + 1;
			
			//////////////////////////////////////////////
			//Calculations for if we include the next node
			//////////////////////////////////////////////
			
			//Set the next node's weight and profit
			next.weight = current.weight + items[next.level - 1].GetWeight();
			next.profit = current.profit + items[next.level - 1].GetProfit();
			
			//Copy the previous solution information to the next node
			next.prev = current.prev;
			next.prev.at(next.level-1) = 1;
			
			//Determine whether the next node's weight fits in the capacity and
			//its profit exceeds the current max
			if ((next.weight <= capacity) && (next.profit > maxProfit))
			{
				//Update the current max profit
				maxProfit = next.profit;
				
				//Update the optimal solution
				solution = next.prev;
			} // !if
			
			//Find the next node's upper bound
			next.bound = Bound(next, capacity, items, problemSize);
			
			//Determine whether the potential profit of the next node is greater
			//than the current max profit and its weight fits in capacity
			if ((next.bound > maxProfit) && (next.weight < capacity))
			{
				//Push the next node onto the queue
				Q.push(next);
			} // !if
			else
			{
				//We have encountered a leaf node
				leaves++;
			} //!if
			
			//////////////////////////////////////////////
			//Calculations for if we exclude the next node
			//////////////////////////////////////////////
			
			//Set the next node's weight and profit
			next.weight = current.weight;
			next.profit = current.profit;
			
			//Copy the previous solution information to the next node
			next.prev.at(next.level - 1) = 0;
			next.bound = Bound(next, capacity, items, problemSize);
			
			//Determine whether the potential profit of the next node is greater
			//than the current max profit and its weight fits in capacity
			if ((next.bound > maxProfit) && (next.weight < capacity))
			{
				//Push the next node onto the queue
				Q.push(next);
			} // !if
			else
			{
				//We have encountered a leaf node
				leaves++;
			} // !else
		} // !if
		else
		{
			//We have encountered a leaf node
			leaves++;
		} // !else
	} // !while
	
	//Find the number of items in the solution
	for (unsigned int i = 0; i < solution.size(); i++)
	{
		if (solution.at(i) == 1)
		{
			solutionSize++;
		} // !if
	} // !for
	
	//Output solution information to the output file
	fout << problemSize << ',' << maxProfit << ',' << solutionSize << endl
		<< visited << ',' << leaves << endl;
	
	//Output each item in the solution to the output file
	for (unsigned int i = 0; i < solution.size(); i++)
	{
		if (solution.at(i) == 1)
		{
			fout << items[i].GetWeight() << ',' << items[i].GetProfit() << endl;
		} // !if
	} // !for	
} // !BestFirstSearchBrandBound