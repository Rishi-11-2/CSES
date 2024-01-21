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
    long long maxm=0;
    map<long long,long long>mp;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
        maxm=max(maxm,arr[i]);
    }
    
    long long m=(long long)(1e6);
    vector<bool>isPrime(m+1,1); 
    isPrime[0]=isPrime[1]=0;
    vector<long long>primes;
    for(long long i=2;i*i<=m;i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(long long j=i*i;j<=m;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    // debug(mp[1]);
    vector<int>vis(n+1,0);
    long long res=mp[1]*(n-mp[1]);
    for(auto it:primes)
    {
        if(it>maxm)
        break;
        long long count1=0;
        long long count2=0;
        for(long long i=0;i<n;i++)
        {
            if(vis[i]||arr[i]==1)
            continue;
            if(arr[i]%it==0)
            {
                count2++;
                vis[i]=1;
            }
            else
            {
                count1++;
            }
        }
        debug(it,count1,count2);
        long long y=(count1*(count2));
        // y/=2;
        res+=y;
    }
    cout<<res<<endl;
}