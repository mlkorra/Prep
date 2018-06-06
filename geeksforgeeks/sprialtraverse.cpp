	
/*

Problem : Spirally Traversing a Matrix
Approach : Imagine or relate it with how 
some car which always right on hitting a Wall.

So,the spiral path of the Matrix is same as the path of the car.

*/


#include <bits/stdc++.h>
using namespace std;

void spiralmatrix(int A[5][5],int m,int n)
{
	int k,l,i;
	k=0,l=0;

	while(k < m && l < n)
	{
		/* First Row of the Matrix  */
		for(i = l;i< n;i++)
		{
			printf("%d ",A[k][i]);
		}
		k++;

		/*Last column of the Matrix */
		for(i = k;i< m;i++)
		{
			printf("%d ",A[i][n-1]);
		}
		n--;

		for(i = n-1;i>=l;i--)
		{
			printf("%d ",A[m-1][i]);
		}

		m--;

		for(i = m-1;i>=k;i--)
		{
			printf("%d ",A[i][l]);
		}
		l++;
	}
	printf("\n");
}

int main()
{

	int i,j,t;cin>>t;
 	int A[5][5];
	while(t--)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				cin>>A[i][j];
			}
		}	

		spiralmatrix(A,4,4);
	}	

	return 0;

}