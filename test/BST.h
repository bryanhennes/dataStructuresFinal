#pragma once
#include "Assignment.h"
#include <iostream>
using namespace std;

class BST {
    int data;
    string strData;
    BST* left, * right;

    public:
        // Default constructor.
        BST();

        // Parameterized constructor for due date BST
        BST(int);

        // Parameterized constructor for course name BST
        BST(string);

        // Insert function for due date values
        BST* Insert(BST*, int);

        // Insert function for course name values
        BST* Insert(BST*, string);

        // Search Function for due date values
        BST* search(BST*, int);

        // Search Function for course name values
        BST* search(BST*, string);

        // Inorder traversal of due date values
        void Inorder(BST*);

        // Inorder traversal of course name values
        void InorderString(BST*);
    };

    

    

  

