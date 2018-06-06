#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int t;cin>>t;
	while(t--){
		int i,j,n;cin>>n;
		int v[n];
		for(i=0;i<n;i++){
			cin>>v[i];
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(v[i]<=v[j]){
					swap(&v[i],&v[j]);
				}
			}
		}
		for(i=0;i<n;i++){
			printf("%d ",v[i]);
		}
		cout << "\n";
	}

	return 0;
}