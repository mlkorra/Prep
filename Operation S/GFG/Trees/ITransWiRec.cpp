#include <bits/stdc++.h>
#include <stack>
using namespace std;

struct Node{

	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){

	struct Node *newnode = new Node;
	newnode->left = newnode->right = NULL;
	newnode->data = data;
}

void InorderTraversalIterative(struct Node *root)
{

	stack<Node *> s;
	Node *curr = root;

	while(curr!=NULL || s.empty() == false)
	{
		while(curr!=NULL){
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		s.pop();

		cout << curr->data << " ";

		curr = curr->right;
	}
}

int main()
{

	struct Node* root = newNode(1);
	root->left = newNode(3);
	root->right = newNode(5);
	root->left->left = newNode(10);
	root->left->right = newNode(20);

	InorderTraversalIterative(root);

	return 0;
}