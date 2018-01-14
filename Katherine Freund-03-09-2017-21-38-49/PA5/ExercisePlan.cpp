#include "exercisePlan.h"

ExercisePlan::ExercisePlan()
{
	mDate = "";
	mName = "";
	mGoalSteps = 0;

}

ExercisePlan::ExercisePlan(ExercisePlan &copy)
{
	mDate = copy.getDate();
	mName = copy.getName();
	mGoalSteps = copy.mGoalSteps;
}

ExercisePlan::~ExercisePlan()
{

}


string ExercisePlan::getDate() const
{
	return mDate;
}

string ExercisePlan::getName() const
{
	return mName;
}

int ExercisePlan::getGoalSteps() const
{
	return mGoalSteps;
}


void ExercisePlan::editGoal()
{
	cout << "Pleae enter new goal calories:" << endl;
	cin >> mGoalSteps;
}

void ExercisePlan::editDate()
{
	cout << "Please enter new date for plan:" << endl;
	cin >> mDate;
}

void ExercisePlan::editName()
{
	cout << "Please enter your new diet goal name:" << endl;
	cin >> mName;
}

void ExercisePlan::setName(string newName)
{
	mName = newName;
}

void ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}

void ExercisePlan::setSteps(int newSteps)
{
	mGoalSteps = newSteps;
}

ostream & operator << (ostream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getGoalSteps() << endl;
	lhs << rhs.getName() << endl;
	lhs << rhs.getDate() << endl;
	lhs << "" << endl;
	return lhs;
}


istream & operator >> (istream &lhs, ExercisePlan &rhs)
{
	int g;
	string n;
	string d;
	lhs >> n;
	lhs >> g;
	lhs >> d;
	rhs.setSteps(g);
	rhs.setName(n);
	rhs.setDate(d);
	return lhs;
}