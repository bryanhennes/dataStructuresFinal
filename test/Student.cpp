#include "Student.h"
#include "Assignment.h"
#include <vector>
#include <algorithm>
#include "BST.h"
#include <fstream>

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
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
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
    cout << endl;
}

//search BST for due date values by due date
void Student::searchByDueDate(int date)
{
    if (dateTree.search(root, date)) {
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
    cout << endl;
}

//function to search BST of course name values by course name
void Student::searchByCourse(string name)
{
    if (courseTree.search(strRoot, name)) {
        cout << "Here are all assignments due from " << name << ": " << endl;
        for (int i = 0; i < assignments.size(); i++) {
            //display any asignments with that due date if the due date is found in the BST
            if (assignments[i].getCourseName() == name) {
                assignments[i].displayAssignment();
            }
        }
    }
    else
        cout << "We did not find a class due in " << name << "." << endl;
    cout << endl;
}

//display due dates from BST
void Student::displayDueDates()
{
    dateTree.Inorder(root);
}

//display all course names from BST
void Student::displayCourseNames()
{
    courseTree.InorderString(strRoot);
}

//function to remove assignment by courseName
void Student::removeAssignment(string name)
{
    for (int i = 0; i < assignments.size(); i++) {
        if (assignments[i].getCourseName() == name) {
            courseTree.removeNode(strRoot, assignments[i].getCourseName());
            assignments.erase(assignments.begin()+i);
            i--;
        }
    }

    cout << name << " assignments have been removed." << endl;
}

void Student::saveToFile()
{
    ofstream MyFile("Text.txt");
    for (int i = 0; i < assignments.size(); i++) {
        MyFile << assignments[i].getCourseName() << "," << assignments[i].getDueDate() << "," << assignments[i].isAssignmentCompleted() << endl;
    }
}

void Student::readFromFile()
{
    string text;
    int counter = 0;
    string due;
    int dueDate;
    string nm;
    bool isComp;
    string isCompleted;
 
    MyTextFile.open("Text.txt");
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyTextFile, text)) {
  
      
        //get saved assignments from file
        nm = text.substr(0, text.find(","));

        text.erase(0, text.find(",") + 1);
        due = text.substr(0, text.find(","));
   
        text.erase(0, text.find(",") + 1);
        isCompleted = text;
    

        dueDate = stoi(due);
        isComp = stoi(isCompleted);

        assignments.push_back(Assignment(dueDate, nm, isComp));

        //insert values into both BSTs
        if (counter == 0) {
            root = dateTree.Insert(root, assignments[counter].getDueDate());
            strRoot = courseTree.Insert(strRoot, assignments[counter].getCourseName());
        }
        else {
            dateTree.Insert(root, assignments[counter].getDueDate());
            courseTree.Insert(strRoot, assignments[counter].getCourseName());
        }
        counter++;
    }

    // Close the file
    MyTextFile.close();
}

//display all assignments regardless of completion status
void Student::displayAssignments()
{
    for (int i = 0; i < assignments.size(); i++) {
        assignments[i].displayAssignment();
    }

    cout << endl;
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
        transform(response.begin(), response.end(), response.begin(), ::toupper);
        if (response == "Y")
            isComp = true;
        else
            isComp = false;

        //add assignment object to vector of assignments
        assignments.push_back(Assignment(due, nm, isComp));

        //insert values into both BSTs
        if (counter == 0) {
            root = dateTree.Insert(root, assignments[counter].getDueDate());
            strRoot = courseTree.Insert(strRoot, assignments[counter].getCourseName());
        }
        else {
            dateTree.Insert(root, assignments[counter].getDueDate());
            courseTree.Insert(strRoot, assignments[counter].getCourseName());
        }


        counter++;


    }
}


