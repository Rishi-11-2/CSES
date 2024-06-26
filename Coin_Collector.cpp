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
    vector<long long>c(n+1);
    for(long long i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    vector<long long>adj[n+1];
    vector<long long>adj_rev[n+1];
    for(long long i=1;i<=m;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj_rev[y].push_back(x);
    }
    vector<long long>vis(n+1,0);
    vector<long long>topoSort;
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

    for(long long i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            f(i);
        }
    }
    fill(all(vis),0);
    map<long long,long long>mp;
    map<long long,long long>cp;
    long long count=0;
    vector<long long>components;
    function<void(long long u)>f1=[&](long long u)->void{
        vis[u]=1;
        components.push_back(u);
        for(long long v:adj_rev[u])
        {
            if(!vis[v])
            {
                f1(v);
            }
        }
    };
    // map<long long,long long
    reverse(all(topoSort));
    for(auto u:topoSort)
    {
        if(!vis[u])
        {
            count++;
            components.clear();
            f1(u);
            long long sum=0;
            for(auto v:components)
            {
                mp[v]=count;
                sum+=c[v];
            }
            cp[count]=sum;
        }
    }
    set<long long>adj_scc[count+1];
    for(long long i=1;i<=n;i++)
    {
        for(auto v:adj[i])
        {
            long long ulp_u=mp[i];
            long long ulp_v=mp[v];
            if(ulp_u!=ulp_v)
            {
                adj_scc[ulp_u].insert(ulp_v);
            }
        }
    }
    for(long long i=1;i<=n;i++)
    {
        // debug(i,mp[i]);
    }
    // vis.resize(count+1);
    fill(all(vis),0);
    vector<long long>dp(count+1);
    for(long long i=1;i<=count;i++)
    {
        // debug(i,cp[i]);
        dp[i]=cp[i];
    }
    topoSort.clear();
    function<void(long long)>f2=[&](long long u)->void{
        vis[u]=1;
        for(long long v:adj_scc[u])
        {
            if(!vis[v])
            f2(v);
        }
        topoSort.push_back(u);
    };

    for(long long i=1;i<=count;i++)
    {
        if(!vis[i])
        {
            f2(i);
        }
    }
    reverse(all(topoSort));
    for(auto u:topoSort)
    {
        // debug(u);
        for(long long v:adj_scc[u])
        {
            dp[v]=max(dp[v],dp[u]+cp[v]);
        }
    }

    long long res=0;

    for(long long i=1;i<=count;i++ )
    {
        res=max(res,dp[i]);
    }

    cout<<res<<endl;


}