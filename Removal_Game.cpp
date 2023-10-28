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
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int sum1=0;
    int sum2=0;
    function<int(int,int,int)>f=[&](int i,int j,int flag)->int{
        if(i==j)
        {
            return arr[i];
        }
        int x1=f(i+1,j,1-flag)+arr[i];
        int x2=f(i,j-1,1-flag)+arr[j];
        cout<<i<<" "<<j<<" "<<x1<<" "<<x2<<endl;
        if(flag==0)
          c=1;
        else
          c=-1;
        return max()
    };
    int x=f(0,n-1,0);
    cout<<x<<endl;
    cout<<sum1<<" "<<sum2<<endl;
}