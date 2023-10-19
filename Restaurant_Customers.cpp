#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
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
    long long n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
    long long c = 1;
    long long res = 1;
    long long minm = 0;
    set<long long> s;
    s.insert(v[0].second);
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > *s.begin())
        {
            cout << *s.begin() << " " << c << endl;
            c--;
            s.erase(s.begin());
        }
        else if (v[i].first <= *s.begin())
        {
            c++;
            res = max(res, c);
            s.insert(v[i].second);
        }
    }
    res = max(res, c);
    cout << res << endl;
}