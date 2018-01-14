#include "stack.h"


Stack::Stack()
{

}


Stack::~Stack()
{

}


Stack Stack::get_top()
{
	return *pTop;
}

Stack Stack::get_next()
{
	return *pNext;
}

string Stack::get_absence()
{
	return date;
}

int Stack::get_count()
{
	return count;
}




void Stack::set_top(Stack *pTop1)
{
	pTop = pTop1;
}

void Stack::set_date(string pTemp)
{
	date = pTemp;
}


void Stack::set_next(Stack *pTemp)
{
	pNext = pTemp;
}








void Stack::pop()
{
	pTop = pTop->pNext;
}


void Stack::push(string pNew)
{
	Stack *pTemp;
	pTemp->set_date(pNew);
	pTemp->set_next(pTop);
	pTop = pTemp;
	count++;
}

string Stack::peek()
{
	return pTop->date;
}