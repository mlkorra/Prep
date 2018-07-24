/*
Longest Common Subsequence (LCS)
Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int max(int a,int b){
	return (a>b)?a:b;
}

int main()
{
	int t;cin>>t;
	while(t--){
		int i,j,m,n;cin>>m>>n;
		string s1,s2;		
		cin>>s1;
		cin>>s2;
		int count=0;
		int dp[m+1][n+1];
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){

				if(i==0 || j==0){
					dp[i][j]=0;
				}

				else if(s1[i-1]==s2[j-1]){
					
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout << dp[m][n] << endl;
	}

	return 0;
}