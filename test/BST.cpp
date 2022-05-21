#include "BST.h"
#include "Assignment.h"
// Default Constructor definition.
BST::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

// Parameterized Constructor definition.
BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

//Parameterized Constructor definition for string values
BST::BST(string value)
{
    strData = value;
    left = right = NULL;
}

BST* BST::search(BST* root, int value) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == value)
        return root;

    // Key is greater than root's key
    if (root->data < value)
        return search(root->right, value);

    // Key is smaller than root's key
    return search(root->left, value);

}

BST* BST::search(BST* strRoot, string value)
{
    if (strRoot == NULL || strRoot->strData == value)
        return strRoot;

    // Key is greater than root's key
    if (strRoot->strData < value)
        return search(strRoot->right, value);

    // Key is smaller than root's key
    return search(strRoot->left, value);
}

// Insert function definition.
BST* BST::Insert(BST* root, int value)
{
    if (!root) {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    // Insert data.
    if (value > root->data) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}

// Insert function definitionf or string values
BST* BST::Insert(BST* strRoot, string value)
{
    if (!strRoot) {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    // Insert data.
    if (value > strRoot->strData) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        strRoot->right = Insert(strRoot->right, value);
    }
    else {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        strRoot->left = Insert(strRoot->left, value);
    }

    // Return 'root' node, after insertion.
    return strRoot;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

//display string value BST for course name
void BST::InorderString(BST* strRoot)
{
    if (!strRoot) {
        return;
    }
    InorderString(strRoot->left);
    cout << strRoot->strData << endl;
    InorderString(strRoot->right);
}