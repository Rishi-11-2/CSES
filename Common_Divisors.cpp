#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
        solve();
}
    long long m=(long long)(1e6);
    vector<long long>mp(m+1,0);
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    
    long long res=1;
    for(int i=m;i>=1;i--)
    {
        int div=0;
        for(int j=i;j<=m;j+=i)
        {
            div+=mp[j];
            if(div>=2)
            {
                cout<<i<<"\n";
                return ;
            }
        }
    }
    // cout<<res<<'\n';
}