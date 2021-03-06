// Dynamic Data Structures
// Tomasz Wisniewski 20.05.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercises 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 10 , 11 - Lists , part one

#pragma once
#ifndef _LIST_H_
#define _LIST_H_

// Exercise 1
void insert(int x, int i, Node* &list);
void remove(int i, Node* &list);
int read(int i, Node *list);
Node *search(int x, Node *list);

// Exercise 2
int listSize(Node* &list);

// Exercise 3
void print(Node* list);

// Execute all exercises
void listFirstPart();

#endif // _LIST_H_

