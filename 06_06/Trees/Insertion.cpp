/*

Tree DataStructure

Insertion
Complexity : Binary Tree Worst Case Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

/* Defining the Structure of the Tree*/
struct Node{

	int key;
	struct Node *left,*right;
};

/* Struct to create NewNode in the Tree*/
struct Node* NewNode(int key)
{
	struct Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

/*Inorder Traversal*/
void InorderTraversal(struct Node* temp)
{
	if(!temp) 
		return;
	
	InorderTraversal(temp->left);
	cout << temp->key << " ";
	InorderTraversal(temp->right);
	
}

/*Function to insert node in Binary Tree*/
void insert(struct Node* root,int key)
{

	/* Travere Level Order from the Root*/
	/* And Insert the node,wherever you find an empty child(either left or right) for a given node*/

	queue<struct Node*> q;
	q.push(root);

	while(!q.empty()){

		struct Node *temp = q.front();
		q.pop();

		if(!temp->left){
			temp->left = NewNode(key);
			break;
		}
		else{
			q.push(temp->left);
		}

		if(!temp->right){
			temp->right = NewNode(key);
			break;
		}
		else{
			q.push(temp->right);
		}
	}

}

int main()
{

	struct Node* root = NewNode(10);
	root->left = NewNode(11);
	root->right = NewNode(12);
	root->left->left = NewNode(9);
	root->left->right = NewNode(8);
	root->right->left = NewNode(13);

	cout << "Before Insertion\n";
	InorderTraversal(root);

	insert(root,100);

	cout << "After Insertion\n";
	InorderTraversal(root);


	return 0;
}