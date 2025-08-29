#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
void solve() {
    ll n,k; cin >> n >> k;
    while(cin) {
        ll ans = n * k;
        ll l = 1;
        while(l <= n) {
            ll d = k / l;
            if(!d) break;
            ll r = min(n, k / d);
            ans -= d * (l + r) * (r - l + 1) / 2;
            l = r + 1;
        }
        cout << ans << endl;
        cin >> n >> k;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}