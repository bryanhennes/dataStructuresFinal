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

    //key is greater than root's key
    if (strRoot->strData < value)
        return search(strRoot->right, value);

    //key is smaller than root's key
    return search(strRoot->left, value);
}

//remove assignment node with specific course name
BST* BST::removeNode(BST* root, string name)
{
    // base case
    if (root == NULL)
        return root;

    //if key to be deleted is smaller than the root's key, then it lies in left subtree
    if (name < root->strData)
        root->left = removeNode(root->left, name);

    //if key to be deleted is greater than the root's key, then it lies in right subtree
    else if (name > root->strData)
        root->right = removeNode(root->right, name);

    // if key is same as root's key, then this is the node to be deleted
    else {
        //node has no child
        if (root->left == NULL and root->right == NULL)
            return NULL;

        //node with only one child or no child
        else if (root->left == NULL) {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BST* temp = root->left;
            free(root);
            return temp;
        }

        return root;
    }
}



// Insert function definition.
BST* BST::Insert(BST* root, int value)
{
    if (!root) {
        //insert the first node if root is NULL
        return new BST(value);
    }

    //insert data
    if (value > root->data) {
        // insert right node data if the value to be isnerted is greater than root node data
        root->right = Insert(root->right, value);
    }
    else {
        //insert left node data, if the value to be inserted is greater than root node data
        root->left = Insert(root->left, value);
    }

    //return root node after insertion
    return root;
}

//insert function definition for string values
BST* BST::Insert(BST* strRoot, string value)
{
    if (!strRoot) {
        //insert the first node if root is NULL
        return new BST(value);
    }

    //insert data
    if (value > strRoot->strData) {

        // insert right node data if the value to be isnerted is greater than root node data
        strRoot->right = Insert(strRoot->right, value);
    }
    else {
        //insert left node data, if the value to be inserted is greater than root node data
        strRoot->left = Insert(strRoot->left, value);
    }

    //return root node after insertion
    return strRoot;
}

//display due date values from due date BST
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