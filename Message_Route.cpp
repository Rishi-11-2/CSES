#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
class DSU{
    vector<int>parent,size;
    DSU(int n)
    {
        parent.resize
    }
};
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
}