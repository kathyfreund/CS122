#pragma once
#include "BST.h"

using std::vector;

class DataAnalysis //70 pts total
{
public:
	DataAnalysis();
	~DataAnalysis();
	
	void runAnalysis(); //15 pts - other functions?

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
	void open(); //5 pts - opening file
	void parseString(string &input, vector<string> &output)const; //10 pts - splitting/reading line
	void parseFile(); //10 pts - reading all lines and insering them
	void compare(Node *temp, string choice); //20 pts - determining trends/displaying
	void printData(); //see above

};