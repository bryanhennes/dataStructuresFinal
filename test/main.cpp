#include <iostream>
#include "Student.h"
#include "BST.h"
#include "Assignment.h"
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;



int main() {

	Student bryan = Student("Bryan", 28);
    int searchVal;
    int numOfAssignments = 0;
    string choice;
    //load previously saved assignments
    bryan.readFromFile();


    cout << "Welcome to the ultimate school assignment organzization tool!" << endl;

    //create menu
    while (choice != "E") {
        cout << "\nWhat would you like to do ? \n[A]Add assignments\n[U]Update Assignment Due Dates\n[V]View Assignments\n[I]View Assignments Currently in Progress\n[D]Search by Due Date\n[N]Search by Course Name\n[R]Remove Assignments\n[E]Exit\n->";
        cin >> choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
        if (choice == "A") {
            cout << bryan.getName() << ", Enter how many assignments you have to add: ";
            cin >> numOfAssignments;
            bryan.setAssignments(numOfAssignments);
            bryan.addAssignment();
        }
        else if (choice == "U")
            bryan.changeDueDate();
        else if (choice == "V")
            bryan.displayAssignments();
        else if (choice == "I")
            bryan.displayInProgress();
        else if (choice == "D") {
            cout << "Enter due date to search for: ";
            int searchNum;
            cin >> searchNum;
            bryan.searchByDueDate(searchNum);
        }
        else if (choice == "N") {
            cout << "Enter course name to search for: ";
            string searchName;
            cin >> searchName;
            bryan.searchByCourse(searchName);
        }
        else if (choice == "R") {
            cout << "Enter what course you want to remove assignments for: ";
            string searchName;
            cin >> searchName;
            bryan.removeAssignment(searchName);
        }
        else
            cout << "Please enter a valid option: " << endl;
           

    }
    bryan.saveToFile();
  


	return 0;
}