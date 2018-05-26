// Dynamic Data Structures
// Tomasz Wisniewski 20.05.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Doubly linked and Circular lists
// Exercises 1, 3, 4, 5,  part two


#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "node.h"
#include "list.h"
#include "randomInt.h"

using namespace std;

// Wstawia nowy wezel jako nastepny po zadanym wezle, jezeli wartosc i jest wieksza niz dlugosc listy
// to wstawi na koncu
// Wstawianie na poczatku odbywa sie poprzez indeks 0
void insertAfterDLL(int x, int i, DoublyLinkedNode* &list) {

    int element = 1;
    DoublyLinkedNode *newNode = nullptr;
    DoublyLinkedNode *currentNode = list;
    newNode = new DoublyLinkedNode;
    newNode->item = x;

    if (!list) {
        list = newNode;
    }
    else {
        while (currentNode->next && element != i) {
            currentNode = currentNode->next;
            element++;
        }

        // dodanie na koncu
        if (!currentNode->next) {
            newNode->prev = currentNode;
            currentNode->next = newNode;
        }
        // dodanie pomiedzy
        else {
            newNode->prev = currentNode;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }
}

// Usuniecie pierwszego wezla
void popFrontDLL(DoublyLinkedNode* &list) {

    if (list) {

        DoublyLinkedNode *firstNode = list;
        list = list->next;

        if (list)
            list->prev = nullptr;

        delete firstNode;
        firstNode = nullptr;
    }
}

// Usuwa wezel o danym indeksie
void removeNodeDLL(int i, DoublyLinkedNode* &list) {

    int position = 1;
    DoublyLinkedNode *currentNode = nullptr;
    DoublyLinkedNode *tmp = nullptr;

    if (list && i > 0) {
        currentNode = list;

        if (i == 1) {
            if (currentNode->next) {
                list = list->next;
                list->prev = nullptr;
                delete currentNode;
            }
        }
        else {
            while (currentNode && (position + 1) < i) {
                currentNode = currentNode->next;
                position++;
            }

            if (currentNode) {

                if (currentNode->next) {
                    tmp = currentNode->next;
                    currentNode->next = tmp->next;
                    delete tmp;

                    if (currentNode->next)
                        currentNode->next->prev = currentNode;
                }
            }
        }
    }
}

// Sprawdza czy dana wartosc jest na liscie
bool findDLL(int x, DoublyLinkedNode *list) {

    DoublyLinkedNode *currentNode = list;

    while (currentNode) {
        if (currentNode->item == x)
            return true;
        currentNode = currentNode->next;
    }

    return false;
}

// Przeksztalca liste jednokierunkowa w cykliczna
void linkedList2CircularLinked(Node* &list) {

    Node *node = list;
    Node *front = list;

    while (node->next) {
        node = node->next;
    }

    node->next = front;

}

// Przeksztalca liste dwukierunkowa w cykliczna
void doublyLinked2CircularLinked(DoublyLinkedNode* &list) {

    DoublyLinkedNode *node = list;
    DoublyLinkedNode *front = list;

    while (node->next) {
        node = node->next;
    }
    front->prev = node;
    node->next = front;

}

// Odwraca liste dwukierunkowa
void reverseDLL(DoublyLinkedNode* &list) {

    DoublyLinkedNode *currentNode = list;
    DoublyLinkedNode *nextNode = nullptr;
    DoublyLinkedNode *nextPtr = nullptr;
    DoublyLinkedNode *prevPtr = nullptr;

    while (currentNode) {

        nextPtr = currentNode->next;
        prevPtr = currentNode->prev;
        nextNode = currentNode->next;

        currentNode->next = prevPtr;
        currentNode->prev = nextPtr;

        if (nextNode == nullptr)
            break;
        currentNode = nextNode;
    }
    list = currentNode;

}

void printDLL(DoublyLinkedNode *list) {

    DoublyLinkedNode *node = list;
    while (node) {
        cout << node->item << " ";
        node = node->next;
    }
    cout << endl;

    delete node;
}

// Wyswietla liste cykliczna
void printLLC(Node *list) {
    Node *first = list;

    while (first) {
        cout << first->item << " ";
        first = first->next;

        if (first == list) {
            first = nullptr;
            break;
        }

    }
    cout << endl;

    delete first;
}

// Usuniecie listy cyklicznej
void deleteLLC(Node* &list) {

    Node *first = list;
    list = list->next;
    Node *tmp = nullptr;

    while (list) {

        if (list == first) {
            delete list;
            list = nullptr;
            break;
        }

        tmp = list;
        list = list->next;
        delete tmp;
    }
}

// Execute exercises 
void listSecondPart() {

    // doubly linked list
    DoublyLinkedNode *dll = nullptr;

    // 1
    insertAfterDLL(20, 2, dll);
    insertAfterDLL(10, 1, dll);
    insertAfterDLL(30, 2, dll);
    insertAfterDLL(555, 5, dll);
    insertAfterDLL(-11, -11, dll);
    cout << "test insertAfterDLL()" << endl;

    popFrontDLL(dll);
    cout << "test popFrontDLL()" << endl;
    cout << "test findDLL(): " << findDLL(555, dll) << " " << findDLL(66, dll) << endl;

    removeNodeDLL(1, dll);
    cout << "test removeNodeDLL()" << endl;

    // 3
    Node *linkedList = nullptr;
    for (int i = 0; i < 9; i++)
        insert(i, 1, linkedList);

    linkedList2CircularLinked(linkedList);
    cout << "test linkedList2CircularLinked()" << endl;
    printLLC(linkedList);
    deleteLLC(linkedList);
    cout << "delete" << endl;

    // 4
    doublyLinked2CircularLinked(dll);
    cout << "test doublyLinked2CircularLinked()" << endl;

    // 5
    DoublyLinkedNode *dll2 = nullptr;
    for (int i = 1; i < 5; i++)
        insertAfterDLL(i, 0, dll2);

    printDLL(dll2);
    reverseDLL(dll2);
    cout << "test reverseDLL()" << endl;
    printDLL(dll2);
    
    delete dll, dll2, linkedList;
}