all:	Main

Main:	Main.cpp Main.h BestFirstSearch.o ItemClass.o HelperFunctions.o
	g++ -g -Wall -o BestFirstSearch Main.cpp BestFirstSearch.o ItemClass.o HelperFunctions.o
	
BestFirstSearch.o:	BestFirstSearch.cpp BestFirstSearch.h Main.h HelperFunctions.o
	g++ -g -Wall -c BestFirstSearch.cpp
	
ItemClass.o:	ItemClass.cpp ItemClass.h Main.h
	g++ -g -Wall -c ItemClass.cpp
	
HelperFunctions.o:	HelperFunctions.cpp HelperFunctions.h Main.h
	g++ -g -Wall -c HelperFunctions.cpp
	
test1:
	./task1 filex.txt filey.txt output1.txt

clean:
	-rm BestFirstSearch *.o
