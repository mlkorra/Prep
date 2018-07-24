/*

Minimum Cost Path
Objective : Find the Minimum cost path from (0,0) to (m,n)
Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int i,j,m,n;cin>>m>>n;
		int cost[3][3];
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				cin>>cost[i][j];
			}
		}

		int dp[3][3];
		dp[0][0] = cost[0][0];
		
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){

				/*
				 0,0	
				  _______
				 |_|	 |	 	
				 |		 |
				 |	 __	 | 	
				 |	|__| |m,n	
				 |_______|

				*/

				/*1. First Row */
				if(i==0){
					dp[0][j] = dp[0][j-1]+cost[0][j];
				}
				/*2. Second Row*/
				else if(j==0){
					dp[i][0] = dp[i-1][0] + cost[i][0]; 
				}
				/*3. Remaining Matrix */
				else{
					dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + cost[i][j];	
				}
			}
		}

		cout << dp[m][n] << endl;
	}

	return 0;
}