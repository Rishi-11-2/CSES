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
    long long n;
    cin>>n;
    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    unordered_map<long long,long long>mp;
    long long sum=0;
    long long count=0;
    mp[0]=1;
    for(long long i=0;i<n;i++)
    {
        sum+=arr[i];
        int zz=sum%n;
        if(zz<0)
        {
            zz+=n;
        }
        count+=mp[zz];
        mp[zz]++;
    }
    cout<<count<<endl;
}