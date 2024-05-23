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
    long long n;
    cin>>n;

    long long arr[n];

    long long s=0;

    for(long long i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
     
    vector<long long>v;
    v.push_back(arr[0]);


    /* normal greedy will not fail in either (increasing) or (decreasing) or (decreasing and increasing)*/

    /* if the array does not fall into any of the three cases  , then we would have to consider it triplets(a,b,c) such that b>=a,c  so what happens now is that 
    we replace the triplets (a,b,c) by a-b+c. this ensures that we reduces the local maxima encountered and we keep doing
    that until the the arrays fall under any of three above categories */
    long long i=1;
    while(i<n)
    {
        if(i+1 <n && arr[i]>v.back() && arr[i]>arr[i+1])
        {
            // debug(i);
            long long x=v.back();
            v.pop_back();
            v.push_back(x+arr[i+1]-arr[i]);
            i+=2;
        }
        else
        {
            v.push_back(arr[i]);
            i++;
        }
        //checking if furthur operations can be performed
        while(v.size()>=3){
            int sz=v.size();
            if(v[sz-2]>v[sz-3] && v[sz-2]>v[sz-1]){
                long long x=v[sz-3]+v[sz-1]-v[sz-2];
                v.pop_back();
                v.pop_back();
                v.pop_back();
                v.push_back(x);
            }
            else break;
        }
    }

    long long a=0;
    long long b=0;
    i=0;
    long long j=(int)(v.size())-1;

    long long flag=0;

    while(i<=j)
    {
        if(v[i]>v[j])
        {
            if(flag)
            {
                b+=v[i];
                i++;
            }
            else
            {
                a+=v[i];
                i++;
            }
        }
        else
        {
            if(flag)
            {
                b+=v[j];
                j--;
            }
            else
            {
                a+=v[j];
                j--;
            }   
        }
        flag=1-flag;
    }

    long long res=(s+a-b)/2;

    cout<<res<<endl;
}