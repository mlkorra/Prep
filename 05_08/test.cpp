#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){
		int i,a,b;cin>>a>>b;
		int temp[a],temp1[b];
		int sum(0),sum2(0);
		for(i=0;i<a;i++){
			cin>>temp[i];
			sum+= temp[i];
		}

		for(i=0;i<b;i++){
			cin>>temp1[i];
			sum2+= temp1[i];
		}

		if(sum2>=sum){
			cout << "C2" << endl;
		}
		else{
			cout << "C1" << endl;
		}

	}

	return 0;
}