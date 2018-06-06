#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){
		int i,j,n;cin>>n;
		int A[3] = {0,0,0};
 		for(i=0;i<n;i++){
			cin>>j;
			A[j]++;
		}
		j = 0;
		for(i=0;i<A[0];i++) printf("%d ",j);
		J++;
		for(i=0;i<A[1];i++) printf("%d ",j);
		j++;
		for(i=0;i<A[2];i++) printf("%d ",j);
		cout << "\n";	
	}

	return 0;
}