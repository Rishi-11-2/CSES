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
//(data type to be stored (pair,long long ,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong long s)
typedef tree < pair<long long ,long long >, null_type,less<pair<long long ,long long >>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    vector<pair<long long ,long long >>adj[n+1];
    for(long long i=1;i<=m;i++)
    {
        long long x,y,c;
        cin>>x>>y>>c;

        adj[x].push_back({y,c});
        // adj[y].push_back({x,c});
    }

    priority_queue< vector<long long> , vector<vector<long long>>, greater<vector<long long>> >pq;

    vector<vector<long long>>dis(n+1,vector<long long>(2,(long long )(1e18)));
    vector<vector<long long>>vis(n+1,vector<long long>(2,(long long )(0)));
    dis[1][0]=0;
    dis[1][1]=0;
    // vis[1][1]=1;
    // vis[1][0]=1;
    pq.push({0,0,1});

    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        
        long long d=it[0];
        long long co=it[1];
        long long u=it[2];
        if(vis[u][co])
        continue;
        vis[u][co]=1;
        for(auto v:adj[u])
        {
            // long long dist=
            // debug(u,v.first,dis[v.first]);
            if(dis[v.first][co]>d+v.second)
            {
                vis[u][co]=1;
                dis[v.first][co]=d+v.second;
                pq.push({dis[v.first][co],co,v.first});
            }
            if(co<1 && (dis[v.first][1]>(d+(v.second/2))))
            {
                vis[u][1]=1;
                dis[v.first][1]=d+v.second/2;
                pq.push({dis[v.first][1],1,v.first});
            }
        }
    }

    cout<<min(dis[n][0],dis[n][1])<<endl;
}