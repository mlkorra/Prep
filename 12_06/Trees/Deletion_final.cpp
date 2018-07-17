/*

Trees : Deletion

Complexity : O(h),h : Height of the Tree

*/

#include <bits/stdc++.h>
using namespace std;

struct Node{

	int key;
	struct Node *left,*right;
};

struct Node* newNode(int key)
{

	struct Node *temp = new Node;
	temp->key = key;
	temp->left=temp->right = NULL;
	
	return temp;
}

void InorderTraversal(struct Node *root)
{
	if(!root){
		return;
	}

	InorderTraversal(root->left);
	cout << root->key << " ";
	InorderTraversal(root->right);

}

void delete_deepnode(struct Node *root,struct Node* del_node)
{

	queue<struct Node*> q;
	q.push(root);

	struct Node *temp;
	while(!q.empty()){

		temp = q.front();
		q.pop();

		if(temp->right){
			if(temp->right == del_node){
				temp->right = NULL;
				delete(del_node);
				return;
			}
			else{
				q.push(temp->right);
			}
		}		

		if(temp->left){
			if(temp->left == del_node){
				temp->left = NULL;
				delete(del_node);
				return;
			}
			else{
				q.push(temp->left);
			}
		}
	}
}

void Deletion(struct Node *root,int del_key)
{	

	queue<struct Node*> q;
	q.push(root);

	struct Node *temp;
	struct Node *key_node = NULL;
	while(!q.empty()){

		temp = q.front();
		q.pop();

		if(temp->key == del_key){
			key_node = temp;
		}

		if(temp->left){
			q.push(temp->left);
		}

		if(temp->right){
			q.push(temp->right);
		}

	}
		/* temp obtained from above is the deepest,to be replaced with the node to be deleted */ 
		int x = temp->key;
		delete_deepnode(root,temp);
		key_node->key = x;
}


int main()
{
	struct Node *root = newNode(10);
	root->left = newNode(11);
	root->right = newNode(12);
	root->left->left = newNode(9);
	root->left->right = newNode(8);
	root->right->left = newNode(7);

	cout << "Before Insertion\n";
	InorderTraversal(root);

	int key = 9;
	Deletion(root,key);
	cout << "After deletion\n";
	InorderTraversal(root);

	
	key = 7;
	Deletion(root,key);
	cout << "After deletion\n";
	InorderTraversal(root);

	return 0;
}