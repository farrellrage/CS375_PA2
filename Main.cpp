#include "Main.h"
#include "HelperFunctions.h"
#include "BestFirstSearch.h"

int main(int argc, char **argv)
{
	//String to hold the names of the input text file
	string inputFileName;
	
	//String to hold the name of the output file
	string outputFileName;
	
	//Input file stream object
	ifstream fin;
	
	//Output file stream object
	ofstream fout;
	
	//Determine whether the correct number of arguments was passed to the
	//program
	if (argc != 3)
	{
		//Output an error message to the console
		cout << "Error - Invalid number of arguments" << endl
			<< "Arguments must be: " << argv[0]
			<< " <input.txt> <output.txt>" << endl;

		return -1;
	} // !if
	
	//Open input/output files---------------------------------------------------
	//Get the file names from the program arguments
	inputFileName = argv[1];
	outputFileName = argv[2];

	//Open the files
	fin.open(inputFileName);
	fout.open(outputFileName);
	
	
	
	
	
	
	//Close the input and output files
	fin.close();
	fout.close();
} // !main