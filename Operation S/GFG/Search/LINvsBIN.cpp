/*
Who will win?
Linear Search vs Binary Search,comparing the total time taken to search for an element
at a given index,also given time elapsed for each search
*/

#include <bits/stdc++.h>
using namespace std;

int bin_iter(int A[],int start,int end,int x)
{	
	if(start>end) return -1;

	int mid = (start+end)/2;
	if(A[mid]==x) return 1;

	/* Left SubArray */
	if(A[mid]>x) return 1+bin_iter(A,start,mid-1,x);
	else return 1+bin_iter(A,mid+1,end,x);
}

int main()
{
	int t;cin>>t;
	while(t--){
		int i,n,m,t1,t2;
		cin>>n>>m>>t1>>t2;

		int A[n];
		for(i=0;i<n;i++){
			A[i]=i;
		}

		int bin = bin_iter(A,0,n,m-1);

		int lin_time = t1*m;
		int bin_time = t2*bin;

		if(lin_time==bin_time) cout << 0 << endl;

		if(lin_time > bin_time) cout << 2 << endl;
		else cout << 1 << endl;

	}

	return 0;
}