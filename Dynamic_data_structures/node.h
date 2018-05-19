// Dynamic Data Structures
// Tomasz Wisniewski 10.03.2018
// Part II of Algorithms and Data Structures
// Uniwersytet Slaski 

#pragma once

#ifndef _NODE_H_
#define _NODE_H_

// Node struct used in stacks and queues.
// 'Node' is an abberation of 'Nodement'.
struct Node
{
	int item = 0;
	Node* next = nullptr;
};

#endif