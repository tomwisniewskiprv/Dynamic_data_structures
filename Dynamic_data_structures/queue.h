// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercise 2 , 6 , 12 , 13 - Queue 

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "stack.h"
using namespace std;

void enqueue(Node* &front, Node* &read, int x);
int dequeue(Node* &front, Node* &read, bool &success);
int firstEl(Node* front);
bool isEmptyQ(Node* front);

void joinQueues(Node* &front, Node* &read, Node* &frontNext, Node* &rearNext); // Exercise 12
void reverseQueue(Node* &front, Node* &read); // Exercise 13

void testQueue();
void testQueueE13();

void staticQueue(); // Exercise 6
#endif // !_QUEUE_H_
