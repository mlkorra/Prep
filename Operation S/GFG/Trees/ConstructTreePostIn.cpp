/*
Construct Tree from Post Order Travsersal and Inorder Traversal
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node *left;
	Node *right;
};

struct Node *newNode(int data)
{
	struct Node *newnode = new Node;
	newnode->data = data;
	newnode->left = newnode->right = NULL;

	return newnode;
}

int search(int A[],int start,int end,int x)
{
	int i;
	for(i=start;i<end;i++){
		if(A[i]==x) break;
	}
	return i;
}

struct Node *BuildTreeHelper(int in[],int pre[],int start,int end,int *n)
{
	if(start>end) return NULL;
	struct Node *node = newNode(pre[*n]);
	(*n)--;

	if(start==end) return node;
	int index = search(in,start,end,node->data);

	node->right = BuildTreeHelper(in,pre,index+1,end,n);
	node->left  = BuildTreeHelper(in,pre,start,index-1,n);

	return node;
}

Node *BuildTree(int in[],int pre[],int n)
{
	int index=n-1;
	return BuildTreeHelper(in,pre,0,n-1,&index);
}

void preorder(Node *root)
{
	if(root!=NULL){

		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	int t;cin>>t;
	while(t--){
		int i,n;cin>>n;
		int in[n],post[n];
		for(i=0;i<n;i++){
			cin>>in[i];
		}
		for(i=0;i<n;i++){
			cin>>post[i];
		}

		Node *root = BuildTree(in,post,n);
		preorder(root);
	}
}
/*

int search(int A[],int start,int end,int x)
{
	int i;
	for(i=start;i<end;i++){
		if(A[i]==x) break;
	}
	return i;
}

struct Node *BuildTreeHelper(int in[],int pre[],int start,int end,int *n)
{
	if(start>end) return NULL;
	struct Node *node = newNode(pre[*n]);
	(*n)--;

	if(start==end) return node;
	int index = search(in,start,end,node->data);

	node->right = BuildTreeHelper(in,pre,index+1,end,n);
	node->left  = BuildTreeHelper(in,pre,start,index-1,n);

	return node;
}

Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    int index=n-1;
    return BuildTreeHelper(in,post,0,n-1,&index);
}

*/
