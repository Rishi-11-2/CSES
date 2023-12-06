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
    
    int tail[n];
    int len=0;
    tail[len++]=arr[0];

    function<int(int,int,int)>f=[&](int l,int r,int target)->int{
        int res=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(tail[mid]>=target)
            {
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    };
    for(int i=1;i<n;i++)
    {
        if(arr[i]>tail[len-1])
        {
            tail[len++]=arr[i];
        }
        else
        {
            int c=f(0,len-1,arr[i]);
            tail[c]=arr[i];
        }
    }
    cout<<len<<endl;
}