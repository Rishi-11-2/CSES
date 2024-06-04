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
    long long n,x;
    cin>>n>>x;

    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    long long m=(1LL<<(n+1));

    long long mm=(1LL<<n)-1;

    vector<pair<long long,long long>>dp(m+1,{(long long)(1e9),(long long)(1e9)});

    dp[0]={1,0};

    for(long long mask=0;mask<m;mask++)
    {
        for(long long j=0;j<n;j++)
        {
            auto curr=dp[mask];
            long long wt=curr.second;
            long long nr=curr.first;
            // debug(nr);
            if((mask &(1LL<<j))==0)
            {
                if((wt+arr[j])<=x)
                {
                    wt+=arr[j];
                }
                else
                {
                    wt=arr[j];
                    nr++;
                }
                long long newMask=mask|(1LL<<j);
                // debug(newMask,nr);
                dp[newMask]=min(dp[newMask],{nr,wt});
            }
        }
    }

    cout<<dp[mm].first<<endl;

}