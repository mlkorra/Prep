#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main()
{

	int start_s  = clock();
	int t;cin>>t;
	while(t--){
		int miss(1),i,n;cin>>n;
			
		for(i=2;i<=n;i++){
			miss = miss^i;
		}

		vector<int> v(n-1);
		for(i=0;i<n-1;i++){
			cin>>v[i];
			miss = miss^v[i];
		}

		cout << miss << endl;

	}
	int stop_s = clock();
	cout << "Execution Time : " <<  (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	return 0;
}