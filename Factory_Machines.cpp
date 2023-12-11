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
     uint64_t n,t;
    cin>>n>>t;
     uint64_t arr[n];
    uint64_t s=0;
    for( uint64_t i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    
     uint64_t low=0;

     uint64_t high=( uint64_t)(1e18);

    function< uint64_t( uint64_t)>f=[&]( uint64_t mid)-> uint64_t{

         uint64_t count=0;
        for( uint64_t i=0;i<n;i++)
        {
             uint64_t x=mid/arr[i];
            count+=(x);
            if(count>=t) /* was not thinking about overflow. Stupid me !!!!*/
            return 1ull;
        }
        if(count>=t)
        return 1ull;
        
        return 0ull;
    };
    // unsigned uint64_t x=f(2710505);
    // cout<<x<<endl;
     uint64_t res=high;
    while(low<=high)
    {
         uint64_t mid=(low+high)/(2ull);
        if(f(mid))
        {
        //    cout<<mid<<endl;
            res=mid;
            high=mid-1ull;
        }
        else
        {
            low=mid+1ull;
        }
    }
    cout<<res<<endl;
}