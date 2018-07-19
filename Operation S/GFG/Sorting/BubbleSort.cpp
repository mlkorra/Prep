/*
Bubble Sorting :
Worst Case Complexity : O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int A[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++){

		for(j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]) swap(A[j],A[j+1]);
		}
	}
}

void printArray(int A[],int n)
{
	int i;
	for(i=0;i<n;i++){
		cout << A[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int i,n;cin>>n;
		int A[n];
		for(i=0;i<n;i++){
			cin>>A[i];
		}

		BubbleSort(A,n);

		printArray(A,n);
	}

	return 0;
}
