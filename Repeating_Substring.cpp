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
#define MAXLEN 1000010

 constexpr uint64_t mod = (1ULL << 61) - 1;
const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);
 uint64_t base_pow[MAXLEN];
int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}
 
void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}
 
 
struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;
 
    PolyHash() {}
 
    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();
 
        int n = ar.size();
        pref.resize(n + 3, 0), suff.resize(n + 3, 0);
 
        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod) pref[i] -= mod;
        }
 
        for (int i = n; i >= 1; i--){
            suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod) suff[i] -= mod;
        }
    }
    /*https://usaco.guide/gold/string-hashing?lang=cpp*/
    /*  pref[r+1]=( p^r+1 + a[0]*p^(r) + a[1]*p^(r-1) + a[2]*p^(r-2) + ..+ a[l-1]*p^((r+1)-(l-1+1))+a[l]*p^((r+1)-(l+1))  .. a[r-1]*p + a[r] )
        pref[l]=( p^l + a[0]*p^(l-1) + a[1]*p^(l-2) + a[2]*p^(l-3) + ...a[l-2]*p +  a[l-1])

        p^(r-l+1)*pref[l] = ( a[0]*p^(r) + a[1]*p^(r-1) +.... + a[l-1]*p^(r-l+1) )

        pref[r+1]-(p^(r-l+1))*pref[l]=a[l]*p^(r-l)+ a[l+1]*p^(r-l-1)+.... + a[r-1]*p + a[r]

    */
    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}
 
    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }
 
    uint64_t rev_hash(int l, int r){
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }
};
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
    long long low=1;
    long long res=0;
    long long high=n-1;
    

    const char *str=s.c_str();
    PolyHash h(str);
    function<long long(long long)>f=[&](long long mid)->long long{

      unordered_map<long long,long long>mp;
      for(long long i=0;i+mid-1<n;i++)
      {
        long long val=h.get_hash(i,i+mid-1);

         mp[val]++;
         if(mp[val]==2)
         {
            return 1;
         }
      }  
      return 0;
    };
    while(low<=high)
    {
        long long mid=(low+high)/2;

        if(f(mid))
        {
            low=mid+1;
            res=mid;
        }
        else
        {
            high=mid-1;
        }
    }
    map<long long,long long>mp;
    if(res==0)
    {
        cout<<-1<<endl;
        return;
    }
    for(long long i=0;i+res-1<n;i++)
    {
        long long val=h.get_hash(i,i+res-1);
        mp[val]++;
        if(mp[val]==2)
        {
            cout<<s.substr(i,res);
            return;
        }
    }   
}