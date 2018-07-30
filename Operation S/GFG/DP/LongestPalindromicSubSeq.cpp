/*
Length of Longest Palindromic Subsequence 
Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int i,j,k;
		string s;cin>>s;
		int l = s.length();

		int dp[l+1][l+1];

		for(i=1;i<=l;i++){
			dp[i][i] = 1;
		}
		
		for(i=2;i<=l;i++){
			for(j=0;j<l-i+1;j++){
				k = j+i-1;
				if(s[j]==s[k] && i==2){
					dp[j][k] = 2;
				}
				else if(s[j]==s[k]){
					dp[j][k] = dp[j+1][k-1]+2;
				}
				else{
					dp[j][k] = max(dp[j+1][k],dp[j][k-1]);
				}
			}
		}

		cout << dp[0][l-1] << endl;
	}	

	return 0;
}