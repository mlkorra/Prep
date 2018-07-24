#include <bits/stdc++.h>
using namespace std;

void _initialize(int A[],int n)
{
    int i;
    for(i=0;i<n;i++){
        A[i]=1;
    }
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int i,j,n;cin>>n;
        int res = 0;
        if(n==0) cout << res << endl;
        
        int A[n];
        for(i=0;i<n;i++){
            cin>>A[i];
        }
        
        int dp[n];
        _initialize(dp,n);
        
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                if(A[j]<A[i]){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
        }
        res = *max_element(dp,dp+n);
        cout << res << endl;
        
    }

    return 0;
}