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
const long long mod=(long long)(1e9+7);
const long long p=69923;
void solve()
{
    string s;
    cin>>s;
    long long n=s.length();
    // debug(x.length(),s.length());
    vector<long long>base_pow(n+1,0);
    base_pow[0]=1;
    for(long long i=1;i<=n;i++)
    {
        base_pow[i]=(base_pow[i-1]*p)%mod;
    }
    vector<long long>prefix(n+1,0);
    prefix[0]=1;
    for(long long i=1;i<=n;i++)
    {
        prefix[i]=(s[i-1]+997+(prefix[i-1]*p)%mod)%mod;
    }

    function<long long(long long,long long)>f=[&](long long l,long long r)->long long{

        long long h=prefix[r+1]-(prefix[l]%mod*base_pow[r-l+1]%mod)%mod;

        if(h<0)
        h+=mod;
        
        return h;
    };
    for(long long i=1;i<=n;i++)
    {
        long long flag=1;
        for(long long j=0;j<n;j+=i)
        {
            long long len=min(i,n-j);
            long long a=f(j,j+len-1);
            long long b=f(0,len-1);
            // if(i==3)
            // {
            //     // debug(i,j,len,j+i);
            //     debug(s.substr(j,len),s.substr(0,len));
            //     debug(a,b);
            // }
            if(a!=b)
            flag=0;
        }
        if(flag)
        cout<<i<<" ";
    }

}