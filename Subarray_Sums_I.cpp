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
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int count=0;
    int i=0;
    int j=0;
    int s=0;
    while(j<=n)
    {
        while(s>x)
        {
            s-=arr[i];
            i++;
        }
        if(s==x)
        count++;
        if(j<n)
        s+=arr[j];
        j++;
    }
    cout<<count<<endl;
}