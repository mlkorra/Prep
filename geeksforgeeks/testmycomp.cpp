#include <bits/stdc++.h>
using namespace std;

 bool mycomp(int a,int b)
 {
 	return a>b;
 }

int main()
{
   int A[5] = {1,234,212,12,9};
   int n = sizeof(A)/sizeof(A[0]);
   stable_sort(A,A+n,mycomp);
   for(int i=0;i<n;i++){
   	cout << A[i] << " ";
   }
   cout << endl;
   return 0;
}