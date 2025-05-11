#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct arr
{
    int s;
    ll sum;
    int idx;
    vector<ll> a;
    arr() = default;
    arr(int n): a(n) {}
};
void solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<arr> t(n, arr(m));
    for(int i = 0; i < n; i++)
    {
        cin >> t[i].s;
        for(int j = 0; j < m; j++) cin >> t[i].a[j];
        ll sum = 0;
        for(int j = 0; j < m; j++) if(t[i].a[j] != -1) sum += t[i].a[j];
        t[i].sum = sum;
        t[i].idx = i;
    }
    sort(t.begin(), t.end(), [&](auto &x, auto &y){ return (x.s != y.s) ? (x.s < y.s) : (x.sum < y.sum); });
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            for(int j = 0; j < m; j++)
            {
                if(t[i].a[j] == -1) t[i].a[j] = 0;
            }
        }
        else if(t[i].s == t[i - 1].s)
        {
            ll minsum = max(t[i - 1].sum - t[i].sum, 0LL);
            for(int j = 0; j < m; j++)
            {
                if(t[i].a[j] == -1)
                {
                    ll minn = min(k, minsum);
                    minsum -= minn;
                    t[i].a[j] = minn;
                    t[i].sum += minn;
                }
            }
            if(t[i].sum < t[i - 1].sum)
            {
                cout << "No\n";
                return;
            }
        }
        else if(t[i].s > t[i - 1].s)
        {
            ll minsum = max(t[i - 1].sum + 1 - t[i].sum, 0LL);
            for(int j = 0; j < m; j++)
            {
                if(t[i].a[j] == -1)
                {
                    ll minn = min(k, minsum);
                    minsum -= minn;
                    t[i].a[j] = minn;
                    t[i].sum += minn;
                }
            }
            if(t[i].sum <= t[i - 1].sum)
            {
                cout << "No\n";
                return;
            }
        }
    }
    sort(t.begin(), t.end(), [&](auto &x, auto &y){ return x.idx < y.idx; });
    cout << "Yes\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cout << t[i].a[j] << " \n"[j == m - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}