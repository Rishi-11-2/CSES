#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define all(v) (v).begin(), (v).end()
#define int long long int
#define lld long double
int M = 1000000007;
int oneBlock[1000001];
int twoBlock[1000001];
void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int n = 1e6;
    oneBlock[1] = twoBlock[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        oneBlock[i] = (oneBlock[i - 1] * 2) % M + (twoBlock[i - 1]) % M;
        twoBlock[i] = (4 * twoBlock[i - 1]) % M + (oneBlock[i - 1]) % M;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    cout << (oneBlock[n] + twoBlock[n]) % (M) << endl;
}