#include "ListNode.h"


Node::Node()
{

}



Node::~Node()
{


}





//////////////////////////////Getters

int Node::get_num()
{
	return num;
}

int Node::get_id()
{
	return id;
}

string Node::get_name()
{
	return name;
}

string Node::get_email()
{
	return email;
}

int Node::get_units()
{
	return units;
}

string Node::get_major()
{
	return major;
}

string Node::get_level()
{
	return level;
}

int Node::get_absences()
{
	return absences;
}

Node Node::get_next()
{
	return *pNext;
}

Stack Node::get_dates()
{
	return *pTop;
}




////////////////////////////Setters

void Node::set_num(int num1)
{
	num = num1;
}

void Node::set_id(int id1)
{
	id = id1;
}

void Node::set_name(string name1)
{
	name = name1;
}

void Node::set_email(string email1)
{
	email = email1;
}

void Node::set_units(int units1)
{
	units = units1;
}

void Node::set_major(string major1)
{
	major = major1;
}

void Node::set_level(string level1)
{
	level = level1;
}

void Node::set_absences(int absences1)
{
	absences = absences1;
}

void Node::set_dates(string date)
{

}