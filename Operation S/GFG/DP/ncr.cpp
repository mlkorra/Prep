/*
Finding nCr for given n and r
Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		const unsigned int M = 1000000007;
		int j,i,n,r;
		cin>>n>>r;

		int dp[n+1][r+1];
		
		for(i=1;i<=n;i++){
			for(j=0;j<=min(i,r);j++){
				if(j==0 || j== i){
					dp[i][j] = 1;
				}
				else{
					dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%M;
				}
			}
		}

		cout << dp[n][r] << endl;
	}

	return 0;
}