all:	task1 task2 task3 test1 test2 test3

task1:	Task1_main.cpp Main.h LCS_BottomUp.cpp LCS_BottomUp.h HelperFunctions.cpp HelperFunctions.h
	g++ -g -Wall -o task1 Task1_main.cpp Main.h LCS_BottomUp.cpp LCS_BottomUp.h HelperFunctions.cpp HelperFunctions.h

BestFirstSearch:	
	g++ -g -Wall -o BestFirstSearch 
	
HelperFunctions.o:	HelperFunctions.cpp HelperFunctions.h Main.h
	g++ -g -Wall -o HelperFunctions.cpp HelperFunctions.h HelperFunctions.o
	
test1:
	./task1 filex.txt filey.txt output1.txt

clean:
	-rm BestFirstSearch
