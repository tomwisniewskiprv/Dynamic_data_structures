// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercises 1 , 3 , 4 , 11 - Stack and Queue

#include "stack1.h"
#include "queue1.h"

int main() {
	srand(time(nullptr));

	string commands = "EAS*Y*QUE***ST***IO*N***";
	string commands2 = "EA*S*Y**";
	
	//ex1 , 11
	cout << "==============================================" << endl;
	cout << "Zadanie 1 , 11:" << endl;
	testStack();
	
	//ex2 , 12
	cout << "==============================================" << endl;
	cout << "Zadanie 2 , 12:" << endl;
	testQueue();

	//ex 13
	cout << "==============================================" << endl;
	cout << "Zadanie 13:" << endl;
	testQueueE13();

	//ex3
	cout << "==============================================" << endl;
	cout << "Zadanie 3:" << endl;
	stack_commands(commands);

	//ex4
	cout << "==============================================" << endl;
	cout << "Zadanie 4:" << endl;
	stack_commands(commands2);

	system("pause");
	return 0;
}