// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercise 2 , 6 , 12 , 13 - Queue 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "queue.h"


// enqueue
// dodanie Nodementu do kolejki
void enqueue(Node* &front, Node* &rear, int x) {

	Node *tmp = new Node;
	tmp->item = x;
	tmp->next = nullptr;

	if (front == nullptr)
		front = rear = tmp;

	else {
		rear->next = tmp;
		rear = tmp;
	}
}

// dequeue
// pobranie pierwszego Nodementu kolejki i zwrócenie go jako wartoœci funkcji
/*
	Funkcja pobiera item z poczatku kolejki oraz kasuje obiekt po zaczytaniu danych.
	Jezeli napotka koniec to po zwroceniu danych zwolni pamiec zarowno poczatku jak i konca kolejki,
	zwracajac kolejke w stan pusty, jak bezposrednio po utworzeniu.

*/
int dequeue(Node* &front, Node* &rear, bool &success) {

	if (front) { 
		int data = front->item;
		Node *tmp = new Node;
		tmp = front;
		front = front->next;
		delete tmp;
		return data;
	}
	else {
		success = 0;
		return  -1;
	}
}

// zwrócenie (wartoœci) Nodementu z pocz¹tku kolejki bez jego usuwania
int firstEl(Node* front) {

	if (front) {
		return front->item;
	}
	else {
		cout << "Kolejka jest pusta." << endl;
		return 0;
	}
}

// sprawdzenie czy kolejka jest pusta
bool isEmptyQ(Node* front) {
	return (!front);
}

// Exercise 12
void testQueue() {

	const int QUEUE_MAX = 5;
	const int ADD_ELEMENTS = 5;

	Node *head = nullptr;
	Node *tail = nullptr;
	bool success = 0;

	// Zapelnienie kolejki wartosciami
	cout << "Zapelnienie kolejki " << QUEUE_MAX << " wartosciami." << endl;
	for (int i = 0; i < QUEUE_MAX; i++) {
		enqueue(head, tail, i);
	}

	// Sprawdzenie czy kolejka jest pusta
	cout << (isEmptyQ(head) ? "Kolejka jest pusta." : "Kolejka nie jest pusta.") << endl;

	// Zdjecie z kolejki wiekszej ilosci Nodementow niz jest zainicjalizowanych 
	cout << "Zdjecie z kolejki wiekszej ilosci Nodementow niz jest zainicjalizowanych." << endl;
	for (int i = 0; i < QUEUE_MAX + 2; i++) {
		cout << dequeue(head, tail, success) << " ";
	}
	cout << endl;

	// Sprawdzenie czy kolejka jest pusta
	cout << (isEmptyQ(head) ? "Kolejka jest pusta." : "Kolejka nie jest pusta.") << endl;

	// Exercise 12
	cout << "==============================================" << endl;
	cout << "Zadanie 12:" << endl;

	head = nullptr;
	tail = nullptr;

	Node *head2 = nullptr;
	Node *tail2 = nullptr;

	cout << "Zapelnienie kolejek " << QUEUE_MAX + ADD_ELEMENTS << " wartosciami." << endl;
	for (int i = 0; i < QUEUE_MAX; i++) {
		enqueue(head, tail, i);
		enqueue(head2, tail2, i + ADD_ELEMENTS);
	}

	joinQueues(head, tail, head2, tail2);

	cout << "Zdjecie z polaczonej kolejki wszystich Nodementow." << endl;
	for (int i = 0; i < QUEUE_MAX + ADD_ELEMENTS; i++) {
		cout << dequeue(head, tail,success) << " ";
	}
	cout << endl;

	cout << "==============================================" << endl;

}


// Exercise 12
/*
	Funkcja pobiera poczatki oraz konce kolejek wybranych do polaczenia w jedna.
	Funkcja polaczy kolejke pierwsza oraz druga usuwajac wskazniki poczatku i konca drugiej kolejki.
	Rezultatem polaczenia bedzie jedna kolejka zaczynajaca sie w poczatku pierwszej poitemj i konczonca
	sie na wskazniku pierwszej poitemj.

*/
void joinQueues(Node* &front, Node* &rear, Node* &frontNext, Node* &rearNext) {

	Node *last = new Node;
	Node *prev = new Node;
	Node *join = new Node;
	last = front;

	// znajduje przed ostatni i ostatni Nodement w kolejce
	while (last->next) {
		prev = last;
		last = last->next;
	}

	// tworzy obietk laczacy kolejke 1 z kolejka druga
	prev->next = last;
	join->item = frontNext->item;
	join->next = frontNext->next;
	last->next = join;

	// znajduje przed ostatni i ostatni Nodement w kolejce
	Node *newEnd = new Node;
	newEnd->next = frontNext->next;
	delete frontNext;

	// znajduje przed ostatni i ostatni Nodement w drugiej kolejce
	while (newEnd->next) {
		prev = newEnd;
		newEnd = newEnd->next;
	}
	// przepina koniec drugiej kolejki na koniec pierwszej
	// oraz zwalnia pamiec z obiektu drugiej kolejki
	rear = newEnd;
	prev->next = rear;

	rearNext = nullptr; // konieczne wywolanie w tej kolejnosci, w celu wyzerowania wskazywanego obiektu
	delete rearNext;
}


// Exercise 13
void testQueueE13() {
	bool success = 0;

	const int QUEUE_MAX = 5;
	const int ADD_ELEMENTS = 5;

	Node *head = nullptr;
	Node *tail = nullptr;

	// Zapelnienie kolejki wartosciami
	cout << "Zapelnienie kolejki " << QUEUE_MAX << " wartosciami." << endl;
	for (int i = 0; i < QUEUE_MAX; i++) {
		enqueue(head, tail, i);
	}

	reverseQueue(head, tail);

	cout << "Zdjecie Nodemntow z odwroconej kolejki." << endl;
	for (int i = 0; i < QUEUE_MAX + ADD_ELEMENTS; i++) {
		cout << dequeue(head, tail , success) << " ";
	}
	cout << endl;
}

// Zapisz funkcjê odwracaj¹c¹ porz¹dek w kolejce.
void reverseQueue(Node* &front, Node* &rear) {

	Node *current = new Node;
	Node *prev = new Node;

	Node *newHead = rear;
	Node *newEnd = front;

	current = front;

	while (front->next) {

		while (current->next) {
			prev = current;
			current = current->next;
		}

		prev->next = nullptr;
		current->next = prev;
		current = front;
	}

	front = newHead;
	rear = newEnd;

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
int staticEnqueue(stQueue *que, int value) {

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
int staticDequeue(stQueue *que) {
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
