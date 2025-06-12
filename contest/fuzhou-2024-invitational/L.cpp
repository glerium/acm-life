#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
using ll = long long;
#define endl '\n'
void solve()
{
    int n,t; cin >> n >> t;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    sort(a.begin() + 1, a.begin() + 1 + n, greater<>());
    vector<ll> s(n+5);
    rep(i,1,n) s[i] = s[i-1] + a[i];
    auto getsum = [&](int l, int r) -> ll {
        return s[r] - s[l-1];
    };
    rep(k,1,n) {
        ll ans = 0;
        for(int l=1,r=k; l<=n; l+=k,r+=k) {
            ans += max(0ll, getsum(l, min(r,n)) - t);
        }
        cout << ans << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    solve();
    return 0;
}