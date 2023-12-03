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
long long dp[20][3][12][3];
long long f(long long i,long long tight,long long prev,long long start,string &s,long long n)
{
      if(i==n)
        return 1;
      if(dp[i][tight][prev+1][start]!=-1)
      return dp[i][tight][prev+1][start];
        long long low=0;
        long long high=(tight==1)?s[i]-'0':9;
        long long res=0;
        // cout<<low<<" "<<high<<endl;
        for(long long j=low;j<=high;j++)
        {
            long long newTight=0;
            if(tight==1 && j==high)
            {
                newTight=1;
            }
            if(j==prev && start==1)
            continue;
            long long newStart=start;
            if(j>0)
            {
                newStart=1;
            }
           res+=f(i+1,newTight,j,newStart,s,n);
            
        }

        return dp[i][tight][prev+1][start]= res;
}
void solve()
{
    long long a,b;
    cin>>a>>b;
    string x=to_string(a-1);
    string y=to_string(b);

    while(x.length()<y.length())
    {
        char c='0';
        x=c+x;
    }
    // cout<<y<<" "<<x<<endl;
    long long n=y.length();
     // index,tight,prev

    // long long dp[n+1][2][15];
    memset(dp,-1,sizeof(dp));
    long long x1=f(0,1,-1,0,x,n);
    // dp.assign(n+1,vector<vector<long long>>(3,vector<long long>(16,-1)));
    memset(dp,-1,sizeof(dp));
    long long y1=f(0,1,-1,0,y,n);
    long long ans=y1-x1;
    // cout<<y1<<" "<<x1<<endl;
    cout<<ans<<endl;
}