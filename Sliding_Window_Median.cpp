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
    long long t;
    solve();
}
void solve()
{
    long long n,k;
    cin>>n>>k;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    pbds s;

    for(long long i=0;i<k;i++)
    {
        s.insert({arr[i],i});
    }
    long long xx=k;
    if(xx%2==0)
    xx--;
    auto x=*s.find_by_order(xx/2);
    vector<long long>ans;
    ans.push_back(x.first);

    for(long long i=k;i<n;i++)
    {
        s.erase({arr[i-k],i-k});
        s.insert({arr[i],i});

        auto y=*s.find_by_order(xx/2);
        ans.push_back(y.first);
    }

    for(auto it:ans)
    cout<<it<<" ";
    
    cout<<endl;
}