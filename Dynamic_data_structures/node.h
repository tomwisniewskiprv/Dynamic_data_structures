// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

#pragma once

#ifndef _NODE_H_
#define _NODE_H_

// Basic data structure
struct Node
{
	int item = 0;
	Node *next = nullptr;
};

// 23.05.2018 - extended verion, for second part of list's exercises
// extended node
struct DoublyLinkedNode
{
	int item = 0;
	DoublyLinkedNode *next = nullptr;
    DoublyLinkedNode *prev = nullptr;
};
#endif