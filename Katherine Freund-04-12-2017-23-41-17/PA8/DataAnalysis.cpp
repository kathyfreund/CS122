#include "DataAnalysis.h"


//constructor/destructor
DataAnalysis::DataAnalysis()
{

}
DataAnalysis::~DataAnalysis()
{

}




//function
void DataAnalysis::runAnalysis()
{
	open();
	parseFile();
	printData();
}




//private functions
void DataAnalysis::open()
{
	mCsvStream.open("data.csv");
}

void DataAnalysis::parseString(string &input, vector<string> &output) const
{
	std::stringstream temp(input);
	string token;
	while (getline(temp, token, ','))
	{
		output.push_back(token);
	}
}

void DataAnalysis::parseFile()
{
	vector<string> output;
	string input;
	getline(mCsvStream, input);
	while (getline(mCsvStream, input))
	{
		output.clear();
		parseString(input, output);
		Node *newNode = new TransNode(output[1], stoi(output[0]));
		compare(newNode, output[2]);
	}
	mTreeSold.inOrder();
	mTreePurchased.inOrder();
}



//compiler keeps complaining about a & and I'm tired of fighting with it
void DataAnalysis::compare(Node *temp, string choice)
{
	TransNode *pTemp = (TransNode*)temp;
	if (choice == "Purchased")
	{
		mTreePurchased.insert(pTemp->getData, pTemp->getUnits);
	}
	else if (choice == "Sold")
	{
		mTreeSold.insert(pTemp->getData, pTemp->getUnits);
	}
}


void DataAnalysis::printData()
{
	cout << "Least Purchased:" << mTreePurchased.findSmall() << endl;
	cout << "Most Purchased:" << mTreePurchased.findLarge() << endl << endl;
	cout << "Lease Sold:" << mTreeSold.findSmall() << endl;
	cout << "Most Sold:" << mTreeSold.findLarge() << endl;
}