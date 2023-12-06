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
    long long n,k;
    cin>>n>>k;

    long long arr[n];
    long long s=0;
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    // sort(arr,arr+n);
    long long low=*max_element(arr,arr+n);
    // cout<<low<<endl;
    long long high=s;
    long long res=low;
    function<long long(long long)>f=[&](long long mid)->long long{

        long long sum=0;
        long long count=0;
        for(long long i=0;i<n;i++)
        {
            if((sum+arr[i])>mid)
            {
                // cout<<mid<<" "<<sum<<endl;
                count++;
                sum=arr[i];
            }
            else
            {
                sum+=arr[i];
                // cout<<mid<<" "<<sum<<endl;
            }
        }
        count++;
        // cout<<mid<<" "<<count<<endl;
        return count;
        // return  (ount==k);
    };
    long long x=f(8);
    // cout<<k<<endl;
    while(low<=high)
    {
        long long mid=(low+high)/(2LL);
        // cout<<mid<<endl;
        if(f(mid)<=k)
        {
            // cout<<mid<<endl;
            res=mid;
            // break;
            high=mid-1;
        }
        else if(f(mid)>k)
        low=mid+1;
        // else
        // high=mid-1;
    }

    cout<<res<<endl;
}