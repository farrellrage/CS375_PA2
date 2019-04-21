#include "Main.h"
#include "ItemClass.h"
#include "HelperFunctions.h"
#include "BestFirstSearch.h"

int main(int argc, char **argv)
{
	//Int to hold the number of items read from the input file
	int problemSize = 0;
	
	//Int to hold the total weight limit
	int capacity = 0;
	
	//Holds the weight of the current item
	int weight;
	
	//Holds the value of the current item
	int profit;
	
	//String to hold the names of the input text file
	string inputFileName;
	
	//String to hold the name of the output file
	string outputFileName;
	
	//Input file stream object
	ifstream fin;
	
	//Output file stream object
	ofstream fout;
	
	//Item object to hold input data from the input file and add the data to
	//the items list
	Item newItem;
	
	//Vector to hold Item objects
	vector<Item> items;
	
	//Determine whether the correct number of arguments was passed to the
	//program
	if (argc != 3)
	{
		//Output an error message to the console
		cout << "Error - Invalid number of arguments" << endl
			<< "Arguments must be: " << argv[0]
			<< " <input.txt> <output.txt>" << endl;

		return 1;
	} // !if
	
	//Open input/output files---------------------------------------------------
	//Get the file names from the program arguments
	inputFileName = argv[1];
	outputFileName = argv[2];

	//Open the files
	fin.open(inputFileName);
	fout.open(outputFileName);
	
	//Get input from input file-------------------------------------------------
	
	//Get the first line from the input file
	ParseBestFirstSearchInputLine(fin, problemSize, capacity);
	
	//Determine whether there is data in the input file
	if (!fin.eof())
	{
		//While there is input in the input file
		while (!fin.eof())
		{
			//Get the next item's weight and profit
			ParseBestFirstSearchInputLine(fin, weight, profit);
			
			//Save the next item's information in a temp Item
			newItem.SetWeight(weight);
			newItem.SetProfit(profit);
			newItem.SetRatio();
			
			//Add the Item to the vector
			items.push_back(newItem);
		} // !while
	} // !if
	else
	{
		return 1;
	} // !else
	
	std::sort(items.begin(), items.end(), greater<Item>());
	
	BestFirstSearchBrandBound(items, problemSize, capacity, fout);

	//Close the input and output files
	fin.close();
	fout.close();
} // !main