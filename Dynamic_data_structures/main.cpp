// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Solutions for exercises:
// 1 , 2 , 3 , 4 , 5 , 6 , 10 , 11 , 12 , 13 - Stack and Queue

/* 
g++ notes:
there are two stages to create exetutable:

1)
- compile source to object files
	g++ main.cpp list1.cpp queue1.cpp stack1.cpp -o output

- link object files together to form an executable
	g++ *.o -o executable

2) or shorter :
	g++ *.cpp -o output
	
	should create output.exe

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "stack.h"
#include "queue.h"
#include "list.h"
#include "randomInt.h"
using namespace std;

void executeStackAndQueues() {

	string commands = "EAS*Y*QUE***ST***IO*N***";
	string commands2 = "EA*S*Y**";
	
	//ex 1 , 10 , 11
	cout << "==============================================" << endl;
	cout << "Zadanie 1 , 11:" << endl;
	testStack();
	
	//ex 2 , 12
	cout << "==============================================" << endl;
	cout << "Zadanie 2 , 12:" << endl;
	testQueue();

	//ex 13
	cout << "==============================================" << endl;
	cout << "Zadanie 13:" << endl;
	testQueueE13();

	//ex 3
	cout << "==============================================" << endl;
	cout << "Zadanie 3:" << endl;
	stackCommands(commands);

	//ex 4
	cout << "==============================================" << endl;
	cout << "Zadanie 4:" << endl;
	stackCommands(commands2);

	//ex 5
	cout << "==============================================" << endl;
	cout << "Zadanie 5:" << endl;
	stacks2queue();

	//ex 6
	cout << "==============================================" << endl;
	cout << "Zadanie 6:" << endl;
	staticQueue();

	//ex 7
	cout << "==============================================" << endl;
	cout << "Zadanie 7:" << endl;
	ex7();
}
void executeLists() {
	listEx1();
}

// Program entry point
int main() {
	srand((unsigned int)time(nullptr));

	//executeStackAndQueues();
	executeLists();





	system("pause");
	return 0;
}