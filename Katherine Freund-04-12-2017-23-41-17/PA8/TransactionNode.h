#pragma once
#include "Node.h"

//15 pts - TransactionNode class, which inherits from the Node class and all functions described above
class TransNode :public Node
{
public:
	TransNode(string temp = "", int num = 0);
	~TransNode();

	//getters
	int getUnits();

	//setters
	void setUnits(int units);

	void printData() override;

private:
	int mUnits;
	//destroy tree


};
