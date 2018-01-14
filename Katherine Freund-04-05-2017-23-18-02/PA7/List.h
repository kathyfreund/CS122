#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "stack.h"
#include "ListNode.h"


using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::fstream;


//visual studio is complaining about the Node data types that im trying to use. I have "ListNode.h"
//file included above, but I can't seem to figure out why it's complaining?


//Part of the 25 pts - design/implementation of Class List
class List
{
public:
	List();
	~List();

	Node read_in_records(fstream &file); //19 pts - import records
	// got help for stoi: http://stackoverflow.com/questions/7663709/convert-string-to-int-c


	void mark_attendance(Node *pHead1); //12 pts - mark absences
	

	//12 pts - generate reports, 6 pts each
	void report1(Node *pHead1);
	void report2(Node *pHead1);


	void edit_absences(Node *pHead1); //BONUS: 20 pts - edit absences

private:
	Node *pHead;


};