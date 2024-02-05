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
            res=(res%mod*a%mod)%mod;
        }
        a=(a%mod*a%mod)%mod;
        b>>=1LL;
    }
    return res;
}
void solve()
{
    string s;
    cin>>s;
    map<char,long long>mp;
    for(char c:s)
    {
        mp[c]++;
    }

    long long n=s.length();
    const long long mod=(long long)(1e9+7);
    vector<long long>fact(n+1,0);
    vector<long long>ifact(n+1,0);
    fact[0]=1;
    for(long long i=1;i<=n;i++)
    {
        fact[i]=(fact[i-1]%mod*i%mod)%mod;
    }
    ifact[n]=binpow(fact[n],mod-2,mod);
    for(long long i=n-1;i>=0;i--)
    {
        ifact[i]=((i+1)%mod*ifact[i+1]%mod)%mod;
    }
    long long res=fact[n];
    long long product=1;
    for(auto it:mp)
    {
        product=(product%mod*ifact[it.second]%mod)%mod;
    }
    res=(res%mod*product%mod)%mod;
    cout<<res<<endl;
}