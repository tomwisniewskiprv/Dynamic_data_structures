// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercises 1 , 3 , 4 , 5 , 10 , 11

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "element.h"
using namespace std;

long rng(int range);

void push(ele* &stos, int value);
int pop(ele* &stos);
int peek(ele* stos);
bool isEmpty(ele* stos);

void testStack();
void stack_commands(string str);
void destroy_stack(ele* &stos);
long countStackElements(ele* &stos);
void stacks2queue();
void ex7();
