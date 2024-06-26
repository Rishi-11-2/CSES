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
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];

    long long p[n];

    for(long long i=0;i<n;i++)
    cin>>p[i];

    
    long long tree[4*n];

    function<void(long long,long long,long long)>build=[&](long long ss,long long se,long long si)->void{

        if(ss==se)
        {
            tree[si]=1;
            return;
        }


        long long mid=(ss+se)/2;

        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=(tree[2*si+1]+tree[2*si+2]);
    };

    build(0,n-1,0);

    function<void(long long,long long,long long,long long)>update=[&](long long ss,long long se,long long si,long long pos)->void{

        if(ss==se)
        {
            tree[si]=0;
            return;
        }

        long long mid=(ss+se)/2;

        if(pos<=mid)
        {
            update(ss,mid,2*si+1,pos);
        }
        else
        {
            update(mid+1,se,2*si+2,pos);
        }
        tree[si]=(tree[2*si+1]+tree[2*si+2]);
    };



    function<pair<long long,long long>(long long,long long,long long,long long)>query=[&](long long ss,long long se,long long si,long long k)->pair<long long,long long>{


        if(ss==se)
        {

            return {arr[ss],ss};
        }

        long long mid=(ss+se)/2;

        if(k<=tree[2*si+1])
        return query(ss,mid,2*si+1,k);
        
        return query(mid+1,se,2*si+2,k-tree[2*si+1]);
    };

    vector<long long>res;
    for(long long i=0;i<n;i++)
    {
        long long x=p[i];
        auto it=query(0,n-1,0,x);
        res.push_back(it.first);
        update(0,n-1,0,it.second);
    }

    for(auto r:res)
    cout<<r<<" ";
    cout<<endl;
}