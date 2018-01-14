#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::string;


//NOTE:
// There's an error that it's giving me, but it's giving me giberrish as to where the problem is. I can't seem to fix this.

class DietPlan
{
public:

	DietPlan(); //constructor, 2 pts
	DietPlan(DietPlan &copy); //copy constructor, 2 pts
	~DietPlan(); //destructor, 1 pt

	//getters and getters, 4 pts
	int getGoalCal();
	string getName();
	string getDate();
	void setGoal(int newCalories);
	void setName(string newName);
	void setDate(string newDate);
	
	//edits, 4 pts
	void editGoal();
	void editName();
	void editDate();

	//others? 2 pts
	friend ostream & operator << (ostream &lhs, DietPlan &rhs);
	friend istream & operator >> (istream &lhs, DietPlan &rhs);

private:
	int mGoalCal; //1 pt
	string mName; //1 pt
	string mDate; //1 pt
};
