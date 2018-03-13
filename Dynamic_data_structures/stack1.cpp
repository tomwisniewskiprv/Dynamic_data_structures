// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercises 1 , 3 , 4 , 11 - ele

#include "stack1.h"

void push(ele* &stos, int value) {

	ele *new_top = new ele;
	new_top->dane = value;
	new_top->nast = stos;

	stos = new_top;
}

int pop(ele* &stos) {
	if (stos) {
		ele *old_top = stos;
		int result = stos->dane;
		stos = stos->nast;
		delete old_top;

		return result;
	}
	else {
		cerr << "Stos jest pusty";
		return -1;
	}
}

int peek(ele* stos) {
	if (stos) {
		return stos->dane;
	}
	else {
		return -1;
	}
}

bool isEmpty(ele* stos) {
	return (!stos);
}

long rng(int range) {
	return rand() % range;
}

void testStack() {

	const int STACK_SIZE = 3;
	ele* stack = 0; // Inicjalizacja zmiennej stosu
	cout << "----------------------------------------------" << endl;
	cout << "Utworzenie pustego stosu." << endl;
	cout << stack << endl;

	// Zapelnienie stosu kolejnymi wartosciami
	cout << "----------------------------------------------" << endl;
	cout << "Dodanie funkcja PUSH " << STACK_SIZE << " elementow." << endl;

	for (int i = 0; i < STACK_SIZE; i++) {
		push(stack, i);
		cout << peek(stack) << " " << stack->nast << " (peek at top)" << endl;
	}
	cout << endl;

	// Zdjecie elementow ze stosu
	cout << "----------------------------------------------" << endl;
	cout << "Proba zdjecia funkcja POP " << STACK_SIZE + 1 << " elementow." << endl;

	for (int i = 1; i < STACK_SIZE + 1; i++) {
		cout << setw(3) << pop(stack) << " (pop) | ";
		cout << setw(3) << peek(stack) << " (peek at top) ";
		cout << "is empty : " << (isEmpty(stack) ? "true" : "false") << endl;
	}

	// Exercise 11
	// Usuniecie wszystkich elementow na stosie oraz usuniecie obiektu stosu
	destroy_stack(stack);
}

// Exercise 3 , 4 - ele commands
void stack_commands(string str) {

	ele* stack = new ele;

	for (int i = 0; i < (int)str.size(); i++) {
		if (str[i] == '*') {
			cout << char(pop(stack)) << " ";
		}
		else if (str[i] >= 65 && str[i] <= 90) {
			push(stack, str[i]);
		}
	}
	cout << endl;
}

// Exercise 11
void destroy_stack(ele* &stos) {

	while (stos) {
		cout << pop(stos) << endl;
	}
	delete stos;
	cout << "==============================================" << endl;
	cout << "Zadanie 11:" << endl;
	cout << "Stos wyczyszczony i usuniety. " << stos << endl;
	cout << "==============================================" << endl;

}


