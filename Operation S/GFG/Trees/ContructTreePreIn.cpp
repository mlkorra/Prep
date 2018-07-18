/*
Construct Binary Tree from Pre Order and Inorder Traversal
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node *left;
	Node *right;

};

Node *BTHelper(int in[],int pre[],int istrt,int iend,int &j)
{
	if(istrt > iend){
		return NULL;
	}
	j++;
	int i;
	for(i=istrt;i<=iend;i++){
		if(in[i]==pre[j]) break;
	}

	Node *head = newNode(pre[j]);
	head->left = BTHelper(in,pre,istrt,i-1,j);
	head->right = BTHelper(in,pre,i+1,iend,j);

	return head;
}

Node *buildTree(int in[],int pre[],int str,int end){

	int j=-1;
	return BTHelper(in,pre,str,end,j);
}