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
    long long n,q;
    cin>>n>>q;
    
    long long arr[n+1];

    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        arr[i]=x;
    }

    vector<long long>adj[n+1];
    for(long long i=1;i<n;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<long long>nodes;
    function<void(long long,long long)>f=[&](long long u,long long p)->void{

        nodes.push_back(u);


        for(long long v:adj[u])
        {
            if(v==p)
            continue;
            
            f(v,u);
        }

        nodes.push_back(u);
    };

    f(1,-1);

    vector<long long>v;
    vector<long long>mp[n+1];
    long long ii=0;
    for(auto node:nodes)
    {
        // cout<<node<<" ";
        mp[node].push_back(ii);
        v.push_back(arr[node]);
        ii++;
    }

    vector<long long>seg(10*n+1,0);
    function<void(long long,long long,long long)>build=[&](long long idx,long long low,long long high)->void{

        if(low==high)
        {
            seg[idx]=v[low];
            return;
        }

        long long mid=(low+high)/2;

        build(2*idx+1,low,mid);
        build(2*idx+2,mid+1,high);

        seg[idx]+=seg[2*idx+1]+seg[2*idx+2];
    };

    build(0,0,2*n-1);


    function<void(long long,long long,long long,long long,long long )>update=[&](long long ss,long long se,long long i,long long si,long long diff)->void{


        if(i>se || i<ss)
        return;

        seg[si]+=diff;

        if(se>ss)
        {
            long long mid=(ss+se)/2;
            update(ss,mid,i,2*si+1,diff);
            update(mid+1,se,i,2*si+2,diff);
        }

    };

    function<long long(long long,long long,long long,long long,long long)>query=[&](long long qs,long long qe,long long ss,long long se,long long si)->long long{

        if(qe<ss || qs>se)
        return 0;
        
        if(ss>=qs && se<=qe)
        {
            return seg[si];
        }
        long long mid=(se+ss)/2;
        return query(qs,qe,ss,mid,2*si+1)+query(qs,qe,mid+1,se,2*si+2);
    };

    vector<long long>res;
    for(long long i=1;i<=q;i++)
    {
        long long val;
        cin>>val;
        if(val==1)
        {
            long long s,x;
            cin>>s>>x;

            long long diff=x-arr[s];

            update(0,2*n-1,mp[s][0],0,diff);
            update(0,2*n-1,mp[s][1],0,diff);


            arr[s]=x;
        }
        else if(val==2)
        {
            long long node;
            cin>>node;
            // debug(mp[node][0],mp[node][1]);
            res.push_back(query(mp[node][0],mp[node][1],0,2*n-1,0));
        }
    }

    for(auto it:res)
    cout<<it/2<<endl;
}