#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "node.h"
#include "list.h"
#include "randomInt.h"

using namespace std;

// Zwraca ilosc elementow w liscie, czyli dlugosc
int listSize(Node* &list) {
	Node *tmp = list;
	int size = 0;

	while (tmp != nullptr) {
		size++;
		tmp = tmp->next;
	}

	delete tmp;
	return size;
}

// Wstawienie elementu x pomiedzy elementami ai-1 oraz ai
// x - wstawiany element
// i - indeks elementu , min = 1
// list - lista
void insert(int x, int i, Node* &list) {

	Node *tmp = new Node;
	tmp->item = x;
	tmp->next = nullptr;

	if (list == nullptr) {
		list = tmp;
	}
	else {
		Node *current = list;
		int element = 1;

		while ((element + 1) < i) {
			current = current->next;
			element++;
		}

		tmp->next = current->next;
		current->next = tmp;
	}
}

// Usuwa element o indeksie i
void remove(int i, Node* &list) {

	Node *current = list;
	Node *tmp = list;
	int element = 1;

	if (i == element) {
		list = current->next;
		delete tmp;
		tmp = nullptr;
	}
	else {

		while ((element + 1) < i) {
			current = current->next;
			element++;
		}

		tmp = current->next;
		current->next = tmp->next;
		delete tmp;
	}

}

// Odczytuje element o indeksie i bez usuwania
// zwraca -1 jezeli proba odczytu nastapi do indeksu poza tablica
int read(int i, Node *list) {
	Node *current = list;
	int element = 1;

	while (element != i && current != nullptr) {
		element++;
		current = current->next;
	}

	if (current)
		return current->item;
	else
		return -1;
}

// Zwrócenie wskaŸnika do elementu listy zawieraj¹cego w polu ''dane'' wartoœæ x
Node *search(int x, Node *list) {

	Node *node = list;

	while (node) {
		if (node->item == x) {
			return node;
		}
		node = node->next;
	}

	return nullptr;
}

// Wypisuje wszystkie elementy listy
void print(Node* list) {
	Node *node = list;

	while (node) {
		cout << node->item << " ";
		node = node->next;
	}
	cout << endl;

	delete node;
}


void listEx1() {

	Node *list = nullptr;
	Node *list2 = nullptr;

	for (int i = 1; i < 10; i++) {
		insert(i, 1, list);
	}

	cout << "List size before remove: " << listSize(list) << endl;
	remove(4, list);
	cout << "List size after  remove: " << listSize(list) << endl;
	cout << "Element on 2 position  : " << read(2, list) << endl;

	Node *element4 = search(4, list);
	cout << "Found element with value 4 : " << element4->item << endl;

	cout << "Test of print function: " << endl;
	print(list);

	delete element4;
}
