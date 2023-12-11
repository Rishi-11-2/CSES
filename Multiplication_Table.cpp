#include <bits/stdc++.h>
using namespace std;
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    srand(time(NULL));
    // uint64_t t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    
}
void solve()
{
    uint64_t n;
    cin>>n;
    uint64_t low=1ull;
    uint64_t high=n*n;
    uint64_t res=high;
    /* The idea here is we have to find the  minimum element which is greater than atleast ceil((n*n)/2) elements
     Thus we use Binarry Search on answer. Also one more thing to keep in mind that we need to calculate for every number
     how many number that particular number is greater than or equal .
     We can divide i(1<=i<=n) to find out that fact because for every row, every number is a multiple of 2*/
    function<uint64_t(uint64_t)>f=[&](uint64_t mid)->uint64_t{
        uint64_t count=0;
        for(uint64_t i=1;i<=n;i++)
        {
            count+=min(n,mid/i);
        }
        if(count>((n*n)/2ull))
        return 1;
        return 0;
    };
    while(low<=high)
    {
        uint64_t mid=(low+high)/2ull;
        if(f(mid))
        {
            // debug(mid);
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