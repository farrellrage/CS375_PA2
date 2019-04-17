all:	Main

Main:	Main.cpp Main.h BestFirstSearch.cpp BestFirstSearch.h HelperFunctions.cpp HelperFunctions.h
	g++ -g -Wall -o BestFirstSearch Main.cpp BestFirstSearch.cpp HelperFunctions.cpp
	
BestFirstSearch.o:	BestFirstSearch.cpp BestFirstSearch.h Main.h HelperFunctions.o
	g++ -g -Wall -c BestFirstSearch.cpp
	
HelperFunctions.o:	HelperFunctions.cpp HelperFunctions.h Main.h
	g++ -g -Wall -c HelperFunctions.cpp
	
test1:
	./task1 filex.txt filey.txt output1.txt

clean:
	rm BestFirstSearch *.o
