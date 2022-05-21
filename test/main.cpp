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
    

    cout << ", Enter how many assignments you have: ";
    cin >> numOfAssignments;
    bryan.setAssignments(numOfAssignments);
    bryan.addAssignment();
    bryan.displayAssignments();
    
  
    

 
    
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