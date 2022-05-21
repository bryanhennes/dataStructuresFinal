#include <iostream>
#include "Student.h"
#include "BST.h"
#include "Assignment.h"
#include <vector>
#include <string>

using namespace std;



int main() {

	Student bryan = Student("Bryan", 28);
    int searchVal;
    int numOfAssignments = 0;
    string choice;

    //create menu
    while (choice != "E") {
        cout << "Welcome to the ultimate school assignment organzization tool! What would you like to do?\n[A]Add assignments\n[U]Update Assignment Due Dates\n[V]View Assignments\n[I]View Assignments Currently in Progress\n[D]Search by Due Date\n[N]Search by Course Name\n[E]Exit\n->";
        cin >> choice;

        if (choice == "A") {
            cout << bryan.getName() << ", Enter how many assignments you have: ";
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
           

    }
    //bryan.displayCourseNames();
  


	return 0;
}