#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main()
{
	int start_s = clock();
	int t;cin>>t;
	while(t--){
		int i,n;cin>>n;
		int A[n],Max[n];
		for(i=0;i<n;i++){
			cin>>A[i];
			Max[i] = A[i];
		}

		/* Kadane Starts here*/
		for(i=1;i<n;i++){
			if(Max[i-1]+A[i]>0){
				Max[i] = max(Max[i-1]+A[i],Max[i]);
			}	
		}

		int max = INT_MIN;
		for(i=0;i<n;i++){
			if(Max[i]>max){
				max = Max[i];
			}
		}

		cout << max << endl;
	}
	int stop_s = clock();

	cout << "Execution Time : " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}