#include "List.h"
#include "stack.h"

List::List()
{

}

List::~List()
{

}






Node List::read_in_records(fstream &file)
{
	Node *pNew;
	string token;
	int i = 0, x = 0;
	while (!file.eof())
	{
		getline(file, token, ',');
		i++;
		switch (i)
		{
		case 1:
			x = stoi(token);
			pNew->set_num(x);
			break;
		case 2:
			x = stoi(token);
			pNew->set_id(x);
			break;
		case 3:
			pNew->set_name(token);
			break;
		case 4:
			pNew->set_email(token);
			break;
		case 5:
			x = stoi(token);
			pNew->set_units(x);
			break;
		case 6:
			pNew->set_major(token);
			break;
		case 7:
			pNew->set_level(token);
			break;
		case 8:
			x = stoi(token);
			pNew->set_absences(x);
			break;
		default:
			pNew->set_dates(token);
			break;
		}

	}


}



void List::mark_attendance(Node *pHead1)
{
	string date;
	cout << "What is today's date?" << endl;
	cin >> date;

	cout << "When names appaer, press 1 for present, 0 for absent." << endl;

	Node *pTemp = pHead1;
	int attend = 0;

	while (pTemp != nullptr)
	{
		cout << pTemp->get_name << endl;
		cin >> attend;
		if (attend == 0)
		{
			pTemp->set_dates(date);
		}
		pTemp = pTemp->get_next;
	}
}


void List::report1(Node *pHead1)
{
	Node *pTemp = pHead1;
	Stack *absences;
	while (pTemp != nullptr)
	{
		cout << pTemp->get_name;
		absences = pTemp->get_dates;
		cout << absences->peek() << endl;
		pTemp = pTemp->get_next;
	}
}

void List::report2(Node *pHead1)
{
	int input;
	Node *pTemp = pHead1;
	Stack *absences;
	cout << "Please enter amount of absences requested:" << endl;
	cin >> input;

	while (pTemp != nullptr)
	{
		absences = pTemp->get_dates;
		if (absences->get_count >= input)
		{
			cout << pTemp->get_name << endl;
			while (absences != nullptr)
			{
				cout << absences->peek << endl;
				absences = absences->get_next;
			}
		}
		pTemp = pTemp->get_next;
	}
	
}



void List::edit_absences(Node *pHead1)
{
	string name, date;
	Stack *absences;
	int choice = 0;
	cout << "For which student would you like to edit absences for?" << endl;
	cin >> name;
	
	Node *pTemp = pHead1;
	while (pTemp->get_name != name)
	{
		pTemp = pTemp->get_next;
	}
	if (pTemp->get_name == name)
	{
		cout << "Would you like to (1)add or, (2)delete latest absence?" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "Please enter a new date to add to student's absences:" << endl;
			cin >> date;
			absences = pTemp->get_dates;
			absences->push(date);
		}
		else if (choice == 2)
		{
			absences = pTemp->get_dates;
			absences->pop();
		}
	}
}