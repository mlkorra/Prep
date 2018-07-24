/*

0-1 Knapsack Problem
Dynamic Problem

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{	
		int i,j,n;cin>>n;
		int W;cin>>W;
		int val[n],w[n];
		
		for(i=0;i<n;i++){
			cin>>val[i];
		}
		
		for(i=0;i<n;i++){
			cin>>w[i];
		}

		int dp[n+1][W+1];

		for(i=0;i<=n;i++){
			for(j=0;j<=W;j++){
				if(i==0 || j==0){
					dp[i][j] = 0;
				}
				else if(w[i-1]<=j){
					dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j-w[i-1]]);
				}
				else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		cout << dp[n][W] << endl;

	}

	return 0;
}