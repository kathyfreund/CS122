#pragma once
#include "List.h"



//part of the 25 pts - appropriate design/implementation of Class ListNode
class Node
{
public:
	Node();
	~Node();

	//getters
	int get_num();
	int get_id();
	string get_name();
	string get_email();
	int get_units();
	string get_major();
	string get_level();
	int get_absences();
	Node get_next();
	Stack get_dates();


	//setters
	void set_num(int num1);
	void set_id(int id1);
	void set_name(string name1);
	void set_email(string email1);
	void set_units(int units1);
	void set_major(string major1);
	void set_level(string level1);
	void set_absences(int absences1);
	void set_dates(string date);

private:
	int num;
	int id;
	string name;
	string email;
	int units;
	string major;
	string level;
	int absences;
	Node *pNext;
	Stack *pTop;
};
