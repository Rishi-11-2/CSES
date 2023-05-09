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
void solve();
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif
}
void solve()
{
    int n;
    cin >> n;
    char arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    int dp[n][n];
    if (arr[0][0] == '*')
        dp[0][0] = 0;
    else
        dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] == '*')
        {
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
        }
        if (arr[0][i] == '*')
        {
            dp[0][i] = 0;
        }
        else
        {
            dp[0][i] = dp[0][i - 1];
        }
    }
    int m = 1000000007;
    // cout << m << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % m;
            }
        }
    }
    cout << dp[n - 1][n - 1] % m << endl;
}