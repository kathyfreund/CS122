#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::string;


class ExercisePlan
{
public:

	ExercisePlan(); //constructor, 2 pts
	ExercisePlan(ExercisePlan &copy); //copy constructor, 2 pts
	~ExercisePlan(); //destructor, 2 pts

	//getters and setters, 4 pts
	int getGoalSteps() const;
	string getName() const;
	string getDate() const;
	void setSteps(int newSteps);
	void setName(string newName);
	void setDate(string newDate);

	//edits, 4 pts
	void editGoal();
	void editName();
	void editDate();
	
	//others? 2 pts
	friend ostream & operator << (ostream &lhs, ExercisePlan &rhs);
	friend istream & operator >> (istream &lhs, ExercisePlan &rhs);

private:
	int mGoalSteps;//1 pt
	string mName;//1 pt
	string mDate;//1 pt
};