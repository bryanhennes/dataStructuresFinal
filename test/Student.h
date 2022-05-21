#pragma once

#include <string>
#include <iostream> 
#include "Assignment.h"
#include "BST.h"
#include <vector>

using namespace std;

class Student
{
private:
	string name;
	int age;
	int numAssignments;
	vector<Assignment> assignments;
	BST b, * root = NULL;
	//start by using simple array of assignment numbers to test
	
public:
	Student();
	Student(string nm, int age);
	string getName();
	void setAssignments(int num);
	void displayAssignmentAmount();
	void addAssignment();
	int getAssignmentCount();
	void displayAssignments();
	void changeDueDate();
	void displayInProgress();
	void searchByDueDate(int date);
	void displayDueDates();

};

