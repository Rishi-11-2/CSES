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
    long long n,a,b;
    cin>>n>>a>>b;
    long long arr[n];
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    long long i=0;
    long long s=arr[0];
    long long j=1;
    long long res=s;
    while(j<n)
    {
        long long len=j-i;
        while(i<j && len>b)
        {
            s-=arr[i];
            i++;
            len=j-i;
        }
        res=max(res,s);
        s+=arr[j];
        j++;
    }
    res=max(res,s);
    cout<<res<<endl;
}