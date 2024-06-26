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
    vector<long long>adj[n+1];

    for(long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    
    vector<long long>topoSort;
    vector<long long>vis(n+1,0);

    function<void(long long)>f=[&](long long u)->void{
        vis[u]=1;
        for(long long v:adj[u])
        {
            if(!vis[v])
            {
                f(v);
            }
        }
        topoSort.push_back(u);
    };

    f(1);

    reverse(all(topoSort));
    const long long mod=(long long)(1e9)+7;
    vector<long long>dp(n+1,0);
    dp[1]=1;
    for(long long u:topoSort)
    {
        for(long long v:adj[u])
        {
            dp[v]=(dp[v]%mod+dp[u]%mod)%mod;
        }
    }

    cout<<dp[n]<<endl;
}