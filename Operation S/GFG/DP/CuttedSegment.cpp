/*
Cutting Segment Problem
Objective : Cut the Rod in the lengths of either x,y,z ,such that
			after cutting,the no.of segments are maximum 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int i,n;cin>>n;
		int x,y,z;
		int seg[3];
		for(i=0;i<3;i++){
			cin>>seg[i];
		}

		/* L[i] stores the Max no.of segments that can be cut of given rod length i*/
		int L[n+1];
		for(i=0;i<=n;i++){
			L[i] = INT_MIN;
		}
		L[0] = 0;
		int j;
		for(i=0;i<=n;i++){
			for(j=0;j<3;j++){
				if(i-seg[j]>=0){

					int sub_res = L[i-seg[j]];
					if(sub_res!=INT_MIN && 1+sub_res>L[i]){
						L[i] = 1+sub_res;
					}
				}
			}
		}

		cout << L[n] << endl;

	}
	return 0;
}