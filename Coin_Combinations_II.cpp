#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int dp[n + 1][x + 1];
    for (int i = 0; i <= x; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1])
                dp[i][j] += dp[i][j - coins[i - 1]];
            dp[i][j] = dp[i][j] % (1000000007);
        }
    }
    cout << dp[n][x];
}