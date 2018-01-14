#include "BST.h"

//constructor/destructor/delete tree
BST::BST()
{
	mpRoot = nullptr;
}
BST::~BST()
{
	deleteTree(mpRoot);
}
void BST::deleteTree(Node *temp)
{
	if (temp != nullptr)
	{
		deleteTree(temp->Node::lefty());
		deleteTree(temp->Node::righty());
		delete temp;
	}
}



//getters
Node *BST::getRoot()
{
	return mpRoot;
}


//setters
void BST::setRoot(Node *root)
{
	mpRoot = root;
}




//functions (public)
void BST::insert(string foo, int num)
{
	Node *newNode = new TransNode(foo, num);
	insert(newNode);
}
void BST::inOrder()
{
	inOrder(mpRoot);
}
TransNode *BST::findSmall()
{
	TransNode *small = nullptr;
	small = findSmall(mpRoot);
	return small;
}
TransNode *BST::findLarge()
{
	TransNode *large = nullptr;
	large = findLarge(mpRoot);
	return large;
}



//functions (private)
void BST::insert(Node *temp)
{
	TransNode *pTemp = (TransNode*)temp;
	TransNode *root = (TransNode*)mpRoot;
	if (root == nullptr)
	{
		root = pTemp;
	}
	else if (root->getUnits() >= pTemp->getUnits())
	{
		insert(root->lefty());
	}
	else
	{
		insert(root->righty());
	}
}
void BST::inOrder(Node *temp) const
{
	TransNode *foo = (TransNode*)temp;
	if (foo != nullptr)
	{
		inOrder(foo->lefty());
		temp->printData();
		inOrder(foo->righty());
	}
}
TransNode *BST::findSmall(Node *temp) const //get units?
{
	TransNode *foo = (TransNode*)temp;
	TransNode *small = foo;
	while (small->lefty() != nullptr)
	{
		small = (TransNode*)small->lefty();
	}
	return small;
}
TransNode *BST::findLarge(Node *temp) const //get units?
{
	TransNode *foo = (TransNode*)temp;
	TransNode *large = foo;
	while (large->righty() != nullptr)
	{
		large = (TransNode*)large->righty();
	}
	return large;
}


