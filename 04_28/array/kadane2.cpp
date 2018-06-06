#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main()
{

	int t;cin>>t;
	int start_s = clock();

	while(t--){

		int i,n;cin>>n;
		vector<int> v(n);

		for(i=0;i<n;i++){
			cin>>v[i];
		}	

		int curr_max = v[0];
		int max_so_far = v[0];

		for(i=1;i<n;i++){

			curr_max = max(curr_max+v[i],v[i]);
			max_so_far = max(max_so_far,curr_max);

		}	

		cout << max_so_far << endl;
	}

	int stop_s = clock();
	cout << "Execution Time : " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

	return 0;
}