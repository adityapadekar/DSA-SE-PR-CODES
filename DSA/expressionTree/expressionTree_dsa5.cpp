/*

Construct an expression tree from the given prefix expression eg. +--a*bc/def
and traverse it using post order traversal (non recursive) and then delete the entire tree.

*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class node
{
public:
	char data;
	node *left, *right;
	node(char val) : data(val), left(NULL), right(NULL) {}
};

string acceptExpression()
{
	string expression;
	cout << "Enter the Expression : ";
	cin >> expression;
	return expression;
}

node *convertExpressionIntoTree(string expression)
{
	// int len = expression.size();
	stack<node *> s;
	for (auto i = expression.rbegin(); i != expression.rend(); i++)
	{
		// char ch = expression[i];
		// cout << *i << endl;
		if ((*i >= 'a' && *i <= 'z') || (*i >= 'A' && *i <= 'Z') || (*i >= '0' && *i <= '9'))
		{
			node *temp = new node(*i);
			s.push(temp);
		}
		else
		{
			node *op = new node(*i);
			op->left = s.top();
			s.pop();
			op->right = s.top();
			s.pop();
			s.push(op);
		}
	}

	return s.top();
}

// non rec post order
void nonRecPostOrder(node *root)
{
	stack<node *> s1, s2;

	node *temp = root;

	s1.push(temp);

	while (!s1.empty())
	{

		temp = s1.top();
		s1.pop();
		s2.push(temp);
		if (temp->left != nullptr)
			s1.push(temp->left);
		if (temp->right != nullptr)
			s1.push(temp->right);
	}
	while (!s2.empty())
	{
		cout << s2.top()->data;
		s2.pop();
	}
}

void postorder(node *root)
{
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}
int main()
{

	string expression = "+--a*bc/def";
	node *root = convertExpressionIntoTree(expression);
	cout << expression << endl;
	postorder(root);
	cout << endl;
	nonRecPostOrder(root);

	return 0;
}