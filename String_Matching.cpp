#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
  long long binpow(long long a,long long  b,long long mod)
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
  long long inverse(long long n,long long mod)
   {
      return binpow(n,mod-2,mod);
   }
  class Hashing{
    public:
       string s;
       long long n;
       long long primes;
       vector<long long> hashPrimes = {1000000009, 100000007};
       const long long base = 1001;
       vector<vector<long long>> hashValues;
       vector<vector<long long>> powersOfBase;
       vector<vector<long long>> inversePowersOfBase;
       Hashing(string a){
            primes = (long long)(hashPrimes.size());
            hashValues.resize(primes);
            powersOfBase.resize(primes);
            inversePowersOfBase.resize(primes);
            s = a;
            n = s.length();
            for(long long i = 0; i < primes; i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(long long j = 1; j <= n; j++){
                 powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = inverse(powersOfBase[i][n], hashPrimes[i]);
           for(long long j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = ((inversePowersOfBase[i][j + 1]%hashPrimes[i])*(base%hashPrimes[i]))%hashPrimes[i];
           }
       }
       for(long long i = 0; i < primes; i++) {
           hashValues[i].resize(n);
           for(long long j = 0; j < n; j++){
              long long val=(s[j]-'a'+1LL);
               hashValues[i][j] = (val%hashPrimes[i] * powersOfBase[i][j]%hashPrimes[i]) % hashPrimes[i];
               hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
       }
   }
    vector<long long> substringHash(long long l, long long r){
        vector<long long> hash(primes);
        for(long long i = 0; i < primes; i++){
           long long val1 = hashValues[i][r];
           long long val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
           hash[i] = ((val1-val2+hashPrimes[i])%hashPrimes[i]*inversePowersOfBase[i][l]%hashPrimes[i])%hashPrimes[i];
        }
     return hash;
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

    string p;
    cin>>p;

    Hashing text(s);
    Hashing pattern(p);
    long long n=s.length();
    long long count=0;
    long long m=p.length();
    for(long long i=m-1;i<n;i++)
    {
        if(text.substringHash(i-(m-1),i)==pattern.substringHash(0,m-1))
        {
            count++;
        }
    }
    cout<<count<<endl;

}