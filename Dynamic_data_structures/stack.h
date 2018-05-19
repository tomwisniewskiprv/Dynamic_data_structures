// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercises 1 , 3 , 4 , 5 , 10 , 11

#ifndef _STACK_H_
#define _STACK_H_

#include "node.h"

using namespace std;

long randomInt(int range);

void push(Node* &stos, int value);
int pop(Node* &stos);
int peek(Node* stos);
bool isEmpty(Node* stos);

void testStack();
void stackCommands(string str);
void destroyStack(Node* &stos);
long countStackElements(Node* &stos);
void stacks2queue();
void ex7();


#endif // !_STACK_H_
