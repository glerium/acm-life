#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [&](auto x, auto y){ return (x % k) > (y % k); });
    ll m; cin >> m;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll t = ((a[i] % k) ? (k - (a[i] % k)) : (0));
        ll minn = min(m, t);
        m -= minn;
        a[i] += minn;
        ans += a[i] / k;
    }
    ans += m / k;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}