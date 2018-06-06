#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){
		int i,n;cin>>n;
		int A[n];
		int sum_total(0);
		int cum_sum[n];
		
		for(i=0;i<n;i++){
			cin>>A[i];
			sum_total+=A[i];
			if(!i) cum_sum[i]=A[i];
			else cum_sum[i] = cum_sum[i-1]+A[i];
				
		}

		if(n==1) {
			cout << 1 << endl;
			continue;
		}

		if(n==2){
			cout << -1 << endl;
			continue;
		}

		int flag=0,eq_point;
		for(i=1;i<n;i++){
			if(cum_sum[i-1]==(sum_total-cum_sum[i])) {
				eq_point = i;
				flag=1;
				break;

			}
		}

		if(!flag) cout << -1 << endl;
		else cout << eq_point+1<< endl;

	}	

	return 0;
}