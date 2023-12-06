#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
        solve();
}
void solve()
{
    long long n,x;
    cin>>n>>x;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];

   long long count=0;
   unordered_map<long long,long long>mp;
   long long sum=0;
   for(long long i=0;i<n;i++)
   {
     sum+=arr[i];
     if(sum==x)
     {
        count++;
     }
     if(mp.find(sum-x)!=mp.end())
     count+=mp[sum-x];
     
     mp[sum]++;
   }

   cout<<count<<endl;
}