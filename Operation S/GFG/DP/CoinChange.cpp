/*
Coin Change
Objective : Given a value N,find the ways to make change for N,given 
			infinite supply of each S={s1,s2,...}

Observation : In the problem,there is no way mentioned about any
			  Maximum or  Minimum to give us hint to solve using DP
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int N,j,i,m;cin>>m;
		int A[m];
		for(i=0;i<m;i++){
			cin>>A[i];
		}
		cin>>N;
		int dp[N+1];
		memset(dp,0,sizeof(dp));
		/* Base Cases */
		dp[0]=1;
		
		for(i=0;i<m;i++){
			for(j=A[i];j<=N;j++){
				dp[j] += dp[j-A[i]];
			}
		}

		/*
		for(i=0;i<=N;i++){
			for(j=0;j<m;j++){
				if(i-A[j]>=0){
					dp[i] += dp[i-A[j]];
				}	
			}
 		}
 		*/

 		cout << dp[N] << endl;
	} 	
	return 0;
}