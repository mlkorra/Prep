
/*

Problem Statement : https://www.geeksforgeeks.org/trapping-rain-water/

Space Complexity : O(1)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--)
	{
		int n,i;cin>>n;
		int A[n];
		for(i=0;i<n;i++){
			cin>>A[i];
		}

		int water=0;
		int l=0,h=n-1;
		int left_max(0),right_max(0);

		while(l<h){

			if(A[l] < A[h]){

				if(A[l]>left_max){
					left_max = A[l];
				}

				else water+= left_max - A[l];

				l++;
			}

			else{

				if(A[h]>right_max){
					right_max = A[h];
				}
				else water += right_max - A[h];

				h--;
			}
		}

		cout << water << endl;
	}

	return 0;
}