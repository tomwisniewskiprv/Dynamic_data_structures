// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercise 2 , 12 , 13 - Queue 

#include "queue1.h"


// dodanie elementu do kolejki
void add(ele* &poczkol, ele* &konkol, int x) {

	if (poczkol == nullptr && konkol == nullptr) {
		konkol = new ele;
		konkol->dane = x;
		konkol->nast = nullptr;
		poczkol = konkol;
	}
	else {
		ele *nowy = new ele;
		nowy->dane = x;
		nowy->nast = nullptr;
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
int next(ele* &poczkol, ele* &konkol) {

	if (poczkol) {

		if (poczkol == konkol) {
			int dane = konkol->dane;
			poczkol = konkol = nullptr;
			delete poczkol;
			delete konkol;

			return dane;
		}

		int dane = poczkol->dane;
		ele *p = poczkol;
		poczkol = p->nast;
		delete p;

		return dane;
	}
	else {
		return -1;
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
		cout << next(head, tail) << " ";
	}
	cout << endl;

	// Sprawdzenie czy kolejka jest pusta
	cout << (isEmptyQ(head) ? "Kolejka jest pusta." : "Kolejka nie jest pusta.") << endl;

	// Exercise 12
	cout << "==============================================" << endl;
	cout << "Zadanie 12:" << endl;

	delete head;
	delete tail;
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
		cout << next(head, tail) << " ";
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
		cout << next(head, tail) << " ";
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
