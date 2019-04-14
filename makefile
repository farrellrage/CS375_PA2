all:	task1 task2 task3 test1 test2 test3

tasks:	task1 task2 task3

task1:	Task1_main.cpp Main.h LCS_BottomUp.cpp LCS_BottomUp.h HelperFunctions.cpp HelperFunctions.h
	g++ -g -Wall -o task1 Task1_main.cpp Main.h LCS_BottomUp.cpp LCS_BottomUp.h HelperFunctions.cpp HelperFunctions.h

task2:	Task2_main.cpp Main.h LCS_RecursiveNoMemoization.cpp LCS_RecursiveNoMemoization.h HelperFunctions.cpp HelperFunctions.h
	g++ -g -Wall -o task2 Task2_main.cpp Main.h LCS_RecursiveNoMemoization.cpp LCS_RecursiveNoMemoization.h HelperFunctions.cpp HelperFunctions.h

task3:	Task3_main.cpp Main.h LCS_TopDown.cpp LCS_TopDown.h HelperFunctions.cpp HelperFunctions.h
	g++ -g -Wall -o task3 Task3_main.cpp Main.h LCS_TopDown.cpp LCS_TopDown.h HelperFunctions.cpp HelperFunctions.h

tests:	test1 test2 test3
	
test1:
	./task1 filex.txt filey.txt output1.txt

test2:
	./task2 filex.txt filey.txt output2.txt

test3:
	./task3 filex.txt filey.txt output3.txt

clean:
	-rm task1 task2 task3
