/*
Reverse Words in String
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		int i,l,j;
		l = s.length();
		/* First Find the dots */
		int dotmark = l;
		for(i=l-1;i>=0;i--){
			if(s[i]=='.'){
				for(j=i+1;j<dotmark;j++){
					cout << s[j];
				}
				cout << '.';
				dotmark = i;
			}
		}
		for(i=0;i<=dotmark-1;i++){
			cout << s[i];
		}
		cout << "\n";
	}

	return 0;		
}