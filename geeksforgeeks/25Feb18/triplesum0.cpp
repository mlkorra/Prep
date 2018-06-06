/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete the function below*/

#include <bits/stdc++.h>
bool findTriplets(int arr[], int n)
{ 
    //Your code here
        sort(arr,arr+n);
        int i,p1,p2;
        for(i=0;i<n-2;i++){
            
            p1 = i+1;
            p2 = n-1;
            while(p1<p2){
                
                if(arr[p1] + arr[p2] == -arr[i]){
                    return true;
                }
                
                else if(arr[p1] + arr[p2] < -arr[i]){
                    p1++;
                }
                else {
                    p2--;
                }
            }
        }
    return false;
}