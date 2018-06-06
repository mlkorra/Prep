#include <bits/stdc++.h>
using namespace std;



int main()
{
	int t;cin>>t;
	while(t--){

		int i,j,n;cin>>n;
		int v[n];
		for(i=0;i<n;i++){
			cin>>v[i];
		}

		/* Find all the increasing subsequences and their respective sum's,finally the maxi of them*/
		/* Increasing Subsequence starting from every element in the array*/
		int sum(0),max_sum(0);
		int max_so_far;
		for(i=0;i<n;i++){
			sum = v[i];
			max_so_far = v[i];
			for(j=i;j<n;j++){
				if(v[j]>max_so_far){
					max_so_far = v[j];
					sum += max_so_far; 
				}
			}
			if(sum > max_sum){
				max_sum = sum;
			}
		}

	cout << max_sum << endl;

	}

	return 0;
}