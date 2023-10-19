#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
#define ll long long
vector<vector<ll>> dp;
vector<vector<ll>> adj;
void recSolve(int s, int p)
{
    dp[s][0] = dp[s][1] = 0;
    int leaf = 1;
    for (auto it : adj[s])
    {
        if (it != p)
        {
            recSolve(it, s);
            leaf = 0;
        }
    }
    if (leaf == 1)
        return;
    vector<ll> prefix;
    vector<ll> suffix;
    for (int child : adj[s])
    {
        if (child != p)
        {
            prefix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }
    for (int i = 1; i < (int)(prefix.size()); i++)
        prefix[i] = prefix[i] + prefix[i - 1];
    for (int i = (int)(suffix.size()) - 2; i >= 0; i--)
        suffix[i] = suffix[i] + suffix[i + 1];
    dp[s][0] = suffix[0];
    int i = 0;
    for (int child : adj[s])
    {
        if (child == p)
            continue;
        ll left = (i == 0) ? 0 : prefix[i - 1];
        ll right = (i == (int)(suffix.size()) - 1) ? 0 : suffix[i + 1];
        dp[s][1] = max(dp[s][1], 1 + left + right + dp[child][0]);
        i++;
    }
}
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
    cin >> n;
    dp.resize(n + 1, vector<ll>(2, 0));
    adj.resize(n + 1, vector<ll>());
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    recSolve(1, 0);
    // for (auto &i : dp)
    // {
    //     for (auto &j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    cout << max(dp[1][0], dp[1][1]) << endl;
}