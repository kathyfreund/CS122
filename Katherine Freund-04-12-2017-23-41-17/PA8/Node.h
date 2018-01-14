#pragma once

//okay, so everything is fine and good and beautiful except for this one part in the
//dataAnalysis.cpp part, the compiler keeps bitching about some '&' and idk what.
//here's the error in case you're curious: "non-standard syntax: use '&' to create a pointer
//to a member." besides that, i think its all doodoly doo.


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;


class TransactionNode;

class Node //15 points - Node class and all functions described above
{
public:
	Node(string temp = "");
	virtual ~Node();


	//getters
	string getData() const;
	Node *lefty();
	Node *righty();


	//setters
	void setData(string &newData);
	void setLeft(Node *left);
	void setRight(Node *right);

	virtual void printData() = 0;

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;

};