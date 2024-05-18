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


    int maxPower=log2(n)+10;
    vector<vector<int>>parents(maxPower,vector<int>(n+1,-1));

    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        parents[0][i]=x;
    }

    for(int i=1;i<maxPower;i++)
    {
        for(int node=0;node<=n;node++)
        {
            int intermediate=parents[i-1][node];
            if(intermediate!=-1)
            {
                parents[i][node]=parents[i-1][intermediate];
            }
        }
    }

    function<int(int ,int)>f=[&](int node,int k)->int{
        for(int i=0;i<maxPower;i++)
        {
            if(k&(1<<i))
            {
                node=parents[i][node];
                if(node==-1)
                return node;
            }
        }
        return node;
    };

    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        int z=f(x,y);
        cout<<z<<endl;
    }
}