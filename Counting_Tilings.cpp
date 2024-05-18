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
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
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
    long long n,m;
    cin>>n>>m;

    long long end=(1<<(n))-1;

    vector<long long>adj[end+1];

    for(long long mask1=0;mask1<=end;mask1++)
    {
        for(long long mask2=0;mask2<=end;mask2++)
        {
   /*here we are checking if the two masks mask1 and mask2 are compatible or not
   compatibility check:
   mask1-> previous mask
   mask2-> current mask
   now ,
   previous mask   current mask  Reason
      0               1            Because that means we have used horizontal tile to cover the current cell
      1               0            that means that previous cell was covered by the horizontal tile from its previous one such that the current cell is vacant
      1               1             not possible as the previous cell is covered by the horiontal tile from its previous one so the current cannot be covered by tile from its previous one 
      0               0             this means that the previous cell is vacant so we did'nt do anything but this is also not possible. if we have placed a horizontal tile then
      it would be  0   1
      
      
      0                 0
      0                 0     this is possible as we have placed a vertical tile in the previous column and we can have this case in the current column*/  
            long long flag=1;
            for(long long i=0;i<n;i++)
            {
                long long c=(1<<i);
                long long bit1=((mask1&c)!=0)?1:0;
                long long bit2=((mask2&c)!=0)?1:0;

                if(bit1==1 && bit2==1)
                {
                    flag=0;
                    break;
                }
                if(bit1==0 && bit2==0)
                {
                    if(i+1<n)
                    {
                        long long cc=(1<<(i+1));
                        long long next_bit1=((mask1&cc)!=0)?1:0;
                        long long next_bit2=((mask2&cc)!=0)?1:0;
                        if(next_bit1==0 && next_bit2==0)
                        {
                            i++;
                            continue;
                        }

                        flag=0;
                        break;
                    }
                    flag=0;
                    break;
                }
            }

            if(flag)
            adj[mask1].push_back(mask2);
        }
    }
    const long long mod=(long long)(1e9)+7;
    vector<vector<long long>>dp(m+1,vector<long long>(end+1,-1));
    function<long long(long long,long long)>f=[&](long long i,long long mask)->long long{

        if(i==m)
        {
            // debug(mask);
            if(mask==0)
            return 1;
            
            return 0;
        }       
        if(dp[i][mask]!=-1)
        return dp[i][mask];
        long long res=0;
        for(auto it:adj[mask])
        {
            res=(res%mod+f(i+1,it)%mod)%mod;
        }
        return dp[i][mask]= res;
    };

    long long x=f(0,0);
    // for(long long i=0;i<=end;i++)
    // {
    //     for(auto it:adj[i])
        // debug(i,it);
       
    // }
    cout<<x<<endl;
}