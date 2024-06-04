#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
        adj[y].push_back(x);
    }
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>> >q;
    vector<long long>dist(n+1,(long long)(1e18));
    vector<long long>parent(n+1,(long long)(-1));
    dist[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        auto it=q.top();
        q.pop();
        long long u=it.second;
        long long d=it.first;
        if(d!=dist[u])
        continue;
        for(auto v:adj[u])
        {
            if(dist[v]>(dist[u]+1))
            {
                parent[v]=u;
                dist[v]=dist[u]+1;
                q.push({dist[v],v});
            }
        }
    }

    if(dist[n]==(long long)(1e18))
    {
        cout<<"IMPOSSIBLE"<<endl;
    }   
    else
    {
        // cout<<dist[n]<<endl;
        vector<long long>path;

        long long node=n;

        while(node!=-1)
        {
            path.push_back(node);
            node=parent[node];
        }

        reverse(all(path));
        cout<<(int)(path.size())<<endl;
        for(auto it:path)
        cout<<it<<" ";
        cout<<endl;
    }
}