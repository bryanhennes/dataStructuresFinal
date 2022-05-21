#pragma once
#include <iostream>
using namespace std;

class Assignment
{
private:
	//# of days until assignment is due
	int dueDate;
	//corresponding course number
	string courseName;
	//is assignment completed or in progress?
	bool isCompleted;

public:
	//default constructor
	Assignment();

	//parameterized constructor
	Assignment(int dD, string courseNm, bool isComp = false);

	void updateDueDate(int date);

	void displayAssignment();

	string displayCompletedOrNot();

};

