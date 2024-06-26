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
class SegmentTree{
    public:
    vector<long long>tree;
    vector<long long>arr;
    long long n;
    SegmentTree(long long nn,vector<long long>&a)
    {
        n=nn;
        tree.resize(4*n);
        arr=a;
    }

    void build(long long ss,long long se,long long si)
    {
        if(ss==se)
        {
            tree[si]=arr[se];
            return;
        }

        long long mid=(ss+se)/2;

        build(ss,mid,2*si+1);
        build(mid+1,se,2*si+2);

        tree[si]=max(tree[2*si+1],tree[2*si+2]);
    }

    void update(long long ss,long long se,long long si,long long pos,long long val)
    {
        if(ss==se)
        {
            tree[si]=tree[si]-val;
            return;
        }

        long long mid=(ss+se)/2;
        if(pos<=mid)
        {
            update(ss,mid,2*si+1,pos,val);
        }
        else
        update(mid+1,se,2*si+2,pos,val);
        tree[si]=max(tree[2*si+1],tree[2*si+2]);

    }

    long long query(long long ss,long long se,long long si,long long k)
    {
        if(tree[si]<k)
        return -1;

       if(ss==se)
       {
          return se;
       }
       long long mid=(ss+se)/2;

       if(tree[2*si+1]>=k)
       return query(ss,mid,2*si+1,k);
       
       return query(mid+1,se,2*si+2,k);
    }

    void make_update(long long pos,long long val)
    {
        update(0,n-1,0,pos,val);
    }

    long long make_query(long long k)
    {
        return query(0,n-1,0,k);
    }
};
void solve()
{
    long long n,m;
    cin>>n>>m;

    vector<long long>h(n);

    for(long long i=0;i<n;i++)
    cin>>h[i];

    long long r[m];
    for(long long i=0;i<m;i++)
    cin>>r[i];

    SegmentTree st(n,h);
    
    st.build(0,n-1,0);
    vector<long long>res;
    for(long long i=0;i<m;i++)
    {
        long long idx=st.make_query(r[i]);
        res.push_back(idx);
        if(idx!=-1)
        st.make_update(idx,r[i]);
    }

    for(auto it:res)
    cout<<it+1<<" ";
    cout<<endl;
}