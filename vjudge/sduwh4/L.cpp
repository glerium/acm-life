#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(ll i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    ll l, r; cin >> l >> r;
    if(r - l > 2025) {
        cout << 0 << endl;
    } else {
        ll ans = 114514;
        rep(i,l,r) {
            rep(j,i+1,r) {
                ans = min(ans, i * j % 2019);
            }
        }
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
