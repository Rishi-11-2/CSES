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
    vector<pair<long long,pair<long long,long long>>>edges;

    for(long long i=1;i<=m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
        
    }
    
    vector<long long>dp(n+1,(long long)(1e9));
    vector<long long>parent(n+1,-1);
    dp[1]=0;
    long long x=-1;
    for(long long i=0;i<n;i++)
    {
        x=-1;
        for(auto it:edges)
        {
            if(dp[it.second.second]>(dp[it.second.first]+it.first))
            {
                parent[it.second.second]=it.second.first;
                dp[it.second.second]=dp[it.second.first]+it.first;
                x=it.second.second;
            }
        }
    }
    if(x==-1)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        for(long long i=0;i<n;i++)
        x=parent[x];
        long long node=x;
        // debug(x);
        // return;
        vector<long long>cycle;
        do{
            cycle.push_back(node);
            node=parent[node];
        }while(node!=x);
        cycle.push_back(x);
        reverse(all(cycle));
        for(auto v:cycle)
        cout<<v<<" ";
        cout<<endl;        
    }
}