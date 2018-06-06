#include <iostream>
using namespace std;

void printArr(int A[],int n)
{
	int i;
	cout << "Sorted Array\n";
	for(i=0;i<n;i++) {

		cout << A[i] << " ";
		//printf("%d ",A[i]);
	}
	cout << "\n";	
}

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partitionArr(int A[],int low,int high)
{

	int piv = A[high];
	int i=-1,j;

	for(j=low;j<high;j++)
	{
		if(A[j] <= piv)
		{
			i++;
			swap(&A[i],&A[j]);
		}
	}

	swap(&A[i+1],&A[high]);
	return i+1;

}

void quickSort(int A[],int low,int high)
{
	if(low < high)
	{
		int pi = partitionArr(A,low,high);

		quickSort(A,low,pi-1);
		quickSort(A,pi+1,high);
	}

}

int main()
{

	int n,i;cin>>n;
	int A[n];
	for(i=0;i<n;i++){
		cin>>A[i];
	}

	quickSort(A,0,n-1);
	printArr(A,n);	

	return 0;
}