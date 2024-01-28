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
        b>>=1LL;
    }
    return res;
}
void solve()
{
       long long n;
    cin>>n;
    const long long mod=(long long)(1e9+7);
 
    // debug(res);
    const long long modinverse2=binpow(2,mod-2,mod);

    long long prev=n;
    long long res=n;
    long long j=n+1;
    for(long long i=2;i*i<=n;i++)
    {
        j=i+1;
        long long x=n/i;
        long long y=(x%mod*i%mod)%mod;
        res=(res%mod+y%mod)%mod;

        /* first term : x+1  ,  last term : prev*/

        long long sum=((prev%mod-x%mod+mod)%mod*(x%mod+1%mod+prev%mod)%mod)%mod;
        sum=(sum%mod*(i-1)%mod)%mod; // it will occur (i-1) times 
        // for 2 :  numbers from 5e11+1 to 1e12 will only occur one times
        // so we take their sum
        // for 3 : numbers from 3.33e11+1 to 5e11 will occur two times only 
        // for 4 : numbers from 2.5e11 to 3.3e11 will occur three times
        // and so on
        sum=(sum%mod*modinverse2%mod)%mod;

        res=(res%mod+sum%mod)%mod;

        prev=x;

    }

    // 20
    //  1 * 20
    // 2 * 10 + (20 -> 11) * 1
    // 3 * 6 + (10 -> 7) * 2
    // 4 * 5 + (6 -> 6) * 3
    // 5 will be left out for 20. 
    // in the sum till 20 we are not considering 5 therefore we were making a mistake
    for(long long i=j;i<=prev;i++)
    {
        long long x=(n/i);
        long long y=(x%mod*i%mod)%mod;
        res=(res%mod+y%mod)%mod;
    }

    cout<<res<<"\n";
}