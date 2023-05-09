#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
vector<int> res;
class Node
{
public:
    int data;
    vector<Node *> child;
    Node(int a = 0)
    {
        data = a;
    }
};
int count(Node *root)
{
    // cout << root->data << endl;
    if (root->child.size() == 0)
    {
        res[root->data] = 0;
        return 1;
    }
    int size = 0;
    for (auto it : root->child)
    {
        size += count(it);
    }
    // cout << size << endl;
    res[root->data] = size;
    return size + 1;
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
    int n;
    cin >> n;
    res.resize(n + 1);
    vector<Node *> q(n + 1);
    for (int i = 1; i <= n; i++)
    {
        Node *x = new Node(i);
        q[i] = x;
        // cout << q[i]->data << endl;
    }

    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        q[p]->child.push_back(q[i]);
    }
    // for (auto it : q[1]->child)
    //     cout << it->data << endl;
    int v = count(q[1]);
    // reverse(all(res));
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
}