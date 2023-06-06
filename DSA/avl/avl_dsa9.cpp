/*
    A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
    deleting keywords, updating values of any entry. Provide facility to display whole data
    sorted in ascending/ Descending order. Also find how many maximum comparisons may require
    for finding any keyword. Use Height balance tree and find the complexity for finding a keyword.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class node
{
public:
    int keyword;
    string meaning;
    node *left, *right;
    int height;
    node(int key, string meaning) : keyword(key), meaning(meaning), left(NULL), right(NULL), height(0) {}
};

// calculate height
int height(node *root)
{
    if (!root)
        return 0;
    return root->height;
}

// get balance factor
int getBalance(node *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

node *rightRotate(node *root)
{

    node *mid = root->left;
    node *temp = mid->right;

    mid->right = root;
    root->left = temp;

    mid->height = max(height(mid->left), height(mid->right)) + 1;
    root->height = max(height(root->left), height(root->right)) + 1;

    return mid;
}

node *leftRotate(node *root)
{

    node *mid = root->right;
    node *temp = mid->left;

    mid->left = root;
    root->right = temp;

    mid->height = max(height(mid->left), height(mid->right)) + 1;
    root->height = max(height(root->left), height(root->right)) + 1;

    return mid;
}

node *insertNode(node *root, int key, string meaning)
{
    // cout << "1" << endl;

    if (!root)
    {
        return new node(key, meaning);
    }

    if (root->keyword > key)
        root->left = insertNode(root->left, key, meaning);
    if (root->keyword < key)
        root->right = insertNode(root->right, key, meaning);
    else
        return root;

    // cout << "2" << endl;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->keyword)
    {
        return rightRotate(root);
    }
    if (balance > 1 && key > root->left->keyword)
    {
        root->left = leftRotate(root);
        return rightRotate(root);
    }
    if (balance < -1 && key > root->right->keyword)
    {
        return leftRotate(root);
    }
    if (balance < -1 && key < root->right->keyword)
    {
        root->right = rightRotate(root);
        return leftRotate(root);
    }
    // cout << "3" << endl;
    return root;
}

node *minValue(node *root)
{

    while (!root && !root->left)
    {
        root = root->left;
    }

    return root;
}

node *deleteNode(node *root, int key)
{

    if (!root)
        return NULL;
    if (key < root->keyword)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->keyword)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key == root->keyword)
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else
        {
            root->keyword = minValue(root->right)->keyword;
            root->right = deleteNode(root->right, root->keyword);
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root);
        return leftRotate(root);
    }
    return root;
}

node *searchNode(node *root, int key)
{

    if (!root)
    {
        return NULL;
    }
    else if (root->keyword > key)
    {
        return searchNode(root->left, key);
    }
    else if (root->keyword < key)
    {
        return searchNode(root->right, key);
    }
    return root;
}

void updateNode(node *root, int key, string meaning)
{
    node *temp = searchNode(root, key);
    temp->meaning = meaning;
}

void ascending(node *root)
{
    if (!root)
        return;
    ascending(root->left);
    cout << root->keyword << ":" << root->meaning << " , ";
    ascending(root->right);
}

void descending(node *root)
{
    if (!root)
        return;
    descending(root->right);
    cout << root->keyword << ":" << root->meaning << " , ";
    descending(root->left);
}

int main()
{
// 5 6 8 15 21 25 45 85
    node *root = new node(21, "hii");
    root = insertNode(root, 15, "hii");
    root = insertNode(root, 6, "hii");
    root = insertNode(root, 8, "hii");
    root = insertNode(root, 45, "hii");
    root = insertNode(root, 5, "hii");
    root = insertNode(root, 25, "hii");
    root = insertNode(root, 85, "hii");
    cout << 1 << endl;
    ascending(root);
    cout << endl;
    cout << endl;
    cout << 2 << endl;
    int a = searchNode(root, 5) ? 1 : 0;
    cout<< a;
    cout << endl;
    cout << endl;
    cout << 3 << endl;
    root = deleteNode(root, 45);
    cout << endl;
    cout << 4 << endl;
    ascending(root);
    cout << endl;
    cout << endl;
    cout << 5 << endl;
    updateNode(root, 5, "you");
    cout << endl;
    cout << 6;
    cout << endl;
    ascending(root);
    cout << endl;
    cout << endl;

    cout << 7 << endl;
    descending(root);
    return 0;
}