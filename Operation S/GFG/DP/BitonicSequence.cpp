/*
Maximum Length of Bitonic Sequence
Dynamic Programming
*/

/*
Approach : Find the LIS array LIS[i],where ith element is the last element of that array.
		   also,find Longest Decreast Subsequence LDS[i],where  ith element is the starting element of that array 
		   Finally,find the index with maximum value of 'LIS[i] + LDS[i] -1' 	 
		   */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int i,j;
		int A[n];
		for(i=0;i<n;i++){
			cin>>A[i];
		}

		int dp_i[n],dp_d[n];
		for(i=0;i<n;i++){
			dp_i[i] = dp_d[i] = 1;
		}
		
		for(i=1;i<n;i++){
			for(j=0;j<i;j++){
				if(A[i] > A[j]){
					dp_i[i] = max(dp_i[j]+1,dp_i[i]);
				}			
			}
		}

		for(i=n-2;i>=0;i--){
			for(j=n-1;j>i;j--){
				if(A[i] > A[j]){
					dp_d[i] = max(dp_d[j]+1,dp_d[i]);
				}			
			}
		}

		int res=INT_MIN;

		for(i=0;i<n;i++){
			if(res<dp_i[i]+dp_d[i]-1){
				res = dp_i[i] + dp_d[i]-1;
			}
		}

		cout << res << endl;

	}
	return 0;
}