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
//(data type to be stored (pair,int,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaraints)
typedef tree < pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    vector<int>size;
    vector<int>parent;
    int nC;
    int maxm;
    DSU(int n )
    {
        size.resize(n+1);
        parent.resize(n+1);
        nC=n;
        maxm=1;
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUlp(int node)
    {
        if(parent[node]==node)
        return node;

        return parent[node]=findUlp(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findUlp(u);
        int ulp_v=findUlp(v);

        if(ulp_u==ulp_v)
        return ;

       if(size[ulp_u]>size[ulp_v])
       {
          nC--;
          size[ulp_u]+=size[ulp_v];
          maxm=max(maxm,size[ulp_u]);

         parent[ulp_v]=ulp_u;
       }
       else
       {
          nC--;
          size[ulp_v]+=size[ulp_u];
          parent[ulp_u]=ulp_v;
          maxm=max(maxm,size[ulp_v]);
       }
    }
};
void solve()
{
    int n,m;
    cin>>n>>m;

    DSU d(n);

    vector<pair<int,int>>res;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;

        d.unionBySize(u,v);

        res.push_back({d.nC,d.maxm});
    }

    for(auto it:res)
    cout<<it.first<<" "<<it.second<<endl;
}