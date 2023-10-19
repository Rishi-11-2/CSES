#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define int long long int

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
    int n, k;
    cin >> n >> k;
    ordered_set v;
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        v.insert(i);
    }
    int pos = 0;
    while (v.size() > 1)
    {
        pos = (pos + k) % (int)(v.size());
        auto it = *(v.find_by_order(pos));
        res.push_back(it);
        v.erase(it);
        pos = pos % (int)(v.size());
    }
    res.push_back(*(v.find_by_order(0)));
    for (auto &it : res)
    {
        cout << it << " ";
    }
}