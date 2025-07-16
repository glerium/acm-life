#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll l,r; cin >> l >> r;
    if(l == r) {
        if(l == 1) cout << "0" << endl;
        else cout << "infty" << endl;
        return;
    }
    ll first = l - 1, d = r - l;
    ll ct = first / d + 1;
    ll end = first - (ct - 1) * d;
    ll ans = (first + end) * ct / 2;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}