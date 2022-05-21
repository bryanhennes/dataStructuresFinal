#include "Student.h"
#include "Assignment.h"
#include <vector>


Student::Student() {
	name = "John Doe";
	age = 18;
}

Student::Student(string nm, int ag) {
	name = nm;
	age = ag;
}


string Student::getName() {
	return(name);
}

void Student::setAssignments(int num)
{
	numAssignments = num;
}

int Student::getAssignmentCount() {
    return numAssignments;
}

void Student::changeDueDate() {
    string choice;
    int newDate;
    for (int i = 0; i < assignments.size(); i++) {
        cout << "Would you like to change the due date for assignment " << i+1 << "?: Y or N: ";
        cin >> choice;
        if (choice == "Y") {
            cout << "Okay when is this assignment due?: ";
            cin >> newDate;
            assignments[i].updateDueDate(newDate);
        }
            
    }
}

void Student::displayAssignments()
{
   
    for (int i = 0; i < assignments.size(); i++) {
        assignments[i].displayAssignment();
    }
}


void Student::displayAssignmentAmount()
{
	cout << name << " has " << numAssignments << " assignments to finish.";
}

void Student::addAssignment()
{
    int counter = 0;
    int due;
    string nm;
    string response;
    bool isComp;

    while (counter < getAssignmentCount()) {
        cout << "Assignment " << counter + 1 << " is due in how many days?: ";
        cin >> due;
        cout << "What class is assignment " << counter + 1 << " for?: ";
        cin >> nm;
        cout << "Is assignment " << counter + 1 << " completed?: Y or N: ";
        cin >> response;
        if (response == "Y")
            isComp = true;
        else
            isComp = false;

        //add assignment object to vector of assignments
        assignments.push_back(Assignment(due, nm, isComp));


        counter++;


    }
}


