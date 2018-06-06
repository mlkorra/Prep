#include <bits/stdc++.h>
using namespace std;

int main()
{

	int t;cin>>t;
	while(t--){
		int i,n;cin>>n;
		int v[n];
		int v1[n];
		memset(v1,0,sizeof(v1));
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		int max = INT_MIN;
		for(i=n-1;i>=0;i--){
			if(v[i]>max){
				max = v[i];
				v1[i] = max;
			}
			else v1[i] = max;

		}
		set<int> s;
		set<int> ::reverse_iterator rit;
		for(i=0;i<n;i++){
			if(v[i]==v1[i])	s.insert(v[i]);
		}
	
		for(rit = s.rbegin();rit!=s.rend();rit++){
			printf("%d ",*rit);
		}	

		printf("\n");

	}

	return 0;
}