#pragma once
#include "BSTnode.h"
#include "run.h"

#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <cctype>
#include <cassert>


using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::thread;

template <class T>
class List
{
public:
	List();
	~List();

	void print();
	void search(vector<char>&convert, int &i);
	static void check(vector<string> &morse, vector<char>&convert);
	void deleteTree();

	BSTNode<T> *& getRoot();

	void setRoot(BSTNode<T> * const newRoot);
	void insert(BSTNode<T> *&Node);

	void gothroughmorse(vector<string> &morseArray, ifstream &morsefile);
	void gothroughinput(vector<char> &convert, ifstream &inputfile) const;

	static BSTNode<T> *makeNode();

private:
	BSTNode<T> *root;
	void insert(BSTNode<T> *&rootNode, BSTNode<T> *&Node);
	void print(BSTNode<T> *&rootNode);
	bool search(BSTNode<T> *&rootNode, vector<char>&convert, int &i);
	void deleteTree(BSTNode<T> *&rootNode);

};




template<class T>
List<T>::List()
{
	root = nullptr;
	ifstream morsefile("MorseTable.txt", std::ios::in);
	ifstream inputfile("Convert.txt", std::ios::in);
	assert(morsefile.is_open());
	assert(inputfile.is_open());

	vector<string> morse;
	vector<char>convert;
	auto i = 0;

	thread mLoop(&List::gothroughmorse, this, ref(morse), ref(morsefile));
	thread iLoop(&List::gothroughinput, this, ref(convert), ref(inputfile));
	mLoop.join();
	iLoop.join();
	check(morse, convert);
	while (i < convert.size())
	{
		search(convert, i);
	}
}



template<class T>
List<T>::~List()
{
	deleteTree();
	cout << "THE THREE IS NO MORE" << endl;
}


template <class T>
void List<T>::print()
{
	print(this->root);
}


template <class T>
void List<T>::search(vector<char> &convert, int &i)
{
	search(this->root, convert, i);
}


template<class T>
void List<T>::check(vector<string> &morse, vector<char> &convert)
{
	auto j = 0;
	static auto i = 0;
	while (i != convert.size())
	{
		for (j = 0; j < morse.size(); j++)
		{
			if (morse[j][0] == convert[i])
			{
				i++;
				break;
			}
		}
		if (j == morse.size())
		{
			convert[i] = '?';
		}
	}
}



template <class T>
void List<T>::deleteTree()
{
	deleteTree(this->root);
}



template <class T>
BSTNode<T> *& List<T>::getRoot()
{
	return root;
}




template <class T>
void List<T>::setRoot(BSTNode<T> *const newRoot)
{
	root = newRoot;
}




template <class T>
void List<T>::insert(BSTNode<T> *&Node)
{
	insert(this->root, Node);
}




template <class T>
void List<T>::gothroughmorse(vector<string> &morse, ifstream &morsefile)
{
	auto i = 0;
	while (!morsefile.eof())
	{
		BSTNode<T> *Node = new BSTNode<T>;
		string temp;
		getline(morsefile, temp);
		morse.push_back(temp);
		morse[i].erase(remove_if(morse[i].begin(), morse[i].end(), isspace), morse[i].end());
		Node->setData(morse[i][0]);
		Node->setString(morse[i].substr(1, string::npos));
		insert(Node);
		i++;
	}
	morsefile.close();
	assert(!morsefile.is_open());
}



template <class T>
void List<T>::gothroughinput(vector<char> &convert, ifstream &inputfile) const
{
	while (!inputfile.eof())
	{
		string temp;
		getline(inputfile, temp);
		for (auto j = 0; j < temp.length(); j++)
		{
			if (temp[j] == ' ')
			{
				temp[j] = '_';
			}
			convert.push_back(toupper(temp[j]));
		}
	}
	inputfile.close();
	assert(!inputfile.is_open());
}


template <class T>
BSTNode<T> *List<T>::makeNode()
{
	return new BSTNode<T>;
}




template <class T>
void List<T>::insert(BSTNode<T> *&root, BSTNode<T> *&Node)
{
	if (root == nullptr)
	{
		root = Node;
	}
	else if (Node->getData() < root->getData())
	{
		insert(root->lefty(), Node);
	}
	else if (Node->getData() > root->getData())
	{
		insert(root->righty(), Node);
	}
	else
	{
		cout << "duplicate" << endl;
	}
}



template <class T>
void List<T>::print(BSTNode<T> *&root)
{
	if (root != nullptr)
	{
		print(root->lefty());
		cout << root->getstring() << endl;
		print(root->righty());
	}
}




template <class T>
bool List<T>::search(BSTNode<T> *&root, vector<char> &convert, int &i)
{
	if (root != nullptr)
	{
		search(root->lefty(), convert, i);
		if (i < convert.size())
		{
			if (root->getData() == convert[i])
			{
				cout << root->getString() << ' ';
				i++;
				if (i == convert.size())
				{
					cout << '\n';
					for (auto j = 0; j < convert.size(); j++)
					{
						cout << convert[j] << ' ';
					}
					cout << '\n';
					return true;
				}
			}
			search(root->righty(), convert, i);
		}
	}
}




template <class T>
void List<T>::deleteTree(BSTNode<T> *&root)
{
	if (root != nullptr)
	{
		deleteTree(root->lefty());
		deleteTree(root->righty());
		delete root;
	}
}