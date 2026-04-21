#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n+5), b(m+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(b.begin() + 1, b.begin() + 1 + m, greater<>());
    ll ans = 0;
    ll best = 0;
    auto tobest = [&]() -> void {
        best = max(best, ans);
    };
    rep(i,1,n)
        ans += abs(a[i] - b[m - n + i]);
    tobest();
    rep(i,1,n) {
        ans -= abs(a[i] - b[m - n + i]);
        ans += abs(a[i] - b[i]);
        // cerr << ans << endl;
        tobest();
    }
    cout << best << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}