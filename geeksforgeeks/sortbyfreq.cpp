/*

Problem : Sort Elements of an array by frequency
Site 	: GeeksforGeeks

Approach : Brute Force Method 
          
         Sort the array initially which takes O(nlogn) time.
         Then create a 2d Array to store index and count
         Finally sort the 2D Array wrt the count,and if count is equal,compare the index.    


*/

#include <bits/stdc++.h>
using namespace std;

typedef struct store{

	int data,index,count;

}store;


bool mycomp(store a,store b)
{
	return (a.data < b.data);
}

bool mycomp1(store a,store b)
{
	if(a.count!=b.count) return a.count > b.count;
	else return a.index < b.index; 
}

/*Sort by Frequency Function*/
void sortbyfrequency(int A[],int n)
{
   store elements[n];
   int i;
   for(i=0;i<n;i++)
   {
     elements[i].data = A[i];
     elements[i].index = i;
     elements[i].count = 0;    
   }

   stable_sort(elements,elements + n,mycomp);
   elements[0].count = 1;
   for(i=1;i<n;i++)
   {
      if(elements[i].data == elements[i-1].data)
      {
         elements[i].count += elements[i-1].count + 1;

         /* Restore the count of previous element because it's already counted */
         elements[i-1].count = -1;

         /* Restore the index because it is used for further when count is equal*/
         elements[i].index = elements[i-1].index;

      }
      else elements[i].count = 1;
   }
   int ind;
   stable_sort(elements,elements + n,mycomp1);
   for(i = 0,ind=0;i<=n-1;i++)
   {
     if(elements[i].count!=-1)
      for(int j=0;j<elements[i].count;j++)
      {
        A[ind++] = elements[i].data;
      }
   }      

}


/* Main Function*/
int main()
{
   
   int t;cin>>t;
   while(t--){
   int i,n;cin>>n;
   int A[n];

   for(i=0;i<n;i++)
   {
   		cin>>A[i];
   }	

   sortbyfrequency(A,n);
   for(i=0;i<n;i++)
   {
    cout << A[i] <<  " ";
   }
   
   } 
   return 0;

}