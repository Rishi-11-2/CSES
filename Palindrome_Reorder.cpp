#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    // cout << n << endl;
    vector<int> asc(26, 0);
    for (int i = 0; i < n; i++)
    {
        // cout << s[i] - 'A' << endl;
        asc[s[i] - 'A']++;
    }
    int c = 0;
    for (int i = 0; i < 26; i++)
    {
        if (asc[i] % 2 == 1)
            c++;
    }
    if (c > 1)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    string zf = "";
    string zr = "";
    string mid = "";
    for (int i = 0; i < 26; i++)
    {
        if (asc[i] % 2 == 0)
        {
            for (int k = 1; k <= (asc[i] / 2); k++)
            {
                cout << (char)('A' + i);
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (asc[i] % 2 == 1)
        {
            // cout << asc[i] << endl;
            for (int k = 1; k <= (asc[i]); k++)
            {
                cout << (char)('A' + i);
            }
        }
    }
    for (int i = 25; i >= 0; i--)
    {
        if (asc[i] % 2 == 0)
        {
            for (int k = 1; k <= (asc[i] / 2); k++)
            {
                cout << (char)('A' + i);
            }
        }
    }
    cout << endl;
}