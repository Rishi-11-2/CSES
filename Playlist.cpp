#include <algorithm>
#include <set>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    map<int, int> m;
    for (int i = 0, j = 0; i < n; i++)
    {
        j = max(m[arr[i]], j);
        ans = max(ans, i - j + 1);
        m[arr[i]] = i + 1;
    }
    cout << ans;
}