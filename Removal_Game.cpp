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
    long long n;
    cin>>n;
    long long arr[n];
    long long s=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
    function<long long(long long,long long,long long)>f=[&](long long l,long long r,long long p)->long long{

        if(l>r)
        return 0;
       if(dp[l][r]!=-1)
       return dp[l][r];
       long long x=arr[l]-f(l+1,r,1-p);
       long long y=arr[r]-f(l,r-1,1-p);
       return dp[l][r]=max(x,y);
    };

    long long x=f(0,n-1,0);
    cout<<(s+x)/2<<endl;
}