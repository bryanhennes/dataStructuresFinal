#include <iostream>
#include "Student.h"
#include "BST.h"
#include "Assignment.h"
#include <vector>
#include <string>

using namespace std;



int main() {

	Student bryan = Student("Bryan", 28);
	//cout << bryan.getName();
    int searchVal;
    int numOfAssignments = 0;
    string choice;

    //create menu

    while (choice != "E") {
        cout << "Welcome to the ultimate school assignment organzization tool! What would you like to do?\n[A]Add assignments\n[U]Update Assignment Due Dates\n[V]View Assignments\n[E]Exit";
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

    }
   //cout << ", Enter how many assignments you have: ";
   /* cin >> numOfAssignments;
    bryan.setAssignments(numOfAssignments);
    bryan.addAssignment();
    bryan.displayAssignments();*/
    
  
    

 
    
    /*BST b, * root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Inorder(root);*/

    /*cout << "Enter value to search for: ";
    cin >> searchVal;

    bool val = b.search(root, searchVal);
    cout << val;*/


	return 0;
}