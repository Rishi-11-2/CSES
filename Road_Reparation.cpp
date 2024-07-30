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
class DSU{
    public:
    vector<long long>size;
    vector<long long>parent;
    DSU(long long n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        for(long long i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i]=i;
        }
    }

    long long findUlp(long long node)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(long long u,long long v)
    {
        long long ulp_u=findUlp(u);
        long long ulp_v=findUlp(v);
        if(ulp_u==ulp_v)
        return;
        
        if(size[ulp_u]>size[ulp_v])
        {
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else
        {
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }
};
void solve()
{
    long long n,m;
    cin>>n>>m;

    vector< pair<long long, pair<long long,long long>> >edges;
    DSU d(n);
    for(long long i=1;i<=m;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        edges.push_back({c,{a,b}});
    }

    sort(all(edges));
    long long cost=0;
    long long count=0;
    for(auto it:edges)
    {
        long long c=it.first;
        long long a=it.second.first;
        long long b=it.second.second;

        if(d.findUlp(a)==d.findUlp(b))
        continue;
        count++;
        cost+=c;
        d.unionBySize(a,b);
        if(count==n-1)
        break;

    }
    if(count<n-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<cost<<endl;
}