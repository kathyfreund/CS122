#pragma once
#include "Node.h"
#include "TransactionNode.h"

class BST // 75 pts total
{
public:
	BST();
	~BST();

	//getters
	Node *getRoot();

	//setters
	void setRoot(Node *root);

	//functions
	void insert(string foo, int num); //5 pts - public insert function
	void inOrder(); //5 pts - public in order function
	TransNode *findSmall();
	TransNode *findLarge(); //10 pts - other functions?

private:
	Node *mpRoot; 
	void deleteTree(Node *temp); //10 pts - destroy tree
	void insert(Node *temp); //15 pts - private insert functions
	void inOrder(Node *temp) const; // 15 pts - private in order function
	TransNode *findSmall(Node *temp) const; //10 pts - find smallest
	TransNode *findLarge(Node *temp) const; //10 pts - find largest
;

};