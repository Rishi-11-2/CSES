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
//(data type to be stored (pair,uint64_t,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invarauint64_ts)
typedef tree < pair<uint64_t,uint64_t>, null_type,less<pair<uint64_t,uint64_t>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    uint64_t n,k;
    cin>>n>>k;
    uint64_t arr[k];
    for(uint64_t i=0;i<k;i++)
    cin>>arr[i];
    uint64_t mask=(1<<(k));
    mask--;

    sort(arr,arr+k);
    // reverse(arr,arr+k);

    

    uint64_t s=mask;
    uint64_t res=0;
    while(s>0)
    {

        uint64_t count=0;
        uint64_t product=1;
        for(uint64_t i=0;i<k;i++)
        {
            if(s&(1ULL<<i))
            {
                if(product>(n/arr[i]))
                {
                    product=n+1;
                    break;
                }
                product=product*arr[i];
                
                count++;
            }
        }
        uint64_t y=(n/product);
        // if(product==n+1)
        // debug(s,count,y,product);
        // if(product<0)
        if(count%2)
        {
            res+=y;
        }
        else
        {
            res-=y;
        }
        s=(s-1ULL)&mask;
    }

    cout<<res<<endl;
}