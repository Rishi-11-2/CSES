#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);

    solve();
}
void solve()
{

    long long n,m;
    cin>>n>>m;

    long long grid[n][n];

    for(long long i=0;i<n;i++)
    {
        for(long long j=0;j<n;j++)
        {
            char ch;
            cin>>ch;

            if(ch=='*')
            grid[i][j]=1;
            else
            grid[i][j]=0;
        }
    }

    
    // for(long long i=0;i<n;i++)
    // {
    //     for(long long j=0;j<n;j++)
    //     {
    //         cout<<grid[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<endl;
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,0));

 

    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=n;j++)
        {
            
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])+grid[i-1][j-1];
        }
    }

    // for(long long i=0;i<n;i++)
    // {
    //     for(long long j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(long long i=1;i<=m;i++)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;

        // debug(c,d,a,b);
        // debug(dp[c][d],dp[a-1][b-1],dp[c][b],dp[a][d]);
        cout<<(dp[c][d]+dp[a-1][b-1]-dp[c][b-1]-dp[a-1][d])<<endl;
    }
}