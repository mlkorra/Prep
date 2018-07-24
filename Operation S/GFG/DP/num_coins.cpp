/*
Number of Coins : Minimum No of coins to make the change
Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int i,j,v,m,n;cin>>v>>n;
		int A[n];
		for(i=0;i<n;i++){
			cin>>A[i];
		}
		
		int dp[v+1];
		dp[0]=0;

		for(i=1;i<=v;i++){
			dp[i] = INT_MAX;
		}

		int res = INT_MAX;
		int sub_res;
		for(i=1;i<=v;i++){
			for(j=0;j<n;j++){
				if(A[j]<=i){
					sub_res = dp[i-A[j]];
					if(sub_res!=INT_MAX && sub_res+1 < dp[i]){
						dp[i] = 1+sub_res;
					}
				}
			}
		}
		cout << dp[v] << endl;
	}
	return 0;
}