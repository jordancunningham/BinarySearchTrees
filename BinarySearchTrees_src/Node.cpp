#include "Node.h"


Node::Node(void)
{
	key = 0;
	left = nullptr;
	right = nullptr;
	parent = nullptr;

}

Node::Node(int x){

	key = x;

	left = nullptr;
	right = nullptr;
	parent = nullptr;

}


Node::~Node(void)
{
}
