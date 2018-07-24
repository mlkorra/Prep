/*
Longest Increasing Subsequence - (LIS)
Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int i,j,n;cin>>n;
		int A[n];
		if(n==0) cout << "0" << endl;
		else{

			for(i=0;i<n;i++){
			cin>>A[i];
			}

		/* array dp for maintaining the length of the LIS,from jth index to that index(ith) */	
		/*

		Array 'dp' is part of the memoization for storing the length of LIS till that corresponding element 
		in the Arrray.

		So,
		dp[i] = 1+Max(dp[j]) such that j<i and A[j]<A[i] or else
		if no such element exists
		dp[i] = 1
		
		*/

		int dp[n];
		for(i=0;i<n;i++){
			dp[i]=1;
		}	

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j<i && A[i]>A[j]){
					dp[i] = max(dp[j]+1,dp[i]);
				}
			}
		}

		cout << *max_element(dp,dp+n) << endl;
		//free(dp);


		}
	}

	return 0;
}
