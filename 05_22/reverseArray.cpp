
/*
Problem Statement : https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0

Author : K R D
OS     : Ubuntu 16.04

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){

		int i,k,n;cin>>n;
		int A[n];

		for(i=0;i<n;i++){
			cin>>A[i];
		}

		cin>>k;

		for(i=0;i<n;i+=k){

			int left = i;

			int right = min(i+k-1,n-1);

			while(left<right){
				swap(A[left++],A[right--]);
			}
		}

		for(i=0;i<n;i++){
			printf("%d ",A[i]);
		}
		printf("\n");
	}

	return 0;
}