#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5 + 10;
constexpr ll mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> oidx, eidx;
    vector<int> o, e;
    rep(i, 1, n)
    {
        if (a[i] & 1)
        {
            oidx.push_back(i);
            o.push_back(a[i]);
        }
        else
        {
            eidx.push_back(i);
            e.push_back(a[i]);
        }
    }
    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    int ct = 0;
    for (auto i : oidx)
    {
        a[i] = o[ct++];
    }
    ct = 0;
    for (auto i : eidx)
    {
        a[i] = e[ct++];
    }
    vector<int> b = a;
    sort(next(b.begin()), b.end());
    if (a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
