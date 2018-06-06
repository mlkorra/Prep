
/*

Problem Statement:  Trapping Rain Water (https://www.geeksforgeeks.org/trapping-rain-water/)

Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){
		int i,n;cin>>n;
		int A[n];
		for(i=0;i<n;i++){
			cin>>A[i];
		}

		int R[n]; // Maintains the Largest Height to the Right of i'th block(including itself)
		int L[n]; // Maintains the Largest Height to the Left of i'th block(including itself)
		L[0] = A[0];
		for(i=1;i<n;i++){
			L[i] = max(L[i-1],A[i]);
 		}
 		R[n-1] = A[n-1];
 		for(i=n-2;i>=0;i--){
 			R[i] = max(R[i+1],A[i]);
 		}
 		int water = 0;
 		/*
			Calculate the Amount of trapped water by traversing across the array on each element(block)
 		*/

 		for(i=0;i<n;i++){
 			water += min(L[i],R[i])-A[i];
 		}

 		cout << water << endl;
	}

	return 0;
}