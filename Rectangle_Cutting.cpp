#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int dp[505][505];
  int f(int a,int b){
       for(int a1=0;a1<=500;a1++)
       {
            for(int b1=0;b1<=500;b1++)
            {
                // if(a1>b1)
                // swap(a1,b1);
                dp[a1][b1]=0x3f3f3f3f;
                if(a1==b1)
                {
                    dp[a1][b1]=0;
                    continue;
                }
                if(a1==1)
                { 
                    dp[a1][b1]=b1-1;
                    continue;
                }
                if(b1==1)
                {
                    dp[a1][b1]=a1-1;
                    continue;
                }
                for(int i=1;i<b1;i++)
                {
                    dp[a1][b1]=min(dp[a1][b1],1+dp[a1][i]+dp[a1][b1-i]);
                }
                for(int i=1;i<a1;i++)
                {
                    dp[a1][b1]=min(dp[a1][b1],1+dp[i][b1]+dp[a1-i][b1]);
                }
            }
       }
       return dp[a][b];
    };
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
    int a,b;
    cin>>a>>b;
    // vector<vector<int>>dp(a+10,vector<int>(b+10,-1));
    memset(dp,0x3f3f3f3f,sizeof(dp));
    cout<<f(a,b)<<endl;
}