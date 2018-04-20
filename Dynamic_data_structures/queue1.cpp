// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercise 2 , 6 , 12 , 13 - Queue 

#include "queue1.h"


// dodanie elementu do kolejki
void add(ele* &poczkol, ele* &konkol, int x) {

	ele* nowy = new ele;
	nowy->dane = x;
	nowy->nast = nullptr;

	if (poczkol == nullptr)
		poczkol = konkol = nowy;

	else {
		konkol->nast = nowy;
		konkol = nowy;
	}
}

// pobranie pierwszego elementu kolejki i zwrócenie go jako wartoœci funkcji
/*
	Funkcja pobiera dane z poczatku kolejki oraz kasuje obiekt po zaczytaniu danych.
	Jezeli napotka koniec to po zwroceniu danych zwolni pamiec zarowno poczatku jak i konca kolejki,
	zwracajac kolejke w stan pusty, jak bezposrednio po utworzeniu.

*/
int next(ele* &poczkol, ele* &konkol, bool &sukces) {

	if (poczkol) { 
		int data = poczkol->dane;
		ele *tmp = new ele;
		tmp = poczkol;
		poczkol = poczkol->nast;
		delete tmp;
		return data;
	}
	else {
		sukces = 0;
		return  -1;
	}
}

// zwrócenie (wartoœci) elementu z pocz¹tku kolejki bez jego usuwania
int firstEl(ele* poczkol) {

	if (poczkol) {
		return poczkol->dane;
	}
	else {
		cout << "Kolejka jest pusta." << endl;
		return 0;
	}
}

// sprawdzenie czy kolejka jest pusta
bool isEmptyQ(ele* poczkol) {
	return (!poczkol);
}

// Exercise 12
void testQueue() {

	const int QUEUE_MAX = 5;
	const int ADD_ELEMENTS = 5;

	ele *head = nullptr;
	ele *tail = nullptr;
	bool success = 0;

	// Zapelnienie kolejki wartosciami
	cout << "Zapelnienie kolejki " << QUEUE_MAX << " wartosciami." << endl;
	for (int i = 0; i < QUEUE_MAX; i++) {
		add(head, tail, i);
	}

	// Sprawdzenie czy kolejka jest pusta
	cout << (isEmptyQ(head) ? "Kolejka jest pusta." : "Kolejka nie jest pusta.") << endl;

	// Zdjecie z kolejki wiekszej ilosci elementow niz jest zainicjalizowanych 
	cout << "Zdjecie z kolejki wiekszej ilosci elementow niz jest zainicjalizowanych." << endl;
	for (int i = 0; i < QUEUE_MAX + 2; i++) {
		cout << next(head, tail, success) << " ";
	}
	cout << endl;

	// Sprawdzenie czy kolejka jest pusta
	cout << (isEmptyQ(head) ? "Kolejka jest pusta." : "Kolejka nie jest pusta.") << endl;

	// Exercise 12
	cout << "==============================================" << endl;
	cout << "Zadanie 12:" << endl;

	head = nullptr;
	tail = nullptr;

	ele *head2 = nullptr;
	ele *tail2 = nullptr;

	cout << "Zapelnienie kolejek " << QUEUE_MAX + ADD_ELEMENTS << " wartosciami." << endl;
	for (int i = 0; i < QUEUE_MAX; i++) {
		add(head, tail, i);
		add(head2, tail2, i + ADD_ELEMENTS);
	}

	joinQueues(head, tail, head2, tail2);

	cout << "Zdjecie z polaczonej kolejki wszystich elementow." << endl;
	for (int i = 0; i < QUEUE_MAX + ADD_ELEMENTS; i++) {
		cout << next(head, tail,success) << " ";
	}
	cout << endl;

	cout << "==============================================" << endl;

}


// Exercise 12
/*
	Funkcja pobiera poczatki oraz konce kolejek wybranych do polaczenia w jedna.
	Funkcja polaczy kolejke pierwsza oraz druga usuwajac wskazniki poczatku i konca drugiej kolejki.
	Rezultatem polaczenia bedzie jedna kolejka zaczynajaca sie w poczatku pierwszej podanej i konczonca
	sie na wskazniku pierwszej podanej.

*/
void joinQueues(ele* &poczkol, ele* &konkol, ele* &pocznast, ele* &konnast) {

	ele* last = new ele;
	ele* prev = new ele;
	ele* join = new ele;
	last = poczkol;

	// znajduje przed ostatni i ostatni element w kolejce
	while (last->nast) {
		prev = last;
		last = last->nast;
	}

	// tworzy obietk laczacy kolejke 1 z kolejka druga
	prev->nast = last;
	join->dane = pocznast->dane;
	join->nast = pocznast->nast;
	last->nast = join;

	// znajduje przed ostatni i ostatni element w kolejce
	ele* newEnd = new ele;
	newEnd->nast = pocznast->nast;
	delete pocznast;

	// znajduje przed ostatni i ostatni element w drugiej kolejce
	while (newEnd->nast) {
		prev = newEnd;
		newEnd = newEnd->nast;
	}
	// przepina koniec drugiej kolejki na koniec pierwszej
	// oraz zwalnia pamiec z obiektu drugiej kolejki
	konkol = newEnd;
	prev->nast = konkol;

	konnast = nullptr; // konieczne wywolanie w tej kolejnosci, w celu wyzerowania wskazywanego obiektu
	delete konnast;
}


