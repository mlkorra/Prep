
/*

K  Rahul Dev

O(n) solution

*/


#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0;i< int(n) ;i++)
#define sz(x) ((int) (x).size())
typedef long long ll;
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {   
        int start,end;
        int check;
        int i,n,sum;cin>>n>>sum;
        int curr_sum;
        vector<int> v(n+1);
        for(i=1;i<=n;i++)
        {
            cin>>v[i];    
        }
        start = 1,end =1;
        curr_sum = 0;
        for(i=1;i<=n;i++)
        {
            
            curr_sum += v[i];
            
            
            if(curr_sum > sum){
                curr_sum -= v[start];
                start++;
                
            }
            
            if(curr_sum == sum){
                check = 1;
                cout << start << " " << end << endl;        
            }
            
            end++;
        }
        if(check!=1) {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
