#include  <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){
		int j,i,n;cin>>n;
		int A[n],DP[n];
		for(i=0;i<n;i++){
			cin>>A[i];
			DP[i] = A[i];
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				if(A[j]<A[i] && A[i]+DP[j]>DP[i]){
					DP[i] = A[i]+DP[j];
				}
			}
		}
	
		int max=INT_MIN;
		for(i=0;i<n;i++){
			if(DP[i]>max){
				max = DP[i];
			}
		}

		cout << max << endl;
	}	

	return 0;
}