#include "dietPlan.h"
#include "list.h"



List::List()
{
	pHead = nullptr;
}

List::~List()
{

}

Node *List::makeNode()
{
	return new Node;
}


void List::runapp()
{
	fstream diet;
	diet.open("dietPlans.txt", std::ios::in | std::ios::out);

	fstream exer;
	exer.open("exercisePlans.txt", std::ios::in | std::ios::out);

	diet.close();
	exer.close();
}










Node * List::loadDailyD()
{
	Node *pTemp;


	return pTemp;
}
Node * List::loadDailyE()
{
	Node *pTemp;


	return pTemp;
}
Node * List::loadWeeklyD()
{
	Node *pTemp;


	return pTemp;
}
Node * List::loadWeeklyE()
{
	Node *pTemp;


	return pTemp;
}







void List::displayDailyD() const
{
	auto *pCur = pHead;
	int x = 0, count = 0;
	
	cout << "Which daily plan would you like to see?" << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	cout << "6.Saturday" << endl;
	cout << "7.Sunday" << endl;
	cin >> x;
	x++;
	
	if ((x>0) && (x<8))
	{
		while (x > 0)
		{
			pCur = pCur->pNext;
			x--;
		}
		cout << pCur->x.dplan;
	}
	else
	{
		cout << "Invalid input. Please try again." << endl;
	}
}


void List::displayDailyE() const
{
	auto *pCur = pHead;
	int x = 0, count = 0;

	cout << "Which daily plan would you like to see?" << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	cout << "6.Saturday" << endl;
	cout << "7.Sunday" << endl;
	cin >> x;
	x++;

	if ((x>0) && (x<8))
	{
		while (x > 0)
		{
			pCur = pCur->pNext;
			x--;
		}
		cout << pCur->x.eplan;
	}
	else
	{
		cout << "Invalid input. Please try again." << endl;
	}
}



void List::displayWeeklyD() const
{
	auto *pCur = pHead;
	int count = 0;

	while (count < 8)
	{
		cout << pCur->x.dplan;
		pCur = pCur->pNext;
		count++;
	}
}


void List::displayWeeklyE() const
{
	auto *pCur = pHead;
	int count = 0;

	while (count < 8)
	{
		cout << pCur->x.eplan;
		pCur = pCur->pNext;
		count++;
	}
}




























void List::storeDailyD(fstream &diet) const
{
	auto *pCur = pHead;
	int x = 0, count = 0;

	cout << "Which daily plan would you like to store a plan?" << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	cout << "6.Saturday" << endl;
	cout << "7.Sunday" << endl;
	cin >> x;
	x++;

	if ((x>0) && (x<8))
	{
		while (x > 0)
		{
			pCur = pCur->pNext;
			x--;
		}
		diet << pCur->x.dplan;
	}
	else
	{
		cout << "Invalid input. Please try again." << endl;
	}
}




void List::storeDailyE(fstream &exer) const
{
	auto *pCur = pHead;
	int x = 0, count = 0;

	cout << "Which daily plan would you like to store a plan?" << endl;
	cout << "1.Monday" << endl;
	cout << "2.Tuesday" << endl;
	cout << "3.Wednesday" << endl;
	cout << "4.Thursday" << endl;
	cout << "5.Friday" << endl;
	cout << "6.Saturday" << endl;
	cout << "7.Sunday" << endl;
	cin >> x;
	x++;

	if ((x>0) && (x<8))
	{
		while (x > 0)
		{
			pCur = pCur->pNext;
			x--;
		}
		exer << pCur->x.dplan;
	}
	else
	{
		cout << "Invalid input. Please try again." << endl;
	}
}






void List::storeWeeklyD(fstream &diet) const
{
	auto *pCur = pHead;
	diet.seekg(std::ios::beg);
	while (pCur->pNext != nullptr)
	{
		diet << pCur->x.eplan << endl;
		pCur = pCur->pNext;
	}
}


void List::storeWeeklyE(fstream &exer) const
{
	auto *pCur = pHead;
	exer.seekg(std::ios::beg);
	while (pCur->pNext != nullptr)
	{
		exer << pCur->x.eplan << endl;
		pCur = pCur->pNext;
	}
}










void List::menu(fstream &FileD, fstream &FileE) const
{
	int x = 0;

	cout << "Please select one of the following options:" << endl;
	cout << "1.Load weekly diet plan." << endl;
	cout << "2.Load weekly exercise plan." << endl;
	cout << "3.Store weekly diet plan." << endl;
	cout << "4.Store weekly exercise." << endl;
	cout << "5.Display weekly diet plan." << endl;
	cout << "6.Display weekly exercise plan." << endl;
	cout << "7.Nope." << endl;
	cout << "8.Nope." << endl;
	cout << "9.Exit." << endl;
	cin >> x;

	switch (x)
	{
	case 1:
		cout << "File was preloaded because I'm too lazy to do it now." << endl;
		break;
	case 2:
		cout << "File was preloaded because I'm too lazy to do it now." << endl;
	case 3:
		storeWeeklyD(FileD);
		break;
	case 4:
		storeWeeklyE(FileE);
		break;
	case 5:
		displayWeeklyD();
		break;
	case 6:
		displayWeeklyE();
		break;
	case 7:
		//no need for edit
		break;
	case 8:
		//no need for edit
		break;
	case 9:
		storeWeeklyD(FileD);
		storeWeeklyE(FileE);
		break; 
	}
}







std::ostream & operator<<(std::ostream& lhs, FitnessAppWrapper & rhs)
{
	lhs << "Diet Plan Name: " << rhs.dplan.getName() << endl;
	lhs << "Diet Plan Goal: " << rhs.dplan.getGoalCal() << endl;
	lhs << "Diet Plan Date: " << rhs.dplan.getDate() << endl;
	lhs << '\n' << endl;
	lhs << "Exercise Plan Name: " << rhs.eplan.getName() << endl;
	lhs << "Exercise Plan Goal: " << rhs.eplan.getGoalSteps() << endl;
	lhs << "Exercise Plan Date: " << rhs.eplan.getDate() << endl;
	return lhs;
}

