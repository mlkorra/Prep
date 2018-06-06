#include <bits/stdc++.h>
using namespace std;

typedef struct store{
	int data,count,index;
}store;

bool mycomp(store a,store b)
{
	return (a.data < b.data);
}

bool mycomp1(store a,store b)
{
	if(a.count!=b.count) return (a.count > b.count);
	else return (a.index < b.index);
}

void sortbyfreq(int A[],int n)
{
	int i;
	store elements[n];
	for(i=0;i<n;i++)
	{
		elements[i].data = A[i];
		elements[i].count = 0;
		elements[i].index = i;
	}

	stable_sort(elements,elements+n,mycomp);

	elements[0].count = 1;
	for(i=1;i<n;i++)
	{
		if(elements[i].data == elements[i-1].data)
		{
			elements[i].count += elements[i-1].count + 1;

			/*Restore the previous element's count */	
			elements[i-1].count = -1;

			/*Restore Index*/
			elements[i].index = elements[i-1].index;
		}

		else elements[i].count = 1;
	}

	stable_sort(elements,elements+n,mycomp1);
	int ind;
	for(i=0,ind=0;i<n;i++)
	{
		if(elements[i].count!=-1)
		{
			for(int j=0;j<elements[i].count;j++)
			{
				A[ind++] = elements[i].data;
			}
		}
	}
}

int main()
{
	int i,n;cin>>n;

	int A[n];
	for(i=0;i<n;i++)
	{
		cin>>A[i];
	}

	sortbyfreq(A,n);
	for(i=0;i<n;i++)
	{
		cout << A[i] << " ";
	}
    cout << endl;

    return 0;

}