/*

Problem Statement :  Given an array of distinct elements Find the Kth Smallest Element.

Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partitionArr(int A[],int low,int high)
{
	int i,piv = A[high],j=low;

	for(i=low;i<high;i++){

		if(A[i]<=piv){
			swap(&A[i],&A[j]);
			j++;
		}	
	}
	swap(&A[j],&A[high]);
	return j;

}

int kthSmallest(int A[],int low,int high,int k)
{
	
	if(k>0  && k<= high-low+1){
		
		int pos = partitionArr(A,low,high);
		if(pos-low == k-1) return A[pos];
		if(pos-low > k-1) return kthSmallest(A,low,pos-1,k);
		else return kthSmallest(A,pos+1,high,k+low-pos-1);
	}

	return INT_MIN;

}

int main()
{

	int t;cin>>t;
	while(t--){
		
		int k,i,n;cin>>n;
		int A[n];
		for(i=0;i<n;i++){
			cin>>A[i];
		}
		cin>>k;

		cout << kthSmallest(A,0,n-1,k) << endl;

	}

	return 0;
}