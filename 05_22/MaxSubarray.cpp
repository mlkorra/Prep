
/*
https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

Author : K R D
Compiler used : g++
OS : Ubuntu 16.04

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){

		int i,k,n;cin>>n>>k;

		/*
		Use Queue for storing indices
		*/
		deque<int> Q(k);
		int  A[n];

		for(i=0;i<n;i++){
			cin>>A[i];
		}
		
		for(i=0;i<k;i++){

			/*
			Remove from Queue if the new element to be inserted is greater than all the elements to it's left 
			*/
			while(!Q.empty() && A[i]>A[Q.back()]){
				Q.pop_back();
			}

			Q.push_back(i);

		}

		for(;i<n;i++){

			printf("%d ",A[Q.front()]);

			/*
			Remove all the elements which doesn't belong to the current window
			*/
			while(!Q.empty() && Q.front() <= i-k){
				Q.pop_front();
			}

			/*
			Remove elements from Q,if the new  element to be inserted is greater than all the elements to it's lefts
			*/

			while(!Q.empty() && A[i]>=A[Q.back()]){
				Q.pop_back();
			}

			Q.push_back(i);
		}

		/*
		Print the MaX element of the last Window
		*/
		printf("%d\n",A[Q.front()]);
		Q.clear();

	}

	return 0;
}