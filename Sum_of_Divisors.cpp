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
long long binpow(long long a,long long b,long long mod)
{
    long long res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(res%mod*a%mod);
        }
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return res;
}
void solve()
{
    long long m=(long long)(1e6);
    long long n;
    cin>>n;
    const long long mod=(long long)(1e9+7);

    long long res=(n%mod*(n+1)%mod)%mod;
    long long z=binpow(2,mod-2,mod);
    res=(res%mod*z%mod)%mod;
    // debug(res);
    for(long long i=1;i<=min(n,m);i++)
    {
        long long x=(n/i);
        x--;
        long long y=(x%mod*i%mod)%mod;
        res=(res%mod+y%mod)%mod;
    }
    cout<<res<<endl;
}