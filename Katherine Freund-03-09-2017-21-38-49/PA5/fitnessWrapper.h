#pragma once
#include "exercisePlan.h"
#include "dietPlan.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;

//NOTE: Because I am using lists, I put all the load, display, and store functions under
//the list class. This is basically just a dummy class.


class FitnessAppWrapper
{

public:

	FitnessAppWrapper();
	~FitnessAppWrapper();

	DietPlan dplan;
	ExercisePlan eplan;
};

