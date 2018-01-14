#include "TransactionNode.h"


//constructor/destructor
TransNode::TransNode(string temp, int num)
{
	mData = temp;
	mUnits = num;
}
TransNode::~TransNode()
{

}




//getters
int TransNode::getUnits()
{
	return mUnits;
}


//setters
void TransNode::setUnits(int units)
{
	mUnits = units;
}




//print
void TransNode::printData()
{
	cout << "Data:" << mData << endl;
	cout << "Units:" << mUnits << endl;
}