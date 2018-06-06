#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){

		int j,i,n;cin>>n;
		int a[n];
		for(i=0;i<n;i++){
			cin>>a[i];
		}


		if(n==1){
			cout << 1 << endl;
			continue;
		}
		if(n==2){
			continue;
		}

		i=0;
		j=n-1;
		int sum_left=0,sum_right=0;
		int eq_point,flag(0);

		while(i<j){

			sum_left+= a[i];
			sum_right+= a[j];	
			
			i++;j--;

			if(sum_left==sum_right && i==j){
				eq_point = i;
				flag=1;
				break;
			}
		}

		if(flag) printf("%d\n",eq_point+1);
		else printf("%d\n",-1);

	}

	return 0;
}