/*
Edit Distance
Dynamic Programming
*/

/*
Tutorial : How to solve a DP problem.

1. First,find the subproblems and try to find the 
   Recursion Part of Exponential Complexity

2. Then get rid of Recursion using Memoization,i.e storing already solved 
   problems in an array or Matrix.

3. Finally,convert the Recursion Form to Iterative form using Memoization.   

*/

#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
	return (a<b)?a:b;
}

int main()
{
	int t;cin>>t;
	while(t--)
	{
		int i,j,m,n;cin>>m>>n;
		string s1,s2;cin>>s1>>s2;

		/* A 2D Array to store the No.of edits required for the strings s1[0-m],s2[0-n] */
		int dp[m+1][n+1];

		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){

				if(i==0){
					dp[i][j] = j;
				}
				else if(j==0){
					dp[i][j] = i;
				}

				else if(s1[i-1]==s2[j-1]){
					dp[i][j] = dp[i-1][j-1];
				}
				else{
					/* 
					Insert : ith and jth characters of respective strings are compared,
							 we are performing 'INSERT' to match the two characters.
							 But as we added a new character,it's position is (i+1)th.
							 So,(i+1)th and jth character of respective strings are matched as
							 desired,now move to the next characters i.e ith and (j-1)th of 
							 respective strings.

					Replace: ith and jth charaters of respective strings are compared,
							 we are performing 'REPLACE' to match the two characters.
							 So,when we replace the ith character in the first string to
							 match the jth character of second string.
							 We proceed to the next character,i.e (i-1)th and (j-1)th 
							 character of the respective strings.

					Remove : ith and jth characters of respective strings are compared,
							 we are performing 'REMOVE' to remove the ith character of 
							 1st string.We proceed to the next character,i.e  (i-1)th and
							 jth of respective strings.
							 Note : Here,it's still 'jth'character of respective string
							 because we haven't matched it yet.

					*/
					dp[i][j] = 1+min(min(dp[i][j-1],dp[i-1][j-1]),dp[i-1][j]);
				}
			}
		}

		cout << dp[m][n] << endl;
	}

	return 0;
}