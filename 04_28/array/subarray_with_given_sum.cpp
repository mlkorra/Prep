#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main()
{
	int t;cin>>t;
	while(t--){
		int i,n,s;cin>>n>>s;
		vector<int> v(n);
		
		int sum(0);
		for(i=0;i<n;i++){
			cin>>v[i];
			sum += v[i];
		}

		i = 0;
		j = n-1;
		int flag = 0;

		while(i<=j){
			
			if(sum == v[i] + v[j]){
				flag = 1;
				break;
			}	

			if(sum - v[i] >= s){
				sum -= v[i];
				i++;
			}

			if(sum - v[j] >= s){
				sum -= v[j];
				j--;
			}

			
		}

		if(!flag){
			cout << -1 << endl;
		}
		else{
			cout << i+1 << j+1 << endl;
		}

	}

	return 0;
}
