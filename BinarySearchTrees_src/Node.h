#pragma once

class Node
{
public:
	Node(void);
	Node(int);
	~Node(void);

	int key;
	Node *parent;
	Node *left;
	Node *right;

};

