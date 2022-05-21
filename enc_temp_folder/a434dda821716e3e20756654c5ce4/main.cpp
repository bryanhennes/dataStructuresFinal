#include <iostream>
#include "Student.h"
#include "BST.h"
#include "Assignment.h"
#include <vector>
#include <string>

using namespace std;



int main() {

	Student bryan = Student("Bryan", 28);
	cout << bryan.getName();
    int searchVal;
    int numOfAssignments = 0;
    vector<Assignment> assignments(numOfAssignments);
    

    cout << ", Enter how many assignments you have: ";
    cin >> numOfAssignments;
    bryan.setAssignments(numOfAssignments);
    //bryan.addAssignment();
    //bryan.displayAssignments();
    
    int counter = 0;
    int due;
    string nm;
    string response;
    bool isComp;
  
    while (counter < numOfAssignments) {
        cout << "Assignment " <<  counter+1 << " is due in how many days?: ";
        cin >> due;
        cout << "What class is assignment " << counter+1 << " for?: ";
        cin >> nm;
        cout << "Is assignment " << counter+1 <<  " completed?: Y or N: ";
        cin >> response;
        if (response == "Y")
            isComp = true;
        else
            isComp = false;

        //add assignment object to vector of assignments
        assignments[counter] = Assignment(due, nm, isComp);

        counter++;
        

    }

    //display all assignments
    for (int i = 0; i < assignments.size(); i++) {
        assignments[i].displayAssignment();
    }
    

 
    
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