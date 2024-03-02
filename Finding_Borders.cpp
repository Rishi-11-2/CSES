#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
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
        b=b>>1LL;
    }
    return res;
}
long long inverse(long long a,long long mod)
{
    return binpow(a,mod-2,mod);
}
class Hashing
{
    public:
    long long p;
    vector<long long> modPrimes = {1000000009, 100000007};
    vector<vector<long long>> powersOfP;                                   
    vector<vector<long long>> inversePowersOfP;
    vector<vector<long long>> hash;
    string s;
    long long len;
    long long modLength;
    Hashing(string a)
    {
        s=a;
        len=s.length();
        p=1001;
        modLength=(long long)(modPrimes.size());
        powersOfP.resize(modLength);
        inversePowersOfP.resize(modLength);
        hash.resize(modLength);
        for(long long i=0;i<2;i++)
        {
            powersOfP[i].resize(len); 
            hash[i].resize(len); 
            inversePowersOfP[i].resize(len);
        }
        for(long long i=0;i<modLength;i++)
        {
            powersOfP[i][0]=1;
            for(long long j=1;j<len;j++)
            {
                powersOfP[i][j]=(powersOfP[i][j-1]%modPrimes[i]*p%modPrimes[i])%modPrimes[i];
            }
            inversePowersOfP[i][len-1]=inverse(powersOfP[i][len-1],modPrimes[i]);

            for(long long j=len-2;j>=0;j--)
            {
                inversePowersOfP[i][j]=(inversePowersOfP[i][j+1]%modPrimes[i]*p%modPrimes[i])%modPrimes[i];
            }

            for(long long j=0;j<len;j++)
            {
                long long val=(long long)(s[j]-'a'+1);
                long long pref=0;
                if(j>0)
                {
                    pref=hash[i][j-1];
                }
                hash[i][j]=(pref%modPrimes[i]+(val%modPrimes[i]*powersOfP[i][j]%modPrimes[i])%modPrimes[i])%modPrimes[i];
            }
        }


    }


    vector<long long>hashSubstring(long long l,long long r)
    {
        vector<long long>v;
        for(long long i=0;i<modLength;i++)
        {
            long long val=hash[i][r];
            if(l>0)
            {
                val=(val-hash[i][l-1]+modPrimes[i])%modPrimes[i];
            }
            val=(val%modPrimes[i]*inversePowersOfP[i][l]%modPrimes[i])%modPrimes[i];
            v.push_back(val);
        }

        return v;
    }


};
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
    string s;
    cin>>s;
    long long n=s.length();
    Hashing h(s);
    vector<int>res;
    for(long long i=0;i<n-1;i++)
    {
        if(h.hashSubstring(0,i)==h.hashSubstring((n-1)-i,n-1))
        {
            res.push_back(i+1);
        }
    }
    for(auto it:res)
    cout<<it<<" ";
    cout<<endl;
}