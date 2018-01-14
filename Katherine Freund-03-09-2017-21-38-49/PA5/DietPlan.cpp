#include "dietPlan.h"

DietPlan::DietPlan()
{
	mDate = "";
	mName = "";
	mGoalCal = 0;
}

DietPlan::DietPlan(DietPlan &copy)
{
	mDate = copy.getDate();
	mName = copy.getName();
	mGoalCal = copy.mGoalCal;
}

DietPlan::~DietPlan()
{

}


string DietPlan::getDate()
{
	return mDate;
}

string DietPlan::getName()
{
	return mName;
}

int DietPlan::getGoalCal()
{
	return mGoalCal;
}


void DietPlan::editGoal()
{
	cout << "Pleae enter new goal calories:" << endl;
	cin >> mGoalCal;
}

void DietPlan::editDate()
{
	cout << "Please enter new date for plan:" << endl;
	cin >> mDate;
}

void DietPlan::editName()
{
	cout << "Please enter your new diet goal name:" << endl;
	cin >> mName;
}

void DietPlan::setName(string newName)
{
	mName = newName;
}

void DietPlan::setDate(string newDate)
{
	mDate = newDate;
}

void DietPlan::setGoal(int newCalories)
{
	mGoalCal = newCalories;
}


ostream & operator << (ostream &lhs, DietPlan &rhs)
{
	lhs << rhs.getGoalCal() << endl;
	lhs << rhs.getName() << endl;
	lhs << rhs.getDate() << endl;
	lhs << "" << endl;
	return lhs;
}


istream & operator >> (istream &lhs, DietPlan &rhs)
{
	int g;
	string n;
	string d;
	lhs >> n;
	lhs >> g;
	lhs >> d;
	rhs.setGoal(g);
	rhs.setName(n);
	rhs.setDate(d);
	return lhs;
}