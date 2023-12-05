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

int dp[101][100002];
int f(int i,int sum,set<int>&s,int n,int *arr)
{

    if(i==n)
        {
            if(sum==0)
            return 0;
            s.insert(sum);
            return 0;
        }
        if(dp[i][sum]!=-1)
        return dp[i][sum];

        dp[i][sum]=f(i+1,sum,s,n,arr)+f(i+1,sum+arr[i],s,n,arr);
        return dp[i][sum];

}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    set<int>s;
    memset(dp,-1,sizeof(dp));
    int x=f(0,0,s,n,arr);
    int sz=(int)(s.size());
    cout<<sz<<endl;
    for(auto it:s)
    cout<<it<<" ";
    cout<<endl;
}