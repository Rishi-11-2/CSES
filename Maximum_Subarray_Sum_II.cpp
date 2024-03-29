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
    long long n,a,b;
    cin>>n>>a>>b;

    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    vector<long long>prefix(n,0);

    multiset<long long>s;

    prefix[0]=arr[0];
    for(long long i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    long long sum=prefix[a-1];
    for(long long i=a;i<n;i++)
    {
        s.insert(prefix[i-a]);
        if(i-b>=1)
        {
            s.erase(s.find(prefix[i-(b+1)]));
        }
         if(i<(b))
        {
            sum=max(sum,prefix[i]);
        }
        sum=max(prefix[i]-*s.begin(),sum);
    }

    cout<<sum<<endl;
}