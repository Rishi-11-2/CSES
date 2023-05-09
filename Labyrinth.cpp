#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
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
    int n, m;
    cin >> n >> m;
    char c[n][m];
    vector<vector<int>> v(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'A')
            {
                q.push({i, j});
                v[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if((x+i)<n &&(x+i)>-1 &&(y+j)<m &&(y+j)>-1)
                {
                    if(vis[x+i][y+j]==0 && c[x+i][y+j]=='.')
                    {
                        
                    }
                }
            }
        }
    }
}