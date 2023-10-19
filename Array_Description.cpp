#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
   
        solve();
    
}
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    const int mod=(int)(1e9+7);
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     function<int(int,int)>f=[&](int i,int prev)->int{
        int res=0;
        if(dp[i][prev]!=-1)
        return dp[i][prev];
        if(i==n)
        {
            return 1;
        }
        if(a[i]!=0)
        {
            // cout<<i<<endl;
            if(prev !=0 && abs(a[i]-prev)>1)
            return 0;
            return (f(i+1,a[i]))%mod;
        }
        else
        {
            for(int k=max(1,prev-1);k<=m;k++)
            {
                if(prev!=0 && abs(k-prev)<=1)
                {
                    res=(res%mod+f(i+1,k)%mod)%mod;
                }
                else if(prev==0)
                {
                    res=(res%mod+f(i+1,k)%mod)%mod;
                }
                else
                break;
            }
        }
        return dp[i][prev]=res;
     };
     cout<<max(0,f(0,0))<<endl;
}