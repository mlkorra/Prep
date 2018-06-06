#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main()
{	
	int start_s = clock();

	int t;cin>>t;
	while(t--){
		int i,n;cin>>n;
		vector<int> v(n-1);
		int sum = 0;
		for(i=0;i<n-1;i++){
			cin>>v[i];
			sum += v[i];
		}

		cout << n*(n+1)/2 - sum << endl;

	}
	int stop_s = clock();

	cout << "Execution Time : " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	return 0;
}