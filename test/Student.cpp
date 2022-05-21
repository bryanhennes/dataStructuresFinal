#include "Student.h"
#include "Assignment.h"
#include <vector>
#include "BST.h"

//default conmstructor
Student::Student() {
	name = "John Doe";
	age = 18;
}

//parameterized constructor
Student::Student(string nm, int ag) {
	name = nm;
	age = ag;
}

//return student's name
string Student::getName() {
	return(name);
}

//set assignment count
void Student::setAssignments(int num)
{
	numAssignments = num;
}

//get amount of assignments
int Student::getAssignmentCount() {
    return numAssignments;
}

//change due date of assignments
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

//display all assignments that are currently in progress
void Student::displayInProgress()
{
    cout << "Current assignments in progress: " << endl;
    for (int i = 0; i < assignments.size(); i++) {
        if (assignments[i].isAssignmentCompleted())
            cout << "-" << assignments[i].getCourseName() << endl;
    }
}

//search BST for due date
void Student::searchByDueDate(int date)
{
    if (b.search(root, date)) {
        cout << "Here are all assignments due in " << date << " days: " << endl;
        for (int i = 0; i < assignments.size(); i++) {
            //display any asignments with that due date if the due date is found in the BST
            if (assignments[i].getDueDate() == date) {
                assignments[i].displayAssignment();
            }
        }
    }
    else
        cout << "We did not find a class due in " << date << " days." << endl;
}

//display due dates from BST
void Student::displayDueDates()
{
    b.Inorder(root);
}

//display all assignments regardless of completion status
void Student::displayAssignments()
{
    for (int i = 0; i < assignments.size(); i++) {
        assignments[i].displayAssignment();
    }
}

//display assignment count
void Student::displayAssignmentAmount()
{
	cout << name << " has " << numAssignments << " assignments to finish.";
}

//add assignments
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

        //insert assignment due dates into BST
        if(counter == 0)
            root = b.Insert(root, assignments[counter].getDueDate());
        else
            b.Insert(root, assignments[counter].getDueDate());


        counter++;


    }
}


