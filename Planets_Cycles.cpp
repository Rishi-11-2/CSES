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
    long long n;
    cin>>n;

    long long arr[n+1];
    for(long long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }


    vector<long long>vis(n+1,0);
    vector<long long>dis(n+1,0);
    queue<long long>path;
    long long pathlength=0;
    function<void(long long)>f=[&](long long u)->void{
        path.push(u);
        if(vis[u])
        {
            pathlength+=dis[u];
            return;
        }
        // debug(u);
        vis[u]=1;
        pathlength++;
        f(arr[u]);
    };

    for(long long i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            pathlength=0;
            // path.clear();
            f(i);
            long long counter=1;
            while(!path.empty())
            {
                if (path.front() == path.back()) { counter = 0; } // cycle can be inside 
                dis[path.front()] = pathlength;
                pathlength -= counter;
                path.pop();
            }

        }
    }
    for(long long i=1;i<=n;i++)
    cout<<dis[i]<<" ";
    cout<<endl;
}