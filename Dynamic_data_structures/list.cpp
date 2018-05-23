// Dynamic Data Structures
// Tomasz Wisniewski 20.05.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercises 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 10 , 11 - Lists , part one

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "node.h"
#include "stack.h"
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

		if (i == 1) {
			tmp->next = current;
			list = tmp;
		}
		else {
			tmp->next = current->next;
			current->next = tmp;
		}
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

		while (current && (element + 1) < i) {
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

// Procedura usuwaj¹ca wszystkie elementy z listy
void destroy(Node* &list) {

	Node *current = nullptr ;
	while (list) {
		current = list;
		list = list->next;
		delete current;
	}
}

// Zwraca adres elementu k
long getAddres(int k, Node *list) {

	Node *current = list;
	int index = 1; // element index/ position in list

	while (index != k && current && listSize(list)) {
		current = current->next;
		index++;
	}
	
	return (long)current;
}

// Kopiuje liste na stos, a nastepnie z wyswieltla ja w odwrotnej kolejnosci
void reverseListUsingStack(Node *list) {

	Node *stack = nullptr;
	int value = 0;

	for (int i = 1; i <= listSize(list); i++) {
		value = read(i, list);
		if (value > -1)
			push(stack, value);
	}

	while (stack) {
		cout << pop(stack) << " ";
	}
	cout << endl;

	delete stack;
}

// Wypisuje wszystkie elementy listy w odwrotnej kolejnoœci
void reverseListWithoutStack(Node *list) {

	for (int i = listSize(list); i > 0; i--) {
		cout << read(i, list) << " ";
	}
	cout << endl;

}

// Tworzy nowa liste bedaca suma podanych list
// This strange function name is required ...
Node * UNION(Node *list1, Node *list2) {

	Node *newList = nullptr;
	Node *current = list1;
	int lastPosition = 1;

	for (int i = 1; i <= listSize(list1); i++) {
		insert(read(i, list1), i, newList);
		lastPosition++;
	}

	for (int i = lastPosition, j = 1; j <= listSize(list2) ; i++ , j++) {
		insert(read(j, list2), i, newList);
	}

	return newList;
}

// Zwraca wskaznik na element minimalny
Node *minimun(Node *list) {

	Node *node = list;
	Node *ptr = list;
	int min = -1;

	// lista musi nie byc pusta
	if (node) {
		min = node->item;
	} 
	else {
		return nullptr;
	}

	while (node) {
		if (node->item < min) {
			min = node->item;
			ptr = node;
		}
		node = node->next;
	}

	return ptr;
}

// Usuwa duplikaty
void removeDuplicates(Node *list) {

	Node *node = list;
	int position = 1, value = 0;
	int currentPosition = 0, currentValue = 0;
	int size = listSize(list);
	int removed = 0;

	while (position <= size) {
		value = read(position, list);
		currentPosition = position + 1;

		while (currentPosition <= size) {
			currentValue = read(currentPosition, list);
			if (value == currentValue) {
				removed++;
				remove(currentPosition, list);
				size--;
			}
			currentPosition++;
		}
		position++;
	}

	cout << "Removed objects: " << removed << endl;
}

// Exercises 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 10 , 11
void listFirstPart() {

	// 1 , 2 , 3 , 4
	// create new list
	Node *list = nullptr;

	for (int i = 1; i < 10; i++) {
		insert(i, 1, list);
	}

	cout << "List size before remove: " << listSize(list) << endl;
	remove(4, list);
	cout << "List size after  remove: " << listSize(list) << endl;
	cout << "test read():\t" << read(2, list) << endl;

	Node *element4 = search(4, list);
	cout << "test search():\t" << element4->item << endl;

    cout << "test print():\t";
	print(list);

	cout << "test destroy():\t";
	destroy(list); // this procedues also deallocs element4 memory
	cout << listSize(list) << " " << list << endl;

	// 5
	// create new list
	for (int i = 10; i >= 1; i--) {
		insert(i, 1, list);
		//insert(randomInt(90) + 1, 1, list);
	}
	cout << "New list:";
	print(list);
    cout << "test getAddres()" << endl;
	for (int i = -2; i < 12; i++)
		cout << i << " " << getAddres(i, list) << endl;

	// 6
    cout << "test reverseListUsingStack()" << endl;
	reverseListUsingStack(list);

	// 7 
    cout << "test reverseListWithoutStack()" << endl;
	reverseListWithoutStack(list);

	// 8
	Node *otherList = nullptr;
	for (int i = 1; i < 11; i++) {
		//insert(randomInt(90) + 10, i, otherList);
		insert(i + 10, i, otherList);
	}

	Node *combinedList = UNION(list, otherList);
	cout << "test UNION()" << endl;
	print(combinedList);

	// 10
	cout << "test minimum(): " << (int)minimun(combinedList)->item << endl;

	// 11
	cout << "test removeDuplicates(): " << endl;
	insert(555, 10, combinedList);
	insert(555, 15, combinedList);
	insert(555, 20, combinedList);
	insert(2, 20, combinedList);
	print(combinedList);
	removeDuplicates(combinedList);
	print(combinedList);


}
