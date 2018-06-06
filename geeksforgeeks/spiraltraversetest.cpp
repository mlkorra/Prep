
/*

Problem : Spiral Traverse of Matrix

*/

#include <bits/stdc++.h>
using namespace std;

void spiralmatrix(int m,int n,int A[5][5])
{
	int k(0),l(0);
 	int i;
	while(k < m && l < n)
	{
		for(i=l;i<n;i++)
		{
			printf("%d ",A[k][i]);
		}
		k++;

		for(i=k;i<m;i++)
		{
			printf("%d ",A[i][n-1]);
		}
		n--;

		for(i=n-1;i>=l;i--)
		{
			printf("%d ",A[m-1][i]);
		}
		m--;

		for(i=m-1;i>=k;i--)
		{
			printf("%d ",A[i][l]);
		}	
		l++;
		
	}
}
int main()
{

	int t,i,j;cin>>t;
	while(t--)
	{
		int A[5][5];
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				cin>>A[i][j];
			}
		}

		/*Declaring two variables to bind the Matrix */
		
		spiralmatrix(4,4,A);

	}

	return 0;
}
