#pragma once
#include "run.h"

#include <cassert>

template <class T>

class BSTNode
{
public:
	BSTNode();
	~BSTNode();
	T getData();
	BSTNode<T> *& lefty();
	BSTNode<T> *& righty();
	string getString() const;
	void setData(T &newData);
	void setString(string &newString);

private:
	T data;
	string temp;
	BSTNode<T> *leftptr;
	BSTNode<T> *rightptr;
};



template <class T>
BSTNode<T>::BSTNode()
{
	data = '\0';
	temp = "";
	leftptr = nullptr;
	rightptr = nullptr;
}

template <class T>
BSTNode<T>::~BSTNode()
{

}


template <class T>
T BSTNode<T>::getData()
{
	return T(data);
}


template <class T>
BSTNode<T> *&BSTNode<T>::lefty()
{
	return leftptr;
}


template <class T>
BSTNode<T> *&BSTNode<T>::righty()
{
	return rightptr;
}


template <class T>
string BSTNode<T>::getString() const
{
	return string(temp);
}



template <class T>
void BSTNode<T>::setData(T &newData)
{
	data = newData;
	assert(data == newData);
}



template <class T>
void BSTNode<T>::setString(string &newString)
{
	temp = newString;
	assert(temp == newString);
}


