// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercise 2 , 12 - Queue 

#pragma once
#include "stack1.h"

using namespace std;


void add(ele* &poczkol, ele* &konkol, int x);
int next(ele* &poczkol, ele* &konkol);
int firstEl(ele* poczkol);
bool isEmptyQ(ele* poczkol);

void joinQueues(ele* &poczkol, ele* &konkol, ele* &pocznast, ele* &konnast); // Exercise 12

void test_queue() ;
