#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    long long s = 1;
    for (int i = 0; i < n && arr[i] <= s; i++)
    {
        s += arr[i];
        // cout << s << endl;
    }
    cout << s;
}