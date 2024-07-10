#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return qpow(x, y-1)*x%mod;
    return qpow(x*x%mod, y/2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod-2) % mod;
}
ll jiec[10005];
ll C(ll x, ll y) {
    if(x < y) return 0;
    return jiec[x] % mod * frac(1, jiec[y] * jiec[x-y] % mod) % mod;
}
void solve() {
    int n, x; cin >> n >> x;
    int lim = sqrt(x);
    // ans = C(n, lim)  n! * lim! / (n-lim)!
    ll ans = 0;
    rep(i,1,lim) {
        ans += C(i-1, n-1);
        // cout << C(i-1,n-1) << endl;
        ans %= mod;
    }
    cout << ans << endl;
}
int main() {
    jiec[0] = 1;
    rep(i,1,1000) jiec[i] = jiec[i-1] * i % mod;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
