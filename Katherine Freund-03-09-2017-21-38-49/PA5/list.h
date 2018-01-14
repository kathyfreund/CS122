#pragma once
#include "fitnessWrapper.h"



typedef struct node
{
	FitnessAppWrapper x;
	struct node *pNext = nullptr;
}Node; //declare lists, 4 pts



class List
{
public:
	List();
	~List();


	Node *makeNode();

	friend std::ostream& operator<<(std::ostream& lhs, FitnessAppWrapper&rhs);

	Node *loadDailyD(); //2 pts
	Node *loadDailyE(); //2 pts
	Node *loadWeeklyD(); //2 pts
	Node *loadWeeklyE(); //2 pts

	void displayDailyD() const; //2 pts
	void displayDailyE() const; //2 pts
	void displayWeeklyD() const; //2 pts
	void displayWeeklyE() const;

	void storeDailyD(fstream &diet) const; //2 pts
	void storeDailyE(fstream &exer) const; //2 pts
	void storeWeeklyD(fstream &diet) const; //2 pts
	void storeWeeklyE(fstream &exer) const; //2 pts

	void runapp(); //opening/closing and runapp, 4 pts + 4 pts
	void menu(fstream &FileD, fstream &FileE) const; //2 pts



private:
	Node *pHead;
};

