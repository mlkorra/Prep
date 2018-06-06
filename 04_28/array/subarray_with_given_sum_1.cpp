#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--){

		int sum(0),j,i,n,s;cin>>n>>s;
		vector<int> v(n);
		vector<int> cum_sum(n);
			
		for(i=0;i<n;i++){
			cin>>v[i];
			sum += v[i];
			cum_sum[i] = sum;
		}

		/*Case 1: Sum S already exists in the Cumulative Sum Array*/ 
		int case_flag(0);
		for(i=0;i<n;i++){
			if(cum_sum[i]==s){
				cout << 1 << " " << i+1 << endl;
				case_flag = 1;
				break;
			}
		}

		/* Jump to the next test case*/
		//cout << case_flag << endl;
		if(case_flag) continue;

		i=0;
		j=n-1;
		int flag(0);
		int check = -2;
		while(i<=j){	

			//cout << "i" << i << endl;
			//cout << "j" << j << endl;

			if(cum_sum[j] - cum_sum[i] == s){
				cout << i+2 << " " << j+1 << endl;
				flag = 1;
				break;
			}

			if(cum_sum[j]-cum_sum[i] > s){
				i++;
				//cout << "i" << i << endl;
  			}

			else{
				i--;
				check = -1;
				while(i<=j){

					if(!check){
						cout << -1 << endl;
						break;
					}

					if(cum_sum[j] - cum_sum[i] == s){
						cout << i+2 << " " << j+1 << endl;
						flag = 1;
						break;
					}

					if(cum_sum[j] - cum_sum[i] > s){
						j--;
					}
					else{
						j++;
						check = 0;
					}
				}
			}
		}
	}

	return 0;
}