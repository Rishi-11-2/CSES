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
    vector<long long>ans;
    multiset<long long>up,down;
    long long up_sum=0;
    long long down_sum=0;
    long long n,k;
    cin>>n>>k;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(long long i=0;i<k;i++)
    {
        up_sum+=arr[i];
        up.insert(arr[i]);
    }
    while((long long)(up.size())>(k/2))
    {
        up_sum-=(*up.begin());
        down_sum+=(*up.begin());
        down.insert(*up.begin());
        up.erase(up.begin());
    }

    long long median=*down.rbegin();

    long long cost=(median*(k-k/2)-down_sum)+(up_sum-(median*(k/2)));
    ans.push_back(cost);

    for(long long i=k;i<n;i++)
    {
        auto it=down.find(arr[i-k]);
        if(it!=down.end())
        {
            down.erase(it);
            down_sum-=arr[i-k];
        }
        else
        {
            up.erase(up.find(arr[i-k]));
            up_sum-=arr[i-k];
        }

        if(!down.empty() && arr[i]<=*down.rbegin())
        {
            down.insert(arr[i]);
            down_sum+=arr[i];
        }
        else
        {
            up.insert(arr[i]);
            up_sum+=arr[i];
        }
        while((long long)(up.size())>(k/2))
        {
            down_sum+=(*up.begin());
            up_sum-=(*up.begin());
            down.insert(*up.begin());
            up.erase(up.begin());
        }
        while((long long)(down.size())>(k-k/2))
        {
            up_sum+=(*down.rbegin());
            down_sum-=(*down.rbegin());
            up.insert(*down.rbegin());
            down.erase(down.find(*down.rbegin()));
        }
        // for(auto it:down)
        // cout<<it<<" ";
        // cout<<endl;
        long long median=*down.rbegin();
        // debug(median,down_sum,up_sum);
        long long cost=(median*(k-k/2)-down_sum)+(up_sum-(median*(k/2)));
        ans.push_back(cost);
    }

    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}