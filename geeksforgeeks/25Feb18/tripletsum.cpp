/*
	Find a triplet in the array,whose sum is the given number
 	Expected Time Complexity : O(n2)
	
	Algorithm : As you need to find three numbers with given sum,
	first sort the Array elements and in the first loop you traverse till n-2 elements
	and in the next loop instead of traditional/brute force doing again the same  loop traversing
    over the array,instead keep twp pointers,one from front,one from back and keep changing 
    them whenver required as solved	 
 
 */


#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){
		int flag=0;
		int i,j,n,x;cin>>n>>x;
		int A[n];
		for(i=0;i<n;i++){
			cin>>A[i];
		}

		sort(A,A+n);
		int p1,p2;
		for(i=0;i<n-2;i++){
			p1 = i+1;
			p2 = n-1;

			while(p1<p2){

				if(A[i]+A[p1]+A[p2] == x){
					flag=1;i=n-2;
					break;
				}

				else if(A[i] + A[p1] + A[p2] < x){
					p1++;
				}
				else {
					p2--;
				}
			}


		}

		if(!flag){
			cout << flag << endl;
		}
		else cout << flag << endl;	
	}
	return 0;
}