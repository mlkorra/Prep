#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &v,int start,int mid,int end)
{
	int i,j,k;
	int l1 = mid - start + 1;
	int l2 = end - mid;
	double A[l1];
	double B[l2];
	for(i=0;i<l1;i++){
		A[i] = v[i+start];
	}
	for(j=0;j<l2;j++){
		B[j] = v[j+m+1];
	}
	i=0;
	j=0;
	k=start;
	while(i<l1 && j<l2){

		if(A[i] <= B[j]){
			v[start] = A[i];
			i++;
		}
		if(B[j] <= A[i]){
			v[start] = B[j];
			j++;
		}
		k++;
	}	

	while(i<l1){
		v[k] = A[i]
		i++;
		k++;
	}

	while(j<l2){

		v[k] = B[j];
		j++:
		k++;
	}

}

/*
void merge(vector<int> &v,int start,int mid,int end){

	int l1 = mid - start + 1;
	int l2 = end - mid;

	int i,j,k;
	double A[l1],B[l2];
	for(i=start;i<l1;i++){
		A[i] = v[i];
	}
	for(j=mid+1,j<l2;j++){
		B[j] = v[j]
	}

	i=0;
	j=0;
	k=start;

	while(i<l1 && j<l2){

		if(A[i] <= B[j]){
			v[k] = A[i];
			i++;
		}

		if(A[i] >= B[j]){
			v[k] = B[j];
			j++;
		}

		k++;

	}

	while(i<l1){

		v[k] = A[i];
		i++;
		k++;

	}

	while(j<l2){

		v[k] = B[j];
		j++;
		k++;
	}


}
*/
void mergesort(vector<int> &v,int start,int end)
{
	
	if(start < end){
		int mid = start + (end - start)/2;
		mergesort(v,start,mid);
		mergesort(v,mid+1,end);

		merge(v,start,mid,end);
	}

}


int main()
{
	int i;
	vector<int> v;
	for(i=0;i<10;i++){
		v.push(rand()%100);
	}
	int n = v.size();
	mergesort(v,0,n);

	return 0;

}