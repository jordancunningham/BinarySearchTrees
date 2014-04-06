//Author: Jordan Cunningham

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Node.h"
#include "Tree.h"

using namespace std;

void tree_insert(Tree *, Node *);
void inorder_tree_walk(Node *);

void main(){

	//Number-Getting-Stuff
	vector<int> arr;	//store things...
	vector<Node*> nodeVector;	//...
	
	Tree tree;	//binary tree object (contains a pointer to the root node)

	ifstream inFile;	//file stream

	string fName;	//file name

	cout<<"Enter the name of the file you would like to work with: ";
	cin>>fName;
	cout<<endl<<endl;

	inFile.open(fName);

	while(!inFile.is_open()){	//check to make sure file opened correctly
	
		cout<<"File did not open correctly. Please re-enter file name: ";
		cin>>fName;
		cout<<endl<<endl;

		inFile.open(fName);
	
	}

	while(!inFile.eof()){	//store nodes in a vector

		int temp;
		inFile>>temp;
		Node *node = new Node(temp);
		nodeVector.push_back(node);

	}

	for(vector<Node*>::iterator count = nodeVector.begin(); count != nodeVector.end(); count++){	//move nodes from vector into tree
	
		tree_insert(&tree, *count);
	
	}
	
	inorder_tree_walk(tree.root);	//prints all ints

	cout<<endl<<endl;

	cout<<"Press any key to exit."<<endl<<endl;
	
	cin.ignore();
	cin.get();

}

void inorder_tree_walk(Node *x){

	if(x != nullptr){

		inorder_tree_walk(x->left);
		cout<<x->key<<" ";
		inorder_tree_walk(x->right);
	
	}


}

void tree_insert(Tree *T, Node *node){		
	
	Node *y = nullptr;
	Node *x = T->root;

	while(x != nullptr){

		y = x;

		if(node->key < y->key)
			x = x->left;
		else
			x = x->right;

	}

	node->parent = y;

	if(y == nullptr)
		T->root = node;
	else if(node->key < y->key)
		y->left = node;
	else
		y->right = node;
}
