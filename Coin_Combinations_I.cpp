#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    int dp[x + 1];
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i - coins[j - 1] >= 0)
            {
                dp[i] += dp[i - coins[j - 1]];
                dp[i] = dp[i] % (1000000007);
            }
        }
    }
    cout << dp[x];
}