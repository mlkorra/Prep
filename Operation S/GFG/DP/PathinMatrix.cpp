/*
Path in Matrix
Objective : Find the Largest sum of path from any of the columns in Row 0 to Row N-1

DYNAMIC PROGRAMMING
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int i,j,n;cin>>n;
		int dp[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>dp[i][j];
			}
		}

		/*
		Can move in three directions 
		Bottom
		Diagonal Right
		Diagonal Left
		*/
		for(i=1;i<n;i++){
			for(j=0;j<n;j++){

				/* Three cases */
				/*1. All Moves possible */
				if(j>0 && j<n-1){
					dp[i][j] += max(max(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
				}
				/*2. Diagonal Right not possible */
				else if(j>0){
					dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
				}
				/*3. Diagonal Left not possible */
				else{
					dp[i][j] += max(dp[i-1][j],dp[i-1][j+1]);
				}
			}
		}

		int max_sum = 0;
		for(i=0;i<n;i++){
			max_sum = max(dp[n-1][i],max_sum);
		}

		cout << max_sum << endl;
	}

	return 0;
}