#pragma once
#include <string>

using std::string;
////////////////////////// 15 pts - implementation of Class Stack
class Stack 
{
public:

	Stack();
	~Stack();

	Stack get_top();
	Stack get_next();
	string get_absence();
	int get_count();

	void set_top(Stack *pTop1);
	void set_date(string pTemp);
	void set_next(Stack *pTemp);

	void pop();
	void push(string pNew);
	string peek();

private:
	Stack *pTop;
	Stack *pNext;
	string date;
	int count;
};



