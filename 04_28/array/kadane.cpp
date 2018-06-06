#include <bits/stdc++.h>
using namespace std;

int main()
{	
	int t;cin>>t;
	
	while(t--){
			
		int n,i;cin>>n;
		int v[n];

		for(i=0;i<n;i++){
			cin>>v[i];
		}

		int dp[n];
		memset(dp,0,sizeof(dp));

		int sum = v[0];
		for(i=1;i<n;i++){
			if(sum+v[i]>0){
				sum += v[i];
				dp[i] = max(dp[i],sum);
			}
		}
		
		cout << dp[n-1] << endl;

	}

	return 0;
}