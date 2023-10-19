#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define int long long int
#define lld long double
#define INF INT_MAX
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (auto &x : v)
        out << x << ' ';
    return out;
}
double PI = acos(-1);
int mulmod(int a, int b, int mod)
{
    int res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {

        if (b % 2 == 1)
            res = (res + a) % mod;

        a = (a * 2) % mod;

        b /= 2;
    }
    return res % mod;
}
void solve();
int sum_of_digit(int k)
{
    int s = 0;
    while (k > 0)
    {
        s += (k % 10);
        k /= 10;
    }
    return s;
}
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
    int arr[n];
    int maxM = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout << arr[i] << " ";
        maxM = max(maxM, arr[i]);
    }
    int k = maxM;
    // cout << maxM << endl;
    int c = 0;
    while (k > 0)
    {

        k /= 10;

        c++;
    }

    int g = pow(10, c);
    int x = g - maxM;
    for (int i = 0; i < n; i++)
    {
        s += sum_of_digit(arr[i] + x);
    }
    cout << s << endl;
}