// Exercise 13
void testQueueE13() {
	bool success = 0;

	const int QUEUE_MAX = 5;
	const int ADD_ELEMENTS = 5;

	ele *head = nullptr;
	ele *tail = nullptr;

	// Zapelnienie kolejki wartosciami
	cout << "Zapelnienie kolejki " << QUEUE_MAX << " wartosciami." << endl;
	for (int i = 0; i < QUEUE_MAX; i++) {
		add(head, tail, i);
	}

	reverseQueue(head, tail);

	cout << "Zdjecie elemntow z odwroconej kolejki." << endl;
	for (int i = 0; i < QUEUE_MAX + ADD_ELEMENTS; i++) {
		cout << next(head, tail , success) << " ";
	}
	cout << endl;
}

// Zapisz funkcjê odwracaj¹c¹ porz¹dek w kolejce.
void reverseQueue(ele* &poczkol, ele* &konkol) {

	ele* current = new ele;
	ele* prev = new ele;

	ele* newHead = konkol;
	ele* newEnd = poczkol;

	current = poczkol;

	while (poczkol->nast) {

		while (current->nast) {
			prev = current;
			current = current->nast;
		}

		prev->nast = nullptr;
		current->nast = prev;
		current = poczkol;
	}

	poczkol = newHead;
	konkol = newEnd;

	current = nullptr;
	prev = nullptr;
	newHead = nullptr;
	newEnd = nullptr;

	delete current;
	delete prev;
	delete newHead;
	delete newEnd;

}

// Exercise 6

// static queue
struct stQueue {

	static const int TAB_SIZE = 10;  // faktyczna pojemnoœæ tablicy rowna jest (tab_size - 1), poniewaz head jest zawsze pusty
	int data[TAB_SIZE];
	int head = 0, tail = 0;			 // wskazniki pozycji 
};

// dodanie na koncu, -1 kolejka pelna
int staticEnqueue(stQueue* que, int value) {

	if (que->head == que->tail) {
		if (que->tail + 1 < que->TAB_SIZE) {
			que->tail += 1;
			que->data[que->tail] = value;
			return value;
		}
		else if (que->head && que->tail + 1 == que->TAB_SIZE) {
			que->tail = 0;
			que->data[que->tail] = value;
			return value;
		}
		else return -1;
	}
	else if (que->tail + 1 != que->head && que->tail + 1 != que->TAB_SIZE) {
		que->tail += 1;
		que->data[que->tail] = value;

		return value;
	}
	else if (que->tail + 1 == que->head)
		return -1;
	else if (que->tail + 1 == que->TAB_SIZE) {
		if (que->head) {
			que->tail = 0;
			que->data[que->tail] = value;
			return value;
		}
		else
			return -1;
	}

	return -1;
}

// zdjecie z przodu , -2 kolejka pusta
int staticDequeue(stQueue* que) {
	if (que->head == que->tail)
		return -2;
	else if (que->head + 1 < que->TAB_SIZE) {
		que->head += 1;
		return que->data[que->head];
	}
	else {
		que->head = 0;
		return que->data[que->head];
	}
}


// testing staticQueue
void staticQueue() {

	stQueue queue;

	for (int i = 0; i < queue.TAB_SIZE; i++)
		cout << staticEnqueue(&queue, i) << " i=  " << i << endl;

	cout << endl;

	for (int i = 0; i < queue.TAB_SIZE ; i++)
		cout << staticDequeue(&queue) << " ";

	cout << endl;

	cout << queue.head << " " << queue.tail << endl; // h 9 t 9

		cout << staticEnqueue(&queue, 22) << " i=  " << 22 << endl;

	cout << queue.head << " " << queue.tail << endl; // h 9 t 0

		cout << staticDequeue(&queue) << " ";

	cout << queue.head << " " << queue.tail << endl; // h 0 t 0

	cout << endl;
}
