// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercise 2 , 6 , 12 , 13 - Queue 

#include "stack1.h"
using namespace std;

void add(ele* &poczkol, ele* &konkol, int x);
int next(ele* &poczkol, ele* &konkol, bool &sukces);
int firstEl(ele* poczkol);
bool isEmptyQ(ele* poczkol);

void joinQueues(ele* &poczkol, ele* &konkol, ele* &pocznast, ele* &konnast); // Exercise 12
void reverseQueue(ele* &poczkol, ele* &konkol); // Exercise 13

void testQueue();
void testQueueE13();

void staticQueue(); // Exercise 6
