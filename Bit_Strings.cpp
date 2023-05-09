#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        solve();
}
void solve()
{
    int n;
    cin>>n;
    long long M=1000000007;
    long long res=1;
    for(int i=0;i<n;i++)
    {
        res=(res*2)%M;
    }
    cout<<res%M<<endl;
}