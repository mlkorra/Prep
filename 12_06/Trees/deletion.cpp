/*

Trees : Deletion

Complexity : O(h),h : Height of the Tree

*/

#include <bits/stdc++.h>
using namespace std;
/*
Define the Tree Node
*/
struct Node{

	int key;
	struct Node *left,*right;
};

/* Function to create New Node */
struct Node* newNode(int key)
{

	struct Node* newnode = new Node;
	newnode->key = key;
	newnode->left = newnode->right = NULL;
	return newnode;
}


/* Perform an Level Order Traversal starting from the root
   and insert the newnode at available empty child.
*/

void insertion(Node *root,int key)
{

	queue<struct Node *> q;
	q.push(root);

	while(!q.empty()){

		struct Node *temp = q.front();
		q.pop();

		if(!temp->left){
			temp->left = newNode(key);
		}
		else{
			q.push(temp->left);
		}

		if(!temp->right){
			temp->right = newNode(key);
			break;
		}
		else{
			q.push(temp->right);
		}
	}
}

/* First Find the RightMost Node in the Tree,and then replace 'Node to be Deleted' with the Rightmost Node.
   Now,delete the RightMost Node	
*/

void deletion(Node *root,int del_key)
{
	
	/* First find the RightMost Node */
    struct Node *rightmost = root;
    struct Node *parent = newNode(0);

    while(!rightmost->right){
    	parent = rightmost;
    	rightmost = rightmost->right;
    }

    /* The obtained 'rightmost' from above is the Rightmost Node */

    /* Now,search for the del_key (Node to be deleted)*/
    queue<struct Node*> q;
    q.push(root);
    struct Node *search;
    while(!q.empty()){

    	search = q.front();
    	q.pop();

    	if(search->left->key == del_key){
    		search = search->left;
    		break;
    	}
    	else{
    		q.push(search->left);
    	}

    	if(search->right->key == del_key){
    		search = search->right;
    		break;
    	}
    	else{
    		q.push(search->right);
    	}

    }
    
    /* Now,replace the search key node(del_key) with rightmost node(rightmost node)*/
    search->key = rightmost->key;

    /* It's SHOW TIME */
    /* Delete the RightMost Node */
    parent->right = NULL;

}

void InorderTraversal(struct Node *root){

	if(!root){
		return;
	}

	InorderTraversal(root->left);
	cout << root->key << " ";
	InorderTraversal(root->right);
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

	insertion(root,123);

	cout << "After Insertion\n";
	InorderTraversal(root);
	int key = 9;
	deletion(root,key);
	cout << "After deletion\n";
	InorderTraversal(root);

	
	key = 123;
	deletion(root,key);
	cout << "After deletion\n";
	InorderTraversal(root);


	return 0;
}