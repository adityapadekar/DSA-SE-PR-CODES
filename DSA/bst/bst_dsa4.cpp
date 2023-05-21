/*

Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. After constructing a binary tree -
i. Insert new node, 
ii. Find number of nodes in longest path from root, 
iii. Minimum data value found in the tree, 
iv. Change a tree so that the roles of the left and right pointers are swapped at every node,
v. Search a value

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class node
{
public:
    int data;
    node *right, *left;
    node(int val) : data(val), right(NULL), left(NULL) {}
};


node *insertBst(node *root, int key)
{
    if (!root)
        return new node(key);
    else if (root->data > key)
        root->left = insertBst(root->left, key);
    else if (root->data < key)
        root->right = insertBst(root->right, key);
    return root;
}

int heightTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(heightTree(root->right), heightTree(root->left)) + 1;
}

int minValue(node *root)
{
    if (!root)
        return INT_MAX;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

bool searchValueInBST(node *root, int key)
{
    if (!root)
        return 0;
    else if (root->data == key)
        return 1;
    else if (root->data > key)
        return searchValueInBST(root->left, key);
    else
        return searchValueInBST(root->right, key);
}

bool searchValueInBST2(node *root, int key)
{
    if (!root)
        return 0;
    else if (root->data > key)
        return searchValueInBST(root->left, key);
    else if (root->data < key)
        return searchValueInBST(root->right, key);
    return 1;
}

node *mirror(node *root)
{
    if (!root)
        return NULL;
    mirror(root->left);
    mirror(root->right);
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = NULL;

    root = insertBst(root, 6);
    root = insertBst(root, 2);
    root = insertBst(root, 63);
    root = insertBst(root, 1);
    root = insertBst(root, 99);

    cout << endl;
    inorder(root);
    cout << endl;
    cout << heightTree(root) << endl;
    cout << minValue(root) << endl;
    cout << "SEARCH " << endl;
    cout << searchValueInBST(root, 62) << endl;
    cout << searchValueInBST2(root, 62) << endl;
    cout << "SEARCH " << endl;
    root = mirror(root);
    cout << endl;
    inorder(root);
    cout << endl;

    return 0;
}