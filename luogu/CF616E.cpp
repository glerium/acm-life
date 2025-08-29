#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
constexpr ll inf = 0x3f3f3f3f;
void solve() {
    ll x, y; cin >> y >> x;
    ll n=x, k=y;
    while(cin) {
        ll ans = n % mod * k % mod;
        ll l = 1;
        while(l <= n) {
            ll d = k / l;
            if(!d) break;
            ll r = min(n, k / d);
            ans -= d % mod * ((l + r) * (r - l + 1) / 2 % mod) % mod;
            l = r + 1;
        }
        ll anss = ans % mod;
        cout << anss << endl;
        cin >> y >> x;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}