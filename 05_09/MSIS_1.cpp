#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        
        int i,j,n;cin>>n;
        int A[n],dp[n];
        for(i=0;i<n;i++){
            cin>>A[i];
            dp[i] = A[i];
        }
        
        for(i=0;i<n;i++){
            for(j=0;j<i;j++){
                if(A[j] < A[i] && A[i]+dp[j]>dp[i]){
                    dp[i] = dp[j]+A[i];
                }
            }
        }
        int max = INT_MIN;
        for(i=0;i<n;i++){
            if(dp[i]>max){
                max = dp[i];
            }
        }

        cout << max << endl;
    }
    
    
    return  0;
}