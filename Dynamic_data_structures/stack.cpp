// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercises 1 , 3 , 4 , 5 , 10 , 11 

#include "stack.h"
#include "queue.h"

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
	ele* stack = nullptr; // Inicjalizacja zmiennej stosu
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

	cout << "----------------------------------------------" << endl;
	cout << "Zliczenie elementow na stosie :" << countStackElements(stack) << endl;

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

//============================================== 
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

// ==============================================
// Exercise  5

struct s2q {
	ele* sIn = nullptr;
	ele* sOut = nullptr;
};


// adds new value at the end (push @ end)
void s2qEnqueue(s2q* &que, int value) {
	push(que->sIn, value);
}

// returns first value in queue (pop @ front)
int  s2qDequeue(s2q* &que) {

	if (que->sOut)
		return pop(que->sOut);
	else {
		while (que->sIn) {
			push(que->sOut, pop(que->sIn));
		}
		return pop(que->sOut);
	}

}

void stacks2queue() {

	s2q *s2queue = new s2q;
	const int STACK_SIZE = 5;

	cout << "Zapelnianie kolejki zlozonej z dwoch stosow " << STACK_SIZE << " kolejnymi wartosciami." << endl;

	for (int i = 0; i < STACK_SIZE; i++) {
		s2qEnqueue(s2queue, i);
	}

	cout << "Peek at sIn : " << peek(s2queue->sIn) << endl;
	cout << "Proba zdjecia z kolejki zlozonej z dwoch stosow wiekszej liczby elementow." << endl;

	for (int i = 0; i < STACK_SIZE + 2; i++) {
		cout << s2qDequeue(s2queue) << " ";
	}
	cout << endl;
}

//============================================== 
// Exercise  10
long countStackElements(ele* &stos) {

	ele* ptr = new ele;
	ptr = stos;
	long counter = 0;

	while (stos) {
		++counter;
		stos = stos->nast;
	}

	return counter;
}


//============================================== 
// Exercise 11
void destroy_stack(ele* &stos) {

	while (stos) {
		cout << pop(stos) << endl;
	}
	cout << "==============================================" << endl;
	cout << "Zadanie 11:" << endl;
	cout << "Stos wyczyszczony i usuniety. " << stos << endl;
	cout << "==============================================" << endl;

}

//============================================== 
// Exercise 7
void ex7() {
	bool success = 0;

	const int STACK_SIZE = 5;
	ele* stack = nullptr; // Inicjalizacja zmiennej stosu
	ele* stack2 = nullptr;

	ele *head = nullptr;  // Inicjalizacja kolejki
	ele *tail = nullptr;

	cout << "Stack1 i Stack2:\n";
	for (int i = 0; i < STACK_SIZE; i++) {
		push(stack, i);
		push(stack2, i);
		cout << peek(stack) << " " << stack->nast << " (peek at top)" << endl;
	}
	cout << endl;

	// 7B - odwrocenie elementow za pomoca kolejki
	while (!isEmpty(stack)) {
		add(head, tail, pop(stack));
	}

	while (!isEmptyQ(head)) {
		push(stack, next(head, tail, success));
	}

	cout << endl;

	// 7A Odwrocenie za pomoca stosu - przepiecie na inny stos ;)
	cout << "7A Odwrocenie za pomoca stosu - przepiecie na inny stos ;)" << endl;
	while (stack)
		pop(stack);

	while (!isEmpty(stack2)) {
		push(stack, pop(stack2));
		cout << peek(stack) << " ";
	}

	stack2 = stack;

	cout << "\nStack2 po odwroceniu: " << endl;
	while (stack2)
		cout << pop(stack2) << " ";
	cout << endl;

}
