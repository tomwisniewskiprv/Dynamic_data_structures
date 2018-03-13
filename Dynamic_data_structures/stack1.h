// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

// Exercises 1 , 3 , 4 , 11 - ele


#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

long rng(int range);

struct ele {
	int dane = 0;
	ele* nast = nullptr;
};

void push(ele* &stos, int value);
int pop(ele* &stos);
int peek(ele* stos);
bool isEmpty(ele* stos);

void test_stack();
void stack_commands(string str);
void destroy_stack(ele* &stos);
