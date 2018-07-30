/*
Remove Adjacent Duplicates (Recursive)
*/

#include <bits/stdc++.h>
using namespace std;

string RemoveDup(string s,int n)
{
	string res;
	//int n = s.length();
	/* Corner Cases */
	if(n==1)
	{
		return s;
	}

	if(s[0]!=s[1]){
		res += s[0];
	}

	int i=1;
	
	while(i<n)
	{
		
		if(s[i]!=s[i-1] && s[i]!=s[i+1]){
			res += s[i];
		}
		i++;
	}

	int res_len = res.length();	
	if(res_len ==  0){
		return res;
	}

	if(res_len != n){
		return RemoveDup(res,res_len);
	}

	return res;

}

int main()
{
	int t;cin>>t;
	while(t--)
	{

		string s;
		
		cin>>s;
		int n = s.length();
	
		string res;
		res = RemoveDup(s,n);	
		cout << res << endl;
	}

	return 0;
}