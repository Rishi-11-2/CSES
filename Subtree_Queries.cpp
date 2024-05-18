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
void solve()
{
    int n,q;
    cin>>n>>q;
    
    int arr[n+1];

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }

    vector<int>adj[n+1];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>inTime(n+1,0);
    vector<int>outTime(n+1,0);

    int timer=0;
    vector<int>nodes;

    function<void(int,int)>f=[&](int u,int p)->void{

        nodes.push_back(u);

        inTime[u]=timer++;

        for(int v:adj[u])
        {
            if(v==p)
            continue;
            
            f(v,u);
        }

        outTime[u]=timer++;
        nodes.push_back(u);
    };

    f(1,-1);

    vector<int>v;
    for(auto node:nodes)
    {
        v.push_back(arr[nodes]);
    }

    vector<int>seg(10*n+1,0);
    function<void(int,int,int)>build=[&](int idx,int low,int high)->void{

        if(low==high)
        {
            seg[idx]=v[low];
            return;
        }

        int mid=(low+high)/2;

        build(2*idx+1,low,mid);
        build(2*idx+2,mid+1,high);

        seg[idx]+=seg[2*idx+1]+seg[2*idx+2];
    };

    build(0,0,2*n-1);


    

}