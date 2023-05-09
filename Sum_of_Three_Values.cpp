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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        v.push_back({y, i});
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        int x1 = v[i].first;
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            int z = x1 + v[low].first + v[high].first;
            if (z > x)
            {
                high--;
            }
            else if (z < x)
            {
                low++;
            }
            else
            {
                vector<int> c;
                c.push_back(v[i].second);
                c.push_back(v[low].second);
                c.push_back(v[high].second);
                sort(all(c));
                for (auto &it : c)
                    cout << it + 1 << " ";
                cout << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}