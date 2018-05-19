#pragma once
#ifndef _LIST_H_
#define _LIST_H_

// Exercise 1
void insert(int x, int i, Node* &a);
void remove(int i, Node* &list);
int read(int i, Node *list);
Node *search(int x, Node *list);

// Exercise 2
int listSize(Node* &list);

// Exercise 3
void print(Node* list);

void listEx1();
void listEx2();
void listEx3();
void listEx4();
void listEx5();
void listEx6();
void listEx7();
void listEx8();
void listEx9();

#endif // _LIST_H_

