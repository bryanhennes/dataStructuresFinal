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
	//BST for due dates
	BST dateTree, * root = NULL;
	//BST for course names
	BST courseTree, * strRoot = NULL;
	
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
	void searchByCourse(string name);
	void displayDueDates();
	void displayCourseNames();
	void removeAssignment(string name);

};

