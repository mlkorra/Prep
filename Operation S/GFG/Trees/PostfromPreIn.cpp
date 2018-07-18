/*
Post Order Traversal from Pre Order and Inorder Travsersal
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){

	struct Node* newnode = new Node;
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

int search(int A[],int x,int n)
{
	for(int i=0;i<n;i++){
		if(A[i]==x){
			return i;
		}
	}
	return -1;
}

void PrintPostOrder(int in[],int pre[],int n)
{
	int root = search(in,pre[0],n);	

	if(root!=0){
		PrintPostOrder(in,pre+1,root);
	}

	if(root!=n-1){
		PrintPostOrder(in+root+1,pre+root+1,n-root-1);
	}

	cout << pre[0] << " ";
}

int main()
{
	int in[] = {4,2,5,1,3,6};
	int pre[] = {1,2,4,5,3,6};
	int n = sizeof(in)/sizeof(in[0]);
	cout << "Post Order Travsersal" << endl;
	PrintPostOrder(in,pre,n);
	cout << "\n";
	
	return 0;
}