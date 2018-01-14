#include "Node.h"


//constructor/destructor
Node::Node(string temp)
{
	mData = temp;
	mpLeft = nullptr;
	mpRight = nullptr;
}
Node::~Node()
{


}




//getters
string Node::getData() const
{
	return mData;
}
Node *Node::lefty()
{
	return mpLeft;
}
Node *Node::righty()
{
	return mpRight;
}





//setters
void Node::setData(string &newData)
{
	mData = newData;
}
void Node::setLeft(Node *lefty)
{
	mpLeft = lefty;
}
void Node::setRight(Node *righty)
{
	mpRight = righty;
}





//print
void Node::printData()
{
	//overridden
